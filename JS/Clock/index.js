setInterval(setClock, 1000);

const _hourHand = document.querySelector("[data-hour-hand]");
const _minuteHand = document.querySelector("[data-minute-hand]");
const _secondHand = document.querySelector("[data-second-hand]");

function setClock() {
  const currentDate = new Date();
  const secondsRatio = currentDate.getSeconds() / 60;
  const minutesRatio = (secondsRatio + currentDate.getMinutes()) / 60;
  const hrRatio = (minutesRatio + currentDate.getHours()) / 12;
  setRotation(_secondHand, secondsRatio);
  setRotation(_minuteHand, minutesRatio);
  setRotation(_hourHand, hrRatio);
}

function setRotation(element, rotationRatio) {
  element.style.setProperty("--rotation", rotationRatio * 360);
}

setClock();