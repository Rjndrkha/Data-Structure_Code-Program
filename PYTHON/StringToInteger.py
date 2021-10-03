def stringToInt(str): 
 
    if (len(str) == 1): 
        return ord(str[0]) - ord('0')
  
    y = stringToInt(str[1:])
  
    x = ord(str[0]) - ord('0')
      
    x = x * (10**(len(str) - 1)) + y
    return int(x)
  

str = input()
print(stringToInt(str))



# Input format :
# Numeric string S (string, Eg. "1234")
# Output format :
# Corresponding integer N (int, Eg. 1234)
# Constraints :
# 0 <= |S| <= 9
# where |S| represents length of string S.
# Sample Input 1 :
# 00001231
# Sample Output 1 :
# 1231
# Sample Input 2 :
# 12567
# Sample Output 2 :
# 12567
