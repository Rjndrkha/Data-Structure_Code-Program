#include <iostream>
#include <cmath>
using namespace std;
int binary_octal(int n);
int octal_binary(int n);
int main()
{
   int n;
   char c;
   cout << "CHOICE: " << endl;
   cout << "1. Enter alphabet 'o' to convert binary to octal." << endl;
   cout << "2. Enter alphabet 'b' to convert octal to binary." << endl;
   cin >> c;
   if (c =='b' || c == 'B')
   {
       cout << "Enter a octal number: ";
       cin >> n;
       cout << n << " in octal = " << octal_binary(n) << " in binary";
   }
   if (c =='o' || c == 'O')
   {
       cout << "Enter a binary number: ";
       cin >> n;
       cout << n << " in binary = " << binary_octal(n) << " in octal";
   }
   return 0;
}
int binary_octal(int n)
{
    int octal=0, decimal=0, i=0;
    while(n!=0)
    {
        decimal+=(n%10)*pow(2,i);
        ++i;
        n/=10;
    }
    i=1;
    while (decimal!=0)
    {
        octal+=(decimal%8)*i;
        decimal/=8;
        i*=10;
    }
    return octal;
}
int octal_binary(int n)
{
    int decimal=0, binary=0, i=0;
    while (n!=0)
    {
        decimal+=(n%10)*pow(8,i);
        ++i;
        n/=10;
    }
    i=1;
    while(decimal!=0)
    {
        binary+=(decimal%2)*i;
        decimal/=2;
        i*=10;
    }
    return binary;
}
