/*
Infix to Postfix 

Easy Accuracy: 51.65% Submissions: 12803 Points: 2
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
​Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be abcd^e-fgh*+^*+i-
Example 2:

Input: str = "A*(B+C)/D"
Output: ABC+*D/
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be ABC+*D/
 
Your Task:
This is a function problem. You only need to complete the function infixToPostfix() that takes a string(Infix Expression) as a parameter and returns 
a string(postfix expression). The printing is done automatically by the driver code.

Expected Time Complexity: O(|str|).
Expected Auxiliary Space: O(|str|).

Constraints:
1 = |str| = 105
*/

// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int prec(char c){
       if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
    }
    string infixToPostfix(string str)
    {
        // Your code here
        stack<char>s;
        int n=str.length();
        string r="";
        for(int i=0;i<n;i++){
            char c=str[i];
            if(c=='(')
             s.push(c);
            else if(c==')'){
                while(!s.empty()&&s.top()!='(')
                 {r+=s.top();s.pop();}
                 s.pop();
            }
            else if(isalpha(c)||isdigit(c))
             r+=c;
            else {
                while(!s.empty() && prec(s.top())>=prec(c)){
                    r+=s.top();s.pop();
                }
                s.push(c);
            }
        }
        while(!s.empty()){
            r+=s.top();
            s.pop();
        }
        return r;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
