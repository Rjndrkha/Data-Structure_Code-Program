/*
    Authors Name :Mayuri Kolhe
    Date Modified: 1/10/2022
*/


#include <iostream>
#include <limits>

using namespace std;

int main() {

    //Integer Numbers//
    int a = 1;
    long b = 2;
    short c = 3;

    //Decimal Numbers//
    float d = 1.5;
    double e = 2.5;

    //Character//
    char f = 'a';

    //Boolean//
    bool g = true;

    cout << "Integer Numbers" << endl;
    cout << a << endl;    
    cout << sizeof(a) << " Byte" << endl;
    cout << numeric_limits<int>::max() << endl;
    cout << numeric_limits<int>::min() << endl;

    cout << "long" << endl;
    cout << b << endl;
    cout << sizeof(b) << " Byte" << endl;
    cout << numeric_limits<long>::max() << endl;
    cout << numeric_limits<long>::min() << endl;

    cout << "Short" << endl;
    cout << c << endl;
    cout << sizeof(c) << " Byte" << endl;
    cout << numeric_limits<short>::max() << endl;
    cout << numeric_limits<short>::min() << endl;

    cout << "Float" << endl;
    cout << d << endl;
    cout << sizeof(d) << " Byte" << endl;
    cout << numeric_limits<float>::max() << endl;
    cout << numeric_limits<float>::min() << endl;

    cout << "Double" << endl;
    cout << e << endl;
    cout << sizeof(e) << " Byte" << endl;
    cout << numeric_limits<float>::max() << endl;
    cout << numeric_limits<float>::min() << endl;

    cout << "Character" << endl;
    cout << f << endl;
    cout << sizeof(f) << " Byte" << endl;
    cout << numeric_limits<double>::max() << endl;
    cout << numeric_limits<double>::min() << endl;

    cout << "Boolean" << endl;
    cout << g << endl;
    cout << sizeof(g) << " Byte" << endl;
    cout << numeric_limits<bool>::max() << endl;
    cout << numeric_limits<bool>::min() << endl;
    
    cin.get();
    return 0;
}