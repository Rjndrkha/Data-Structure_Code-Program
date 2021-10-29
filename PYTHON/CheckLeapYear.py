------------------------------------------------------------------------------------------------
DESCRIPTION: THIS IS A PROGRAM TO CHECK IF THE INPUT YEAR IS LEAP OR NOT
------------------------------------------------------------------------------------------------
##

# Program to find if the input year is Leap or not
year = int(input("Enter Year: "))

# Leap Year Check
if year % 4 == 0 and year % 100 != 0:
    print(year, "is a Leap Year")
elif year % 100 == 0:
    print(year, "is not a Leap Year")
elif year % 400 ==0:
    print(year, "is a Leap Year")
else:
    print(year, "is not a Leap Year")
