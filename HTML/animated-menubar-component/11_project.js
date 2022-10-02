let navdots = document.querySelector('.navdots');
navdots.onclick = function () {
    navdots.classList.toggle('expand');
}
// calculator
const pop = document.querySelector('.calculator-page');
function toggcalculator() {
    pop.classList.toggle('hide');
}
// clock
const pop1 = document.querySelector('.clock-page');
function toggclock() {
    pop1.classList.toggle('hide1');
}
// camera
const pop2 = document.querySelector('.camera-page');
function toggcamera() {
    pop2.classList.toggle('hide2');
}
// bgcolorchanger
const pop3 = document.querySelector('.bgcolorchange-page');
function toggbgchanger() {
    pop3.classList.toggle('hide3');
}
// formvalidation
const pop4 = document.querySelector('.formvalidation-page');
function toggform() {
    pop4.classList.toggle('hide4');
}
// voice recorder
const pop5 = document.querySelector('.voicerecord-page');
function toggvoicerecorder() {
    pop5.classList.toggle('hide5');
}
// youtube
const pop6 = document.querySelector('.youtube-page');
function toggyoutube() {
    pop6.classList.toggle('hide6');
}
// twitter
const pop7 = document.querySelector('.twitter-page');
function toggtwitter() {
    pop7.classList.toggle('hide7');
}
// instagram
const pop8 = document.querySelector('.instagram-page');
function togginstagram() {
    pop8.classList.toggle('hide8');
}
// calculator function
var screen = document.querySelector('#screen');
var btn = document.querySelectorAll('.btn');

for (item of btn) {
    item.addEventListener('click', (e) => {
        btntext = e.target.innerText;
        if (btntext == 'x') {
            btntext = '*';
        }
        if (btntext == '÷') {
            btntext = '/';
        }
        if (btntext == '+') {
            btntext = '+';
        }
        screen.value += btntext;
    });
}
function sin() {
    screen.value = Math.sin(screen.value);
}
function sine(degree) {
    screen.value = Math.sin(degree);
}
function cos(degree) {
    screen.value = Math.cos(degree);
}
function tan(degree) {
    screen.value = Math.tan(degree);
}
function pow() {
    screen.value = Math.pow(screen.value, 2);
}
function sqrt() {
    screen.value = Math.sqrt(screen.value, 2);
}
function log(degree) {
    screen.value = Math.log(degree);
}
function pi() {
    screen.value = 3.14159265359;
}
function e() {
    screen.value = 2.71828182846;
}
function fact() {
    var i, num, f;
    f = 1
    num = screen.value;
    for (i = 1; i <= num; i++) {
        f = f * i;
    }
    i = i - 1;
    screen.value = f;
}
function backsp() {
    screen.value = screen.value.substr(0, screen.value.length - 1);
}
var microphone = document.getElementById('mic');
microphone.onclick = function () {
    microphone.classList.add("record");
    var recognition = new (window.SpeechRecognition || window.webkitSpeechRecognition || window.mozSpeechRecognition || window.msSpeechRecognition)();
    recognition.lang = 'en-US';
    recognition.start();
    operations = {
        "plus": "+", "minus": "-", "multiply": "*", "multiplied": "*", "divide": "/", "divided": "/", "reminder": "%"
    }
    recognition.onresult = function (event) {
        var input = event.results[0][0].transcript;
        for (property in operations) {
            input = input.replace(property, operations[property])

        }
        const inputs = input.split(" ");
        screen.value += input;
        document.getElementById("screen").innerText = screen.value;
        if (inputs[0] == "sin") {
            setTimeout(function () {
                sine(inputs[1]);
            }, 2000);
            microphone.classList.remove("record");
        }
        else {

            setTimeout(function () {
                evaluate(input);
            }, 2000);
            microphone.classList.remove("record");
        }
        if (inputs[0] == "cos") {
            setTimeout(function () {
                cos(inputs[1]);
            }, 2000);
            microphone.classList.remove("record");
        }
        else {

            setTimeout(function () {
                evaluate(input);
            }, 2000);
            microphone.classList.remove("record");
        }
        if (inputs[0] == "tan") {
            setTimeout(function () {
                tan(inputs[1]);
            }, 2000);
            microphone.classList.remove("record");
        }
        else {

            setTimeout(function () {
                evaluate(input);
            }, 2000);
            microphone.classList.remove("record");
        }
        if (inputs[0] == "radian") {
            setTimeout(function () {
                pi(inputs[1]);
            }, 2000);
            microphone.classList.remove("record");
        }
        else {

            setTimeout(function () {
                evaluate(input);
            }, 2000);
            microphone.classList.remove("record");
        }
        if (inputs[0] == "antilog") {
            setTimeout(function () {
                e(inputs[1]);
            }, 2000);
            microphone.classList.remove("record");
        }
        else {

            setTimeout(function () {
                evaluate(input);
            }, 2000);
            microphone.classList.remove("record");
        }
        if (inputs[0] == "log") {
            setTimeout(function () {
                log(inputs[1]);
            }, 2000);
            microphone.classList.remove("record");
        }
        else {

            setTimeout(function () {
                evaluate(input);
            }, 2000);
            microphone.classList.remove("record");
        }
    }
}
function evaluate(input) {
    try {
        var result = eval(input);
        screen.value = result;
    }
    catch (e) {
        console.log(e);
    }
}
// bgcolor changer
function getNewColor() {
    var symbols, color;
    symbols = "0123456789ABCDEF";
    colorString = "#";
    for (var i = 0; i < 6; i++) {
        colorString = colorString + symbols[Math.floor(Math.random() * 16)];
    }
    document.getElementById('flip').style.background = colorString;
    document.getElementById('color').innerHTML = colorString;
}
// form validation
function validation() {
    var user = document.getElementById('user').value;
    var pass = document.getElementById('pass').value;
    var confirmpass = document.getElementById('conpass').value;
    var emails = document.getElementById('emails').value;
    document.getElementById('emails').value;
    if (user == "") {
        document.getElementById('username').innerHTML = "** Please fill the username field";
        return false;
    }
    if (!isNaN(user)) {
        document.getElementById('username').innerHTML = "** only characters are allowed";
        return false;
    }

    if (pass == "") {
        document.getElementById('passwords').innerHTML = "** Please fill the password field";
        return false;
    }
    if ((pass.length <= 5) || (pass.length > 20)) {
        document.getElementById('passwords').innerHTML = "** password lenght must be between 5 and 20";
        return false;
    }

    if (confirmpass == "") {
        document.getElementById('confrmpass').innerHTML = "** Please confirm you password";
        return false;
    }
    if (pass != confirmpass) {
        document.getElementById('confrmpass').innerHTML = "** password is not matching";
        return false;
    }

    if (emails == "") {
        document.getElementById('emailids').innerHTML = "** Please fill the email field";
        return false;
    }
    if (emails.index0f('@') <= 0) {
        document.getElementById('emailids').innerHTML = "** @ Invalid Position";
        return false;
    }
    if ((emails.charAt(emails.length - 4) != '.') && (emails.charAt(emails.length - 3) != '.')) {
        document.getElementById('emailids').innerHTML = "** . Invalid Position";
        return false;
    }
}
// mic
var device = navigator.mediaDevices.getUserMedia({ audio: true });
var items = [];
device.then(stream => {
    var recorder = new MediaRecorder(stream);
    recorder.ondataavailable = e => {
        items.push(e.data);
        if (recorder.state == 'inactive') {
            var blob = new Blob(items, { type: 'audio/webm' });
            var audio = document.getElementById('audio');
            var mainaudio = document.createElement('audio');
            mainaudio.setAttribute('controls', 'controls');
            audio.appendChild(mainaudio);
            mainaudio.innerHTML = '<source src="' + URL.createObjectURL(blob) + '" type = "video/webm" /> ';
            mainaudio.style.marginTop = "20vh";
            mainaudio.style.marginLeft = "10vw";
        }
    }
    recorder.start(100);
    setTimeout(() => {
        recorder.stop();
    }, 5000);
})
// clock
const deg = 6;
const hr = document.querySelector('#hr');
const mn = document.querySelector('#mn');
const sc = document.querySelector('#sc');

setInterval(() => {
    let day = new Date();
    let hh = day.getHours() * 30;
    let mm = day.getMinutes() * deg;
    let ss = day.getSeconds() * deg;
    hr.style.transform = "rotateZ(${(hh)+(mm/12)}deg)";
    mn.style.transform = "rotateZ(${mm}deg)";
    sc.style.transform = "rotateZ(${ss}deg)";
})