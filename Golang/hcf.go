package main

// fmt package provides the function to print anything
import "fmt"
func main() {
   
   // declaring the variables to store n1, n2
   // and i of type int32 using var keyword
   var n1, n2, i int32
   fmt.Println("Program to find the Highest Common Factor within the function.")
   
   // initializing the variable n1
   n1 = 24
   
   // initializing the variable n1
   n2 = 60
   
   // checking for all the if else conditional statements to find highest common factor of the two numbers
   
   // and then storing that number in i variable
   if n1 == 0 || n2 == 0 {
      fmt.Print("The Highest Common Factor is 0")
   } else if n1 > n2 {
      i = n1 % n2
      fmt.Print("The Highest Common Factor is ", i)
   } else if n2 > n1 {
      i = n2 % n1
      
      // printing the results
      fmt.Printf("The Highest Common Factor of %d and %d is %d", n1, n2, i)
   } else {
      fmt.Print("Invalid input")
   }
}
