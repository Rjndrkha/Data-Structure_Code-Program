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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n-3;i++){
			a[i]=i+1;
		}
		a[n-1]=a[0];
		a[n-3]=pow(2,29);
		a[n-2]=pow(2,30);
		for(int i=1;i<n-1;i++){
			a[n-1]=a[n-1]^a[i];
		}
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
    }
    return 0;
}


