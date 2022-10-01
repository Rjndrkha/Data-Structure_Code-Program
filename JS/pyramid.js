function starPyramid(x) {
  for(let i=1; i<= x; i++){
    let fill1 = ' '.repeat(x-i);
    let fill2 = '*'. repeat(i*2 -1)

    console.log(fill1 + fill2 + fill1);
  }

}

starPyramid(5);
