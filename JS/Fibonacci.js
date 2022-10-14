function sumOfFibonacci() {
    // Create an array and store '0' as the first value
    let fibonacci = [0];
    //  Let '1' be the next term
    let a = 1;

    for (let i = 1; ; i++) {        
        //  The value b Would always be the last value of the array
        b = fibonacci[fibonacci.length - 1];
        fibonacci.push(a + b)
        //  The value a Would always be the last value before b in the array
        a = fibonacci[fibonacci.length - 2]
        // Check to make sure the < 4,000,000 condition is met
        if (a+b > 4000000) break
    }

    let x = 0;

    for (i in fibonacci) {
        //  Finding even terms by checking the terms divisible by 2
        if ((fibonacci[i] % 2) === 0) {
            // Summing the terms
            x += fibonacci[i]
        }
    }

    console.log("The sum of all even values less than 4,000,000 in the fibonacci sequence is:", x)
}
