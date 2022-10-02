#include<bits/stdc++.h>
using namespace std;
int stackeval(string s)
{
    stack<int> temp;

    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            temp.push(s[i]-'0');
        }
        else
        {
            int op1=temp.top();
            temp.pop();
            int op2=temp.top();
            temp.pop();
            switch(s[i])
            {
                case '+':
                temp.push(op1+op2);
                break;
                  case '-':
                temp.push(op1-op2);
                break;
                  case '/':
                temp.push(op1/op2);
                break;
                  case '*':
                temp.push(op1*op2);
                break;
                default:
                break;



            }



        }



    }

            return temp.top();



}
int main()
{
cout<<stackeval("-+7*45+20");
return 0;
    
}