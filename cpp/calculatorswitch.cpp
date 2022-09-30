#include <iostream>
using namespace std;

int main(){

    float a, b, result;
    char arithmetic;

    cout << "Input first value: ";
    cin >> a;
    cout << "Input the arithmetic operations +, -, *, /: ";
    cin >> arithmetic;
    cout << "Input second value: ";
    cin >> b;
    cout << "The result of " << a << arithmetic << b << "= ";

    switch(arithmetic){
        case '+':
        result = a + b;
        break;
        case '-':
        result = a - b;
        break;
        case '*':
        result = a * b;
        break;
        case '/':
        result = a / b;
        break;
        default:
        cout << "You input the wrong operator or values" << endl;
    }
    
    cout << result <<  endl;
    return 0;
}