#include<iostream>
using namespace std;
int gp(int n){
    int copy=n,m=-1,sum=0;
    while(n>0){
        m = max(m, n%10);
        n/=10;
    }
    while(copy > 0){
        sum += copy%10;
        copy/=10;
    }
    if((sum-m) == m) return 1;
    return 0;
}

int amt(int x,int y){
    int count = 0;
    for(int i=x;i<=y;i++){
        count += i;
        if(gp(i)) count -=i;
    }
    return count;
}

int main(){
    int x;
    cin >> x;
    int y;
    cin >> y;
    int a = amt(x,y);
    cout << a;
}