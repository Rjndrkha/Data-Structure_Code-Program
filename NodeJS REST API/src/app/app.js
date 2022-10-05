const express = require("express");
const path = require("path");

const app = express();

const port = 3000;

//
var samp = require("../assets/samp");

const key = "PsaU6LUhoZMV";

module.exports = async (bot) => {
  app.use(express.json({ limit: "100mb" }));

  app.listen(port, () => {
    console.log(`App started on port ${port}`);
  });

  app.get("/api/sampquery", async (req, res) => {
    const ip = req.query.ip;
    if (!req.query.ip) {
      return res.json({
        response: "Error: There's no ip input",
      });
    }
    const p = req.query.port;
    if (!req.query.port) {
      return res.json({
        response: "Error: There's no port input",
      });
    }
    const gKey = req.query.key;
    if (!req.query.key) {
      return res.json({
        response: "Error: Please insert API Key",
      });
    }
    if (gKey !== key) {
      return res.json({
        response: "Error: Please insert a valid API Key",
      });
    }
    var options = {
      host: `${ip}`,
      port: `${p}`,
    };
    samp(options, function (error, response) {
      if (error) response = "Something Went Wrong Please Check ip And port correcly or Please Try Again Later";
      return res.json({
        response: response,
      });
    });
  });

  app.get("/api/fivemquery", async (req, res) => {
    const ip = req.query.ip;
    if (!req.query.ip) {
      return res.json({
        response: "Error: There's no ip input",
      });
    }
    const p = req.query.port;
    if (!req.query.port) {
      return res.json({
        response: "Error: There's no port input",
      });
    }

    const gKey = req.query.key;
    if (!req.query.key) {
      return res.json({
        response: "Error: Please insert API Key",
      });
    }
    if (gKey !== key) {
      return res.json({
        response: "Error: Please insert a valid API Key",
      });
    }

    const Fivemapi = require("../assets/fivem");

    const myIp = `http://${ip}:${p}`;
    const main = async () => {
      const fivemapi = new Fivemapi(myIp);

      fivemapi
        .getAllInfo()
        .then((i) => res.send(i))
        .catch();
    };

    main();
  });
};
