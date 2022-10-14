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
        int n,k;
        cin>>n>>k;
        if(k%4==0){
        	cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			if(k%4==1 || k%4==3){
				for(int i=1;i<n;i+=2){
					cout<<i<<" "<<i+1<<endl;
				}
			}
			else if(k%4==2){
				for(int i=3;i<n;i+=4){
					cout<<i<<" "<<i+1<<endl;
				}
				for(int i=2;i<=n;i+=4){
					cout<<i<<" "<<i-1<<endl;
				}
			}
		}

    }
    return 0;
}


