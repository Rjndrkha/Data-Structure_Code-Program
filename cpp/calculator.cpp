/*
    Authors Name : Mayuri Kolhe
    Date Modified: 1 October, 2022
*/


/* Program of a calculator*/

#include <iostream>
 
using namespace std;
 
int main(){
    char mathoperator;
    double firstNumber, secondNumber;
 
    //Reading mathoperator from user
    cout<<"Enter an operator (+, -, *,): ";
    cin>>mathoperator;
 
   //Reading operands from user
    cout<<"Enter two operands: ";
    cin>>firstNumber;
    cin>>secondNumber;
 
    switch(mathoperator)
    {
        cout << firstNumber << " + " << secondNumber << " = " << firstNumber+secondNumber;
            break;
 
        case '-':
             cout << firstNumber << " - " << secondNumber << " = " << firstNumber-secondNumber;
            break;
 
        case '*':
             cout << firstNumber << " * " << secondNumber << " = " << firstNumber*secondNumber;
            break;
 
        case '/':
             cout << firstNumber << " / " << secondNumber << " = " << firstNumber/secondNumber;
            break;
 
        // operator doesn't match any case constant (+, -, *, /)
        default:
            cout<<"Error! please enter correct operator";
    }
 
    return 0;
 
}