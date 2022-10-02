// import Explosion from "./Explosion";
const scoreSpan = document.getElementById("score-span");
const gameOverDiv = document.querySelector(".game-over-div");
const canvas = document.getElementById('canvas');
const canvasCtx = canvas.getContext('2d');
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
let canvasOffset = canvas.getBoundingClientRect();
level=localStorage.getItem('game-level') || 'easy';

const mysteryMusic = new Audio();
mysteryMusic.src="mystery-music.mp3";
mysteryMusic.play()
const ravenImage = new Image();
ravenImage.src = "./raven.png";
const ravenArr = [];
let noOfRavens = 10;
let gameOver = false;
let score = 0;
let speedFactor = 6;
if(level=='medium') speedFactor = 9;
else if(level=='hard') speedFactor=12;
document.querySelector('.level-display').innerText=level;
scoreSpan.innerText = 0;
document.querySelector(".highest-score").innerText =
localStorage.getItem("raven-game-highest-score") || 0;

class Raven {
    constructor(){
        this.spriteWidth = 271;
        this.spriteHeight = 194;
        let sizeFactor = 0.5;
        this.width=this.spriteWidth*sizeFactor;
        this.height = this.spriteHeight*sizeFactor;
        this.slower = 0;
        this.frame=0;
        this.speed = speedFactor*Math.random();
        if(this.speed<2) this.speed+=2;
        this.x = canvas.width;
        this.y = Math.random()*canvas.height;
        if(this.y>=this.spriteHeight){
            this.y -= this.spriteHeight / 2; 
        }
    }

    update(){
        this.slower++;
        this.x-=this.speed;
        if(this.slower%2==0){
            if (this.frame < 5) this.frame++;
            else this.frame = 0;
        }
        if(this.x<0){
            // Gameover
            gameOver=true;
            gameOverDiv.classList.remove("invisible");
            ravenArr.splice(0,ravenArr.length);
            noOfRavens=0;
        }
    }

    draw(){
        canvasCtx.drawImage(ravenImage,this.spriteWidth*this.frame,0,271,194,this.x,this.y,this.width,this.height);
    }
}

let lastTime = 0;
let timeToNextRaven = 0;
let ravenInterval =700;
function animate(timestamp){
    canvasCtx.clearRect(0,0,canvas.width,canvas.height);
    
    let deltaTime = timestamp-lastTime;
    lastTime=timestamp;
    timeToNextRaven +=deltaTime;
    if(timeToNextRaven>ravenInterval){
        ravenArr.push(new Raven());
        timeToNextRaven=0;
    }

    ravenArr.forEach(el=>{
        el.update();
        el.draw();
    })
    if(!gameOver) requestAnimationFrame(animate)
}

// explosions
function isCollision(clickX,clickY){
    ravenArr.forEach((raven,index)=>{
        if(clickX>raven.x && clickX<raven.x+raven.width
            && clickY>raven.y && clickY<raven.y+raven.height){
                ravenArr.splice(index,1);
                explosions.push(new Explosion(clickX,clickY));
                score++;
                scoreSpan.innerText= score;
            }
    })
}

class Explosion {
  constructor(x, y) {
    this.spriteWidth = 200;
    this.spriteHeight = 179;
    this.width = this.spriteWidth * 0.6;
    this.height = this.spriteHeight * 0.6;
    this.x = x-this.width/2;
    this.y = y-this.height/2;
    this.frame = 0;
    this.slower = 0;
    this.image = new Image();
    this.image.src = "boom.png";
    this.sound = new Audio();
    this.sound.src = "boom.wav"
  }

  update() {
    if(this.frame==0) this.sound.play()
    this.slower++;
    if (this.slower % 5 == 0) {
      if (this.frame < 5) this.frame++;
      else this.frame = 0;
    }
  }

  draw() {
    canvasCtx.drawImage(
      this.image,
      this.frame * this.spriteWidth,
      0,
      this.spriteWidth,
      this.spriteHeight,
      this.x,
      this.y,
      this.width,
      this.height
    );
  }
}

let explosions = [];

window.addEventListener('click',(e)=>{
    isCollision(e.x-canvasOffset.left,e.y-canvasOffset.top)
})


function animateExplosion(){
    
    explosions.forEach((el,index)=>{
        el.update();
        el.draw();
        if(el.frame>4){
            explosions.splice(index,1);
        }
    })
    requestAnimationFrame(animateExplosion);
}

function startGame(){
    if(gameOver) return;
    score = 0;
    animate(0);
    animateExplosion();
}

startGame();



// retry btn clicked
document.querySelector('.retry-btn').addEventListener('click',()=>{
  let btnSound = new Audio();
  btnSound.src="btnclick.ogg";
  btnSound.play()
  if (score > localStorage.getItem("raven-game-highest-score")){
    localStorage.setItem("raven-game-highest-score", score);
  }
  location.reload()
})

document.getElementById('restart-btn').addEventListener('click',()=>{
    location.reload();
})

window.addEventListener('keydown',(e)=>{
    if(e.keyCode === 27){
        console.log(27)
        document.querySelector('.level-selector-div').style.display='flex'
    }
})

document.getElementById('level').addEventListener('change',(e)=>{
    console.log(e.target.value);
    localStorage.setItem('game-level',e.target.value);
})