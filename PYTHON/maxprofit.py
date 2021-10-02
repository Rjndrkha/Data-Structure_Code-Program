liStocks = [100, 180, 260, 310, 40, 535, 695]
  
#find local minima
def findMin(liStocks):
    for i, val in enumerate(liStocks[:-1]):
        if val < liStocks[i+1]: 
            return i, val 
    return -1, -1
  
#find local maxima 
def findMax(liStocks): 
    for i, val in enumerate(liStocks[:-1]): 
        if val > liStocks[i+1]:
            return i, val
    return i+1, liStocks[-1]
  
  
  
def buySellStock():
    index=0
    while index < len(liStocks): 
        i, val = findMin(liStocks[index:]) 
        if i > -1:
            index=i+index
            print("bye stock on day ", index+1, val)
        else:
            break
      
        i, val = findMax(liStocks[index:])
        index=i+index
        print("sell stock on day ", index+1, val)
  
  
if __name__ == "__main__":
    buySellStock()
