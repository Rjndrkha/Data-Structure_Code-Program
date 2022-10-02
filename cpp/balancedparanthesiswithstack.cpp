#include<bits/stdc++.h>
using namespace std;


bool stackusingarr(string  a)
{
    stack<char> s;





    for(int i=0;i<a.length();i++)
    
    {
        if(s.empty())
        {
            s.push(a[i]);

        }
        else if(s.top()=='('&&a[i]==')'||s.top()=='{'&&a[i]=='}'||s.top()=='('&&a[i]==')')
{

    s.pop();

}
else
{
    s.push(a[i]);

}

    }
}







int main()
{

string a;
cin>>a;



    
}