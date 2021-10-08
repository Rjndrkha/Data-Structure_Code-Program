#include<iostream>
#include<stack>
using namespace std;

//to reverse stack using another stack space->O(n), time->O(n^2)

void transfer(stack<int> &s1,stack<int> &s2, int n)
{
    for(int i=0;i<n;i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void revStack(stack<int> &s)
{
    stack<int> s2;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        int x=s.top();
        s.pop(); 
        //s to s2
        transfer(s,s2,n-i-1);
        //push x at the bottom
        s.push(x);
        //s2 to s
        transfer(s2,s,n-i-1);
    }
}

istream& operator>>(istream& is, stack<int> &s)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        s.push(d);
        cin>>d;
    }
    return is;
}

ostream& operator<<(ostream& os, stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
        
    }
    cout<<endl;
    return os;
}

int main()
{
    stack<int> s;
    cin>>s;
    cout<<"Before Rversing : "<<s;
    
    revStack(s);
    
    cout<<"After Reversing : "<<s;
    
}
