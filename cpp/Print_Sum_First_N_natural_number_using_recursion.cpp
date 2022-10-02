#include <bits/stdc++.h>
using namespace std;

int sum(int number)
{

    if (number == 0)
    {
        return 0;
    }
    else
    {

        return number + sum(number - 1); // recursion is used for doing the addition for doing the addition of the N natural Numbers.
    }
}

int main()
{
    int result, number;
    cout << "Enter number for which you want the sum:- ";
    cin >> number;
    result = sum(number);
    cout << "The sum of the given number " << number << " is:- " << result;
}