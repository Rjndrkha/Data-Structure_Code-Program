package main
import "fmt"

func main() {
	var number,remainder,temp int
	var reverse int = 0

	fmt.Print("Enter any positive integer : ")
	fmt.Scan(&number)

	temp=number

	// For Loop used in format of While Loop
	for{
		remainder = number%10
		reverse = reverse*10 + remainder
		number /= 10

		if(number==0){
			break // Break Statement used to exit from loop
		}
	}

	if(temp==reverse){
		fmt.Printf("%d is a Palindrome",temp)
	}else{
		fmt.Printf("%d is not a Palindrome",temp)
	}

}
