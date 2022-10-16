class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> Pascal;
        vector<int> vec1;
        
        vec1.push_back(1);
        Pascal.push_back(vec1);

        if(numRows==1)
            return Pascal;
            
        vec1.push_back(1);
        Pascal.push_back(vec1);
        if(numRows==2)
            return Pascal;
        
        vec1.clear();
        
        for(int i=2;i<numRows;i++)
        {
            vec1.push_back(1);
            for(int j=0;j<=i-2;j++)
            {
                vec1.push_back(Pascal[i-1][j] + Pascal[i-1][j+1]);
            }
            vec1.push_back(1);
            Pascal.push_back(vec1);
            vec1.clear();
        }
        return Pascal;
        
    }
};
