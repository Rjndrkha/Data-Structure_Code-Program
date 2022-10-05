#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define INF 1e18
#define fo(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define Fo(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vlli;
#define pb push_back
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

int main()
{
	IOS
    ll test=1;
    cin>>test;
    while (test--)
    {
        //your code goes here
		string x,y;
		cin>>x;
		cin>>y;
		int a=0,b=0,c=0,d=0;
		for(int i=0;i<x.length();i++){
			if(x[i]=='1'){
				a++;
			}
			else if(x[i]=='0'){
				b++;
			}
		}
		for(int i=0;i<y.length();i++){
			if(y[i]=='1'){
				c++;
			}
			else if(y[i]=='0'){
				d++;
			}
		}
		int e = min(a,d);
		int f = min(b,c);
		for(int i=0;i<(e+f);i++){
			cout<<1;
		}
		for(int i=0;i<(x.length()-(e+f));i++){
			cout<<0;
		}
		cout<<endl;
    }
    return 0;
}


