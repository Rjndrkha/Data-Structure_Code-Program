#include<bits/stdc++.h>
using namespace std;

bool check(int arr[100][100], int i, int j, int n){

    for (int row = 0; row < i; row++) {

        if (arr[row][j] == 1) {

            return false;
        }
    }

    int x = i;
    int y = j;

    while (x >= 0 && y >= 0) {

        if (arr[x][y] == 1) {

            return false;
        }

        x--;
        y--;
    }

    x = i;
    y = j;

    while (x >= 0 && y < n) {

        if (arr[x][y] == 1) {

            return false;
        } 

        x--;
        y++;
    }
    return true;
}

//{1-2} {2-4} {3-1} {4-3}  {1-3} {2-1} {3-4} {4-2}

bool rec(int arr[100][100], int currRow, int row){
    
    if (currRow == row){

        //printing 2d array if we are at the last row

        for (int idx = 0; idx < row; idx++){

            for (int idy = 0; idy < row; idy++){

                if (arr[idx][idy] == 1){

                    cout<<idx<<"-"<<idy<<", ";
                }

            }
        }

        cout<<"."<<endl;

        return false;
    }

    for (int idy = 0; idy < row; idy++){

        // check if we can put the queen here
        if (check(arr, currRow, idy, row)){

            arr[currRow][idy] = 1;

            bool can = rec(arr, currRow + 1, row);

            if (can){

                return true;
            }

            arr[currRow][idy] = 0;
        }
    }

    return false;

}

int main() {

    int num;

    cin >> num;

    int arr[100][100] = {{0}};

    rec(arr, 0, num);

    return 0;
}