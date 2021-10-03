//Code by ShreyaDayma-cse
import math as m
class calculator:    
    def inp(self):   
        self.a=int(input("Enter the first number:"))
        self.b=int(input("Enter the second number:"))
        print("The numbers are:",self.a," ",self.b) 
    def add(self):
        return self.a+self.b
    def diff(self):
        return self.a-self.b
    def mul(self):
        return self.a*self.b
    def div(self):
        return self.a/self.b
    def cosine(self):
          return( m.cos(self.a)), (m.cos(self.b))
    def sine(self):
          return( m.sin(self.a)), (m.sin(self.b))
    def square(self):
          return(m.sqrt(self.a)),(m.sqrt(self.b))
    def cube(self):
          return (self.a**(1/3)),(self.b**(1/3))
    
   
ob=calculator()
c=1
while c!=9: 
  print(''' Enter 1 for sum
         2 for Difference
         3 for Multiplication
         4 for Division
         5 for cosine
         6 for sine
         7 for square root 
         8 for cube root 
         9 to exit:''')    
  c=int(input("Enter the operation to be performed:"))
  if c==1:
      ob.inp()
      print("Sum=",ob.add(),"\n")
  elif c==2:
     ob.inp()
     print("Difference=",ob.diff(),"\n")
  elif c==3:
     ob.inp()
     print("Multiplication=",ob.mul(),"\n")
  elif c==4:
     ob.inp()
     print("Division=",ob.div(),"\n")
  elif c==5:
     ob.inp()
     print("Cosine values=",ob.cosine(),"\n")
  elif c==6:
     ob.inp()
     print("Sine values=",ob.sine(),"\n")
  elif c==7:
     ob.inp()
     print("Square roots=",ob.square(),"\n")
  elif c==8:
     ob.inp()
     print("Cube roots=",ob.cube(),"\n")
  else:
      print("Invalid")
    
