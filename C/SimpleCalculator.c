#include <stdio.h>

int main(void) {
  //varible declaration
  char method;
  float num1,num2,result;
  //geting method from user 
  printf("Input the oprator (+ , - , / , *)  : ");
  scanf("%c",&method);
  //checking user entered method 
  if(method=='+'||method=='-'||method=='/'||method=='*'){
  //get the num1 d=from user 
    printf("Enter the 1st number : ");
    scanf("%f",&num1);
    //get the num2 from user 
    printf("Enter the 2nd number : ");
    scanf("%f",&num2);
    //addition
    if(method=='+'){
      result=num1+num2;
    }
    //substraction
    else if(method=='-'){
      result=num1+num2;
    }
      //devision
      else if(method=='/'){
      result=num1/num2;
    }
    //mutplication
    else{
      result=num1*num2;
    }
    printf("%.2f",result);
    }
  //if user enter incorrect method system will print this statement
  else
    printf("Invalid operator \n");
  
  return 0;
}