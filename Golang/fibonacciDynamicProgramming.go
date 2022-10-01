//program fibonacci number with dynamic programming
package main

import (
	"fmt"
)

func fibonacciDynamicProgramming(n int) int{
  f := make([]int, n+2)

  f[0] = 0
  f[1] = 1

  if n == 0 || n == 1{
    return f[n]
  }
  
  for i := 2; i < n; i++{
    f[i] = f[i-1] + f[i-2]
  }

  return f[n] + f[n-1]
}

func main(){
	fmt.Println(fibonacciDynamicProgramming(15))
}
