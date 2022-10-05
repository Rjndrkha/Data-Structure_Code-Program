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
		int n,m;
		cin>>n>>m;
		if(m%n==0 && m>=n){
			int p = m/n;
			cout<<"Yes"<<endl;
			for(int i=0;i<n;i++){
				cout<<m/n<<" ";
			}
			cout<<endl;
		}
		else{
			int p = m/n;
			int q = m%n;
			if((n-q)%2==0 && p>0){
				cout<<"Yes"<<endl;
				for(int i = 0;i<q;i++){
					cout<<p+1<<" ";
				}
				for(int i=q;i<n;i++){
					cout<<p<<" ";
				}
				cout<<endl;
			}
//			else if(flag==0){
//				int x,y;
//				for(int i=1;i<n+1;i++){
//					if(m%i==0){
//						x=m/i;
//						y=i;
//						flag=2;
//						break;
//					}
//				}
//				if(flag==2){
//					cout<<"Yes";
//					for(int i=0;i<y;i++){
//						cout<<x<<" ";
//					}
//					for(int i=y;i<n;i++){
//						cout<<0<<" ";
//					}
//					cout<<endl;
//				}
//			}
			else{
				cout<<"No"<<endl;
			}
		}
    }
    return 0;
}


