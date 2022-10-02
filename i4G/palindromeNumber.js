var isPalindrome = function(x) {
    //convert x to string
    x2 = x.toString();
    //Reverse X2
    x2 = x2.split('').reverse().join('')

    //Convert x3 to integer
    x2 = parseInt(x2);

    //Return the result of comparing x and x2
    return x == x2;

};
