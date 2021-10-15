#include <iostream>
using namespace std;

int main() {    
    float number1, number2, number3;

    cout << "Enter three numbers: ";
    cin >> number1 >> number2 >> number3;

    if(number1 >= number2 && number1 >= number3)
        cout << "Largest number: " << number1;

    if(number2 >= number1 && number2 >= number3)
        cout << "Largest number: " << number2;
    
    if(number3 >= number1 && number3 >= number2)
        cout << "Largest number: " << number3;
  
    return 0;
}
