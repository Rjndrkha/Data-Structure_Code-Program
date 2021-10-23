/*
Reverse each word in a given string 

Medium Accuracy: 62.28% Submissions: 6586 Points: 4
Given a String. Reverse each word in it where the words are separated by dots.

Example 1:

Input:
S = "i.like.this.program.very.much"
Output: i.ekil.siht.margorp.yrev.hcum
Explanation: The words "i", "like",
"this", "program", "very", "much"
are all reversed.
​Example 2:

Input: 
S = "pqr.mno"
Output: rqp.onm
Explanation: Both "pqr" and "mno" are
reversed.

Your Task:
You don't need to read input or print anything. Your task is to complete the function reverseWords() which takes the string S as input and returns 
the resultant string by reversing all the words separated by dots.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).


Constraints:
1<=|S|<=105
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        int l = s.length();
int i;
string ans = "";
stack<char> st;

for(i = 0 ; i<l ;i++){if(s[i]== '.')
{while(!st.empty()){ans +=st.top();
st.pop(); }ans+= '.';}
else{st.push(s[i]); }}
while(!st.empty())
{ans+=st.top();st.pop();}return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
