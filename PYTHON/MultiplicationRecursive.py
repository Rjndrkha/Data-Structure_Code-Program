def product( x , y ): 
    # if x is less than y swap 
    # the numbers 
    if x < y: 
        return product(y, x) 
      
    # iteratively calculate y 
    # times sum of x 
    elif y != 0: 
        return (x + product(x, y - 1)) 
      
    # if any of the two numbers is 
    # zero return zero 
    else: 
        return 0
  
# Driver code 
x = int(input())
y = int(input())
print( product(x, y))
