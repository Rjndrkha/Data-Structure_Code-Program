/*
Remove K Digits 

Medium Accuracy: 38.39% Submissions: 7667 Points: 4
Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.

Example 1:

Input:
S = "149811", K = 3
Output: 111
Explanation: Remove the three digits 
4, 9, and 8 to form the new number 111
which is smallest.
Example 2:

Input:
S = "1002991", K = 3
Output: 21
Explanation: Remove the three digits 1(leading
one), 9, and 9 to form the new number 21(Note
that the output must not contain leading
zeroes) which is the smallest.

Your Task:
You don't need to read input or print anything. Your task is to complete the function removeKdigits() which takes the string S and an integer K as
 input and returns the new number which is the smallest possible.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).


Constraints:
1<=|S|<=10002
1<=K<=|S|
*/


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    string removeKdigits(string S, int k) {
        if(k>S.length())
return "0";
stack<char> s;
int i;
for(i=0;i<S.length();i++) {
    while(s.empty()!=1 && s.top()>S[i] && k>0)
{
s.pop();
k--;
}
if(S[i]=='0'&&s.empty()==1)continue;
else
{
s.push(S[i]);
}


}
if(k!=0)
{
while(s.empty()!=1&&k>0)
{
s.pop();
k--;
}
}

string res="";

while(s.empty()!=1)
{
res=res+s.top();
s.pop();
}
if(res=="")
{
return "0";
}
reverse(res.begin(),res.end());
return res;
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout<<obj.removeKdigits(S,K)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
