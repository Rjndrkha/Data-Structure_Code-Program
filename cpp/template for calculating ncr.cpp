//  ।।जय माता दी।।  

#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
        #include "debug.hpp"
    #else
        #define debug(...)
#endif
 
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define rall(x)            (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define per(i,a,b)        for(int i=a;i>=b;i--)
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
// TEMPLATE FOR NCR FACTORIAL AND BINARY EXPONENTIATIONS

const int M = 1e9 + 7;   
const int N = 1e6 + 1;
#define PRIME M          

int pw(int a,int p = M - 2, int MOD = M){      // Binary Exponentitaion
     int result = 1;
     while(p > 0){
         if(p & 1)
            result = a*result % MOD;
         a = a * a % MOD;
         p >>= 1;
     }
     return result;
} 

int fact[N],invfact[N];

void init(){            // Precomputing factorials and inverse of factorials upto N 
  int p = PRIME;
  fact[0] = 1;
  int i;
  for(i = 1; i < N; i++){
     fact[i]=i*fact[i-1]%p;
  }
  i--;
  invfact[i] = pw(fact[i],p-2,p);
  for(i--;i>= 0;i--){
     invfact[i] = invfact[i+1]*(i+1)%p;
  }
}

int ncr(int n,int r){          // ncr calculate 
   if(r > n or n < 0 or r < 0)return 0;
   return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;

}
 
 
void solve(){
    
    // you can use this code for finding ncr of a number 


 
  
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc = 1;
    //cin >> tc;
    while(tc--) solve();

}
