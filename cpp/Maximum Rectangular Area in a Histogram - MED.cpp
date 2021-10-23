/*
Maximum Rectangular Area in a Histogram 

Medium Accuracy: 47.42% Submissions: 37819 Points: 4
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For 
simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 


Example 2:

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
Your Task:
The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area 
possible and returns the answer.

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 = N = 106
1 = arr[i] = 1012
*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
         stack<pair<int,int>>s;
vector<int>nsr,nsl;

for(long long i=n-1;i>=0;i--){
if(s.empty())
nsr.push_back(n);
else if(!s.empty()&&s.top().first<arr[i]) 
nsr.push_back(s.top().second);
else if(!s.empty()&&s.top().first>=arr[i]){
while(!s.empty()&&s.top().first>=arr[i])
s.pop();
if(s.empty())
nsr.push_back(n);
else
nsr.push_back(s.top().second);

}
s.push({arr[i],i});
}
//int index_left=-1;
stack<pair<int,int>>st;
for(long long i=0;i<n;i++){ if(st.empty())
nsl.push_back(-1); 
else if(!st.empty()&&st.top().first<arr[i])
nsl.push_back(st.top().second);
else if(!st.empty()&&st.top().first>=arr[i]){
while(!st.empty()&&st.top().first>=arr[i])
st.pop();
if(st.empty())
nsl.push_back(-1);
else
nsl.push_back(st.top().second);
}
st.push({arr[i],i});
}
long long m=INT_MIN;
reverse(nsr.begin(),nsr.end());
for(long long i=0;i<n;i++) {m=max(m,(nsr[i]-nsl[i]-1)*arr[i]); }
return m; 
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
