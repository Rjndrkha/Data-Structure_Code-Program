class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        int ans = 0, L = 0;
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                if (l == 1)
                    dp[i][j] = true;
                else if (l == 2)
                    dp[i][j] = (str[i] == str[j]);
                else 
                    dp[i][j] = (str[i] == str[j] and dp[i+1][j-1]);
                if (l > L and dp[i][j]) {
                    ans = i, L = l;
                }
            }
        }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        return str.substr(ans, L);
    }
};
