const cursor = document.getElementsByClassName('cursor');

window.addEventListener('mousemove',(e)=>{
    console.log("moving...",e.x,e.y,cursor)
    cursor.css({left:e.pageX,top:e.pageY})
})