#include <iostream>

#include <bits/stdc++.h>

using namespace std;




int stringToInt(char *arr, int num)
{
    if(num == 0)
    {
        return 0;
    }

    int lastDigit = arr[num-1] - '0';
 
    int small_ans = stringToInt(arr,num-1);
    
    return (10*small_ans) + lastDigit;
    
}




int main()
{
    char myarr[1000];
    cout << "Enter string: ";
    cin.getline(myarr,1000);

    int length = strlen(myarr);
    
    cout << "String: " << myarr << endl;
    int answer = stringToInt(myarr,length);
    
    cout << "Integer Value: " << answer << endl;
    

    return 0;
}
