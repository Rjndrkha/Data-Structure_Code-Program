class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum = 0, curr = 0;
        for(int i=0; i<shifts.size(); i++) {
            shifts[i] = shifts[i] % 26;
            sum += shifts[i];
        }
        for(int i=0; i<shifts.size(); i++) {
            int prev = shifts[i];
            shifts[i] = (sum - curr) % 26;
            curr += prev;
        }
        
        for(int i=0; i<shifts.size(); i++) {
            int toUp = shifts[i];
            
            if( (int)(s[i]) + toUp <= 122 ) {
                s[i] = (char)((int)(s[i]) + toUp);
            }
            else {
                toUp = (int)(s[i]) + toUp - 122;
                s[i] = 'a';
                s[i] = (char)((int)(s[i]) + toUp - 1);
            }
        }
        
        return s;
    }
};
