class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>v(n);
        for(int i =0; i<n; i++)
        {
            v[i].resize(i+1);
            v[i][0]=v[i][i]=1;
            for(int j =1; j<i; j++)
            {
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }
        return v;
    }
};
