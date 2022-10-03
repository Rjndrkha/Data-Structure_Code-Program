#include<bits/stdc++.h>
using namespace std;
 
// We can avoid use of these using references
int N = 20;
int n = 1;
 
void fun1();
void fun2();
 
// Prints n, increments n and calls fun1()
void fun1()
{
    if (n <= N)
    {
        cout << n << " ";
        n++;
        fun2();
    }
    else
        return;
}
 
// Prints n, increments n and calls fun2()
void fun2()
{
    if (n <= N)
    {
        cout << n << " ";
        n++;
        fun1();
    }
    else
        return;
}
 
// Driver Program
int main()
{
    fun1();
    return 0;
}
 