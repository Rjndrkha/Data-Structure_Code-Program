#include<iostream>
using namespace std;
void print(int arr[][4],int n,int m){
    int strtrow=0;
    int endcol=m-1;
    int endrow=n-1;
    int strtcol=0;
    while(strtrow<=endrow && strtcol<=endcol){
        for(int col=strtcol;col<=endcol;col++){
            cout<<arr[strtrow][col]<<" ";
        }
        for(int row=strtrow+1;row<=endrow;row++){
            cout<<arr[row][endcol]<<" ";
        }
        for(int col=endcol-1;col>=strtcol;col--){
            if(endrow==strtrow)
            break;
            cout<<arr[endrow][col]<<" ";
        }
         for(int row=endrow-1;row>=strtrow+1;row--){
            if(strtcol==endcol)
            break;
            cout<<arr[row][strtcol]<<" ";
        }
        strtrow++;
        endrow--;
        strtcol++;
        endcol--;
    }

}
int main(){
    int arr[][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20} 
    };
    int n=5,m=4;
    print(arr,n,m);

}
