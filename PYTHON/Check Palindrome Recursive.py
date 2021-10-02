def isPalRec(st, s, e) : 
      
    # If there is only one character 
    if (s == e): 
        return True 
    if (st[s] != st[e]) : 
        return False
    if (s < e + 1) : 
        return isPalRec(st, s + 1, e - 1); 
  
    return True
  
def isPalindrome(st) : 
    n = len(st) 
      
    if (n == 0) : 
        return True
      
    return isPalRec(st, 0, n - 1); 
  
  
st = input()
if (isPalindrome(st)) : 
    print ('true')
else:
    print ('false')
