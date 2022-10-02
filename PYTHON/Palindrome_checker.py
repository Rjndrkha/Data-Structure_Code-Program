# Program to check if an integer is a palindrome(same when read forwards or backwards) or not.

def ispal(x):
    if x>0:
        return str(x)==str(x)[::-1]  # We stoer the integer as a string and then reverse the string to check if they are equal
    if x<0:
        x=x*(-1)                     # When x is negative, if we store x in string the negative sign will also be stored and when the string is being reversed the negative sign will go to the back of the number hence resulting in false answers.
        return str(x)==str(x)[::-1]



