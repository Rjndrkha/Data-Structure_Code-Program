// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int map[256] = {0};
        int count = 0;
        for(int i = 0 ; i < p.length() ; i++)
        {
            if(map[p[i]] == 0)
                count++;
            map[p[i]]++;
        }
        int res = INT_MAX, ind = 0, i = 0, j = 0;
        while(j < s.length())
        {
            map[s[j]]--;
            if(map[s[j]] == 0)
                count--;
            while(count == 0)
            {
                if(res > j - i + 1)
                {
                    res = min(res, j - i + 1);
                    ind = i;
                }
                map[s[i]]++;
                if(map[s[i]] > 0)
                    count++;
                i++;
            }
            j++;
        }
        return res == INT_MAX ? "-1" : s.substr(ind, res);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
