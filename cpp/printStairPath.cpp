#include <iostream>
using namespace std;

void printStairPaths(int num, string psf){
    
    if (num < 0) {
        return;
    }

    if (num == 0) {

        cout<<psf<<endl;
        return;
    }

    printStairPaths(num - 1, psf + '1');
    printStairPaths(num - 2, psf + '2');
    printStairPaths(num - 3, psf + '3');

    return;
}

int main(){

    int num;

    cin >> num;

    printStairPaths(num, "");

    return 0;
}