#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> get_stair_paths(int num) {
    
    if (num <= 0) {
        
        vector<string> answer;

        if (num == 0) {

            answer.push_back("");

            return answer;
        }
        
        return answer;
    }

    vector<string> ans1, ans2, ans3, ans;

    ans1 = get_stair_paths(num - 1);
    ans2 = get_stair_paths(num - 2);
    ans3 = get_stair_paths(num - 3);

    for (int idx = 0; idx < ans1.size(); idx++) {
        ans.push_back('1' + ans1[idx]);
    }

    for (int idx = 0; idx < ans2.size(); idx++) {
        ans.push_back('2' + ans2[idx]);
    }

    for (int idx = 0; idx < ans3.size(); idx++) {
        ans.push_back('3' + ans3[idx]);
    }
    
    return ans;
}

int main() 
{

    int num;

    cin >> num;

    vector<string> ans = get_stair_paths(num);

    int cnt = 0;

    cout << '[';

    for (string str : ans) 
    {
        if (cnt != ans.size() - 1) 
        {
            cout << str << ", ";
        }

        else 
        {
            cout << str;
        }

        cnt++;
    }

    cout << ']';

    return 0;
}