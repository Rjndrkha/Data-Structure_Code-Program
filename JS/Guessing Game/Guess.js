let max = parseInt(prompt("Hey, enter your maximum number"));
let attempts = 1;

while (!max){
    guess = parseInt(prompt("Hey, please enter valid number"));
}

const targetnum = (Math.floor(Math.random*max))+1;
console.log(targetnum);


let guess = parseInt(prompt("Enter your first guess!"));


while (parseInt(guess) !== targetnum){

    if (guess === 'q' )
    break;
    attempts++;
   if(guess > targetnum){
    guess = prompt("Too high! Enter a new guess:");
   }

   else if (guess<targetnum) {
    guess = prompt("Too low! Enter a new guess:");
   }

}

if(guess==='q'){
    console.log("You quit!");
}
else{
    console.log(`Congatulations! You got it! It took you ${attempts} guesses`);
}