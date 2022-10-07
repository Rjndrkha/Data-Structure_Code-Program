class Solution {
  public:
    
    bool check(int n,int d,int &s){
        if(n<=0) return true;
        if(n%10 <= s || n%10==d) return false;
        s+=n%10;
        if(check(n/10,d,s) == false) return false;

        return true;
    }
  
    vector<int> goodNumbers(int L, int R, int D) {
        // code here
        // int c=0;
        vector<int> res;
        for(int i=L;i<=R;i++){
            int s = i%10;
            if(s == D) continue;
            if(check(i/10,D,s)) res.push_back(i);
        }
        return res;
    }
};