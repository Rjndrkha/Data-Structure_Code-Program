// Codechef
// DSA Learning Series
// Contest 1
// Problem Code: LADDU

#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long int act, lim=400, rank, ladoos=0;
        string inp;
        cin>>act>>inp;
        if(inp == "INDIAN")
            lim = 200;
        while(act--){
            cin>>inp;
            if(inp == "CONTEST_WON"){
                cin>>rank;
                ladoos+= 300;
                if(rank<20)
                    ladoos+=20-rank;
            }
            else if(inp == "TOP_CONTRIBUTOR")
                ladoos+=300;
            else if(inp == "BUG_FOUND"){
                cin>>rank;
                ladoos+=rank;
            }
            else if(inp == "CONTEST_HOSTED")
                ladoos+=50;

        }
        cout<<ladoos/lim<<"\n";
    }

    return 0;
}