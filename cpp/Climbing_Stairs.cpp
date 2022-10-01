//Ques Link: https://leetcode.com/problems/climbing-stairs/
//Approach: DP

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }
        int dp[n+1];
        memset(dp,0,sizeof(int));
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};
