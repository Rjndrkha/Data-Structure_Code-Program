#include<bits/stdc++.h>

using namespace std;

#define ll long long int

#define pb push_back

#define mp make_pair

#define siz 2000005

#define mod 1000000007

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
int phi[1000001];
int maxN = 100000;
// Euler totient function for number is the number multiplied by their prime factor -1 and divided by the prime factor. Using 
// this fact we construct a sieve as prime factor will have it's own number as it doesn't have any prime factor 
void init(){
    for(int i=0 ; i<=maxN ; i++) phi[i]=i;
    for(int i=2 ; i<=maxN ; i++)
    {
        if( phi[i] == i) 
        {
            for(int j=i ; j<=maxN ; j+=i)
            {
                phi[j]*=(i-1);
                phi[j]/=(i);
            }
        }
    }
}
int main()
{
    init();
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<phi[n];
    }
}