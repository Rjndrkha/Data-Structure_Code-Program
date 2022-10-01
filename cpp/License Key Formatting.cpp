//{ Driver Code Starts
/* Driver program to test above function */
#include<bits/stdc++.h>
using namespace std;
//} Driver Code Ends
//Back-end complete function Template for C++
class Solution
{
   public:
    string ReFormatString(string S, int k){
    	string help = "";
    	for(int i = 0; i < S.size() ; i++){
    	    if(S[i]!='-'){
    	        if(S[i]>='a' and S[i] <= 'z'){
                    char xx = (char)('A' + (S[i]-'a'));
                    string temp(1, xx);
                    help += temp;
    	        }else{
                    char xx = S[i];
                    string temp(1, xx);
                    help += temp;
    	        }
    	    }
    	}
    	int sz = help.size();
    	int grp = sz/k ;
    	int left = sz - grp*k ;
    	string ans = "" ;
    	ans += help.substr(0, left);
    	if(ans.size()!=0){
    	    ans += "-";
    	}
    	for(int i = left ; i < help.size() ; i+= k){
    	    ans += help.substr(i, k);
    	    ans += "-";
    	}
    	if(ans.back()=='-'){
    	    ans.pop_back();
    	}
    	return ans ;
    }
};

    
//{Driver code starts  
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        int K;
        cin>>K;
        Solution ob;
        string ans=ob.ReFormatString(S, K);
        cout<<ans;
        cout<<"\n";
    }
    return 0;
}
//} Drivercode starts
