// Leetcode : (Medium Problem) 49. Group Anagrams
// Link : https://leetcode.com/problems/group-anagrams


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
    vector<string> vnew = v ; 
    int n = v.size(); 
	map<string , vector<int>> mp; 

	for (int i = 0; i < n; ++i)
	{
		sort(vnew[i].begin() , vnew[i].end()) ; 
	}
	for (int i = 0; i < n; ++i)
	{
		mp[vnew[i]].push_back(i+1) ; 
	}
	// for(auto & : mp){

	// }

	vector<vector<string>> vec ; 
	for(auto & i : mp){
		vector<string> vs ; 
		for(auto & j : i.second){
			vs.push_back(v[j-1]); 
		}
		vec.push_back(vs) ; 
	}
        
        return vec ; 
        
    }
};