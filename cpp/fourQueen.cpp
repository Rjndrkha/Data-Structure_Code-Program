#include <iostream>
#include <cstdlib>
using namespace std;
#define n 4
int col[5];
bool place(int q,int c){
    for(int k=1;k<=q-1;k++){
        if(col[k]==c||abs(q-k)==abs(col[k]-c)){
            return false;
        } 
    }
    return true;
}
void fourqueen(int q){
    for(int c=1;c<=n;c++){
        if(place(q,c)){
            col[q]=c;
            if(q==n)
            {
                for(int i=1;i<=n;i++){
                    cout<<col[i]<<" ";
                }
                cout<<endl;
            }
            else{
                fourqueen(q+1);
            }
        }
    }
}
int main(){
    fourqueen(1);
    return 0;
}
