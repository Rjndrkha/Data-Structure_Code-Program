#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

void toh(int n, char a, char b, char c)
{
    if(n==0)
    {
        return;
    }
    toh(n-1, a,c,b);
    cout<<n<<"["<<a<<" -> "<<b<<"]"<<endl;
    toh(n-1, c, b, a);
}

int main(){
    int n;
    char a ='A';
    char b = 'B';
    char c = 'C';
    scanf("%d", &n);
    toh(n, a, b, c);   
    return 0;
}