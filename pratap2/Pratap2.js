
var btnNumber = document.querySelectorAll(".btn1").length;
for (var i = 0; i < btnNumber; i++) {
  document.querySelectorAll("button")[i].addEventListener("click", function () {
      var move=this.innerHTML;
      play(move);
      });
}


function play(move){
  var randomNumber1 = Math.floor((Math.random()*6)) +1;
  var randomImg1="dice"+randomNumber1+".png";
  document.getElementById("myImg1").src = "images/"+randomImg1;

  var randomNumber2 = Math.floor((Math.random()*6)) +1;
  var randomImg2="dice"+randomNumber2+".png";
  document.getElementById("myImg2").src = "images/"+randomImg2;

    if((randomNumber1 + randomNumber2 >= 7 && move=="7 Up") || (randomNumber1 + randomNumber2 < 7 && move=="7 Down")){

    document.querySelector("h1").innerHTML="Won!!";
  }
  else{
    document.querySelector("h1").innerHTML="Lose!!";
  }
}