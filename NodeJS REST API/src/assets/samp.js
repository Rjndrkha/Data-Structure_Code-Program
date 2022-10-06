var dgram = require("dgram");

var samp = function (options, callback) {
  var self = this;

  if (typeof options === "string") options.host = options;
  options.port = options.port || 7777;
  options.timeout = options.timeout || 1000;

  if (!options.host) return callback.apply(options, ["Invalid host"]);

  if (!isFinite(options.port) || options.port < 1 || options.port > 65535) return callback.apply(options, ["Invalid port"]);

  var response = {};

  request.call(self, options, "i", function (error, information) {
    if (error) return callback.apply(options, [error]);

    response.address = options.host;
    response.hostname = information.hostname;
    response.gamemode = information.gamemode;
    response.language = information.language;
    response.passworded = information.passworded === 1;
    response.maxplayers = information.maxplayers;
    response.online = information.players;

    request.call(self, options, "r", function (error, rules) {
      if (error) return callback.apply(options, [error]);

      rules.lagcomp = rules.lagcomp === "On";

      rules.weather = parseInt(rules.weather, 10);

      response.rules = rules;

      if (response.online > 100) {
        response.players = [];

        return callback.apply(options, [false, response]);
      } else {
        request.call(self, options, "d", function (error, players) {
          if (error) return callback.apply(options, [error]);

          response.players = players.toString();

          return callback.apply(options, [false, response]);
        });
      }
    });
  });
};

var request = function (options, opcode, callback) {
  var socket = dgram.createSocket("udp4");
  var packet = new Buffer(10 + opcode.length);

  packet.write("SAMP");

  for (var i = 0; i < 4; ++i) packet[i + 4] = options.host.split(".")[i];

  packet[8] = options.port & 0xff;
  packet[9] = (options.port >> 8) & 0xff;
  packet[10] = opcode.charCodeAt(0);

  try {
    socket.send(packet, 0, packet.length, options.port, options.host, function (error, bytes) {
      if (error) return callback.apply(options, [error]);
    });
  } catch (error) {
    return callback.apply(options, [error]);
  }

  var controller = undefined;

  var onTimeOut = function () {
    socket.close();
    return callback.apply(options, ["Host unavailable"]);
  };

  controller = setTimeout(onTimeOut, options.timeout);

  socket.on("message", function (message) {
    if (controller) clearTimeout(controller);

    if (message.length < 11) return callback.apply(options, [true]);
    else {
      socket.close();

      message = message.slice(11);

      var object = {};
      var array = [];
      var strlen = 0;
      var offset = 0;

      try {
        if (opcode == "i") {
          object.passworded = message.readUInt8(offset);
          offset += 1;

          object.players = message.readUInt16LE(offset);
          offset += 2;

          object.maxplayers = message.readUInt16LE(offset);
          offset += 2;

          strlen = message.readUInt16LE(offset);
          offset += 4;

          object.hostname = decode(message.slice(offset, (offset += strlen)));

          strlen = message.readUInt16LE(offset);
          offset += 4;

          object.gamemode = decode(message.slice(offset, (offset += strlen)));

          strlen = message.readUInt16LE(offset);
          offset += 4;

          object.mapname = decode(message.slice(offset, (offset += strlen)));

          return callback.apply(options, [false, object]);
        }

        if (opcode == "r") {
          var rulecount = message.readUInt16LE(offset);
          offset += 2;

          var property,
            value = undefined;

          while (rulecount) {
            strlen = message.readUInt8(offset);
            ++offset;

            property = decode(message.slice(offset, (offset += strlen)));

            strlen = message.readUInt8(offset);
            ++offset;

            value = decode(message.slice(offset, (offset += strlen)));

            object[property] = value;

            --rulecount;
          }

          return callback.apply(options, [false, object]);
        }

        if (opcode == "d") {
          var playercount = message.readUInt16LE(offset);
          offset += 2;

          var player = undefined;

          while (playercount) {
            // player = {}

            const id = message.readUInt8(offset);
            ++offset;

            strlen = message.readUInt8(offset);
            ++offset;

            const name = decode(message.slice(offset, (offset += strlen)));

            const score = message.readUInt16LE(offset);
            offset += 4;

            const ping = message.readUInt16LE(offset);
            offset += 4;

            player = id + " " + name + "   " + score + "  " + ping + "  " + "\n";

            array.push(player);

            --playercount;
          }

          return callback.apply(options, [false, array]);
        }
      } catch (exception) {
        return callback.apply(options, [exception]);
      }
    }
  });
};

var decode = function (buffer) {
  var charset = "";
  for (var i = 0; i < 128; i++) charset += String.fromCharCode(i);
  charset += "€�‚ƒ„…†‡�‰�‹�����‘’“”•–—�™�›���� ΅Ά£¤¥¦§¨©�«¬­®―°±²³΄µ¶·ΈΉΊ»Ό½ΎΏΐΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡ�ΣΤΥΦΧΨΩΪΫάέήίΰαβγδεζηθικλμνξοπρςστυφχψωϊϋόύώ�";
  var charsetBuffer = new Buffer(charset, "ucs2");
  var decodeBuffer = new Buffer(buffer.length * 2);
  for (var i = 0; i < buffer.length; i++) {
    decodeBuffer[i * 2] = charsetBuffer[buffer[i] * 2];
    decodeBuffer[i * 2 + 1] = charsetBuffer[buffer[i] * 2 + 1];
  }
  return decodeBuffer.toString("ucs2");
};

module.exports = samp;
