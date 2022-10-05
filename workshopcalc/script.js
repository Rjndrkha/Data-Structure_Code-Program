var add = document.getElementById("plus");
var sub = document.getElementById("minus");
var mul = document.getElementById("into");
var div = document.getElementById("divide");
var eq = document.getElementById('equal');
//input tag text
var input = document.getElementById("input");
//numbers
var btn = document.getElementsByTagName("button");
var nine = document.getElementById("nine");
var eight = document.getElementById("eight");
var seven = document.getElementById("seven");
var six = document.getElementById("six");
var five = document.getElementById("five");
var four = document.getElementById("four");
var three = document.getElementById("three");
var two = document.getElementById("two");
var one = document.getElementById("one");
var zero = document.getElementById("zero");
// length 
var len = input.innerText.length;

var calc,temp = 0;
calc = 0;

//nine to include in the input
nine.onclick = function() {
    input.innerText += String(nine.innerHTML);
    len = input.innerText.length;
}
//eight to include in the input
eight.onclick = function() {
    input.innerText += String(eight.innerHTML);
    len = input.innerText.length;
}
//seven to include in the input
seven.onclick = function() {
    input.innerText += String(seven.innerHTML);
    len = input.innerText.length;
}
//six to include in the input
six.onclick = function() {
    input.innerText += String(six.innerHTML);
    len = input.innerText.length;
}
//five to include in the input
five.onclick = function() {
    input.innerText += String(five.innerHTML);
    len = input.innerText.length;
}
//four to include in the input
four.onclick = function() {
    input.innerText += String(four.innerHTML);
}
//three to include in the input
three.onclick = function() {
    input.innerText += String(three.innerHTML);
    len = input.innerText.length;
}
//two to include in the input
two.onclick = function() {
    input.innerText += String(two.innerHTML);
    len = input.innerText.length;
}
//one to include in the input
one.onclick = function() {
    input.innerText += String(one.innerHTML);
    len = input.innerText.length;
}
//zero to include in the input
zero.onclick = function() {
    input.innerText += String(zero.innerHTML);
    len = input.innerText.length;
}

var len = input.innerText.length;


    //plus to include in the input
add.onclick = function() {
    if(input.innerText !== "" && input.innerText[len-1] != "/" && input.innerText[len-1]!= "*" && input.innerText[len-1]!= "-" && input.innerText[len-1]!= "+" ){
        input.innerText += "+";
        len = input.innerText.length;
    }
}
//sub to include in the input
sub.onclick = function() {
    if(input.innerText !== "" &&input.innerText[len-1] != "/" && input.innerText[len-1]!= "*" && input.innerText[len-1]!= "-" && input.innerText[len-1]!= "+"  ){
        input.innerText += "-";
        len = input.innerText.length;
    }

}
//mul to include in the input
mul.onclick = function() {
    if(input.innerText !== "" && input.innerText[len-1] != "/" && input.innerText[len-1]!= "*" && input.innerText[len-1]!= "-" && input.innerText[len-1]!= "+" ){
        input.innerText += "*";
        len = input.innerText.length;
    }
}
//div to include in the input
div.onclick = function() {
    if(input.innerText !== "" && input.innerText[len-1] != "/" && input.innerText[len-1]!= "*" && input.innerText[len-1]!= "-" && input.innerText[len-1]!= "+" ){
        input.innerText += "/";
        len = input.innerText.length;
    }
}
var leng;

eq.onclick = function() {
    leng = input.innerText.length;
    for(var i=0; i<leng;i++) {
        if(temp[temp.length-1] == '+'){
            calc = Number(temp.slice(0,temp.length-1)) + Number(input.innerText.slice(i,leng));
            //console.log(temp.slice(0,temp.length-1))
            temp = '';
            input.innerText = String(calc);
            //console.log(temp.slice(0,temp.length-1))
            break;
        }
        if(temp[temp.length-1] == '-'){
            calc = Number(temp.slice(0,temp.length-1)) - Number(input.innerText.slice(i,leng));
            //console.log(temp.slice(0,temp.length-1))
            temp = '';
            input.innerText = String(calc);
            //console.log(temp.slice(0,temp.length-1))
            break;
        }
        if(temp[temp.length-1] == '*'){
            calc = Number(temp.slice(0,temp.length-1)) * Number(input.innerText.slice(i,leng));
            //console.log(temp.slice(0,temp.length-1))
            temp = '';
            input.innerText = String(calc);
            //console.log(temp.slice(0,temp.length-1))
            break;
        }
        if(temp[temp.length-1] == '/'){
            calc = Number(temp.slice(0,temp.length-1)) / Number(input.innerText.slice(i,leng));
            //console.log(temp.slice(0,temp.length-1))
            temp = '';
            input.innerText = String(calc);
            //console.log(temp.slice(0,temp.length-1))
            break;
        }
        temp=temp+input.innerText[i];
    }
}

// to reset
var res = document.getElementById('reset');
res.onclick = function() {
    input.innerText = "";
}