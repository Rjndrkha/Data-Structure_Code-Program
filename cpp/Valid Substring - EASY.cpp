/*
Valid Substring 

Easy Accuracy: 48.25% Submissions: 25745 Points: 2
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses
 substring.
NOTE: Length of smallest the valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.
Example 2:

Input: S = "()(())("
Output: 6
Explanation: The longest valid 
substring is "()(())". Length = 6.

Your Task:  
You dont need to read input or print anything. Complete the function findMaxLen() which takes S as input parameter and returns the maxlength.


Expected Time Complexity:O(n)
Expected Auxiliary Space: O(1)   


Constraints:
1 <= |S| <= 105
*/

#include<bits/stdc++.h>
using namespace std;
int main()      //()(((()))
{
    int t; cin>>t;
    while(t--)
    {
        string f; cin>>f;
        int n; n=f.length();
        int max1 = 0;
        stack <int> s;
        s.push(-1);
        for(int i=0;i<n;i++)
        {
            if((f[i]==')')&&(!s.empty()))
            {
                if((f[s.top()]=='(')) 
                {
                    s.pop();
                    if((!s.empty())&&(max1<i-s.top())) max1=i-s.top();
                }
                else if((!s.empty()))
                {
                    s.pop();
                    s.push(i);
                    continue;
                }
            }
            else s.push(i);
        }
        cout<<max1<<endl;
    }
}


