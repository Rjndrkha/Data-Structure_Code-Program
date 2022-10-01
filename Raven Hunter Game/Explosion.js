const canvasCtx = document.getElementById('canvas').getContext('2d');

class Explosion{
    constructor(x,y){
        this.x=x;
        this.y=y;
        this.spriteWidth = 200;
        this.spriteHeight = 179;
        this.width= this.spriteWidth*0.7;
        this.height= this.spriteHeight*0.7;
        this.frame=0;
        this.slower=0;
        this.image = new Image();
        this.image.src="boom.png"
    }

    update(){
        this.slower++;
        if(this.slower%2==0){
            if(this.frame<5) this.frame++
            else this.frame=0;
        }
    }

    draw(){
        canvasCtx.drawImage(this.image,this.frame*this.spriteWidth,0,this.spriteWidth,this.spriteHeight,this.x,this.y,this.width,this.height);
    }
}

export default Explosion;