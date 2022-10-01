/* Q: Write a function which takes 3 arguments ( array of integers, length of array, int to tell how many cells to right shift by). FFunction should shift the contents
of each cell distance times to the right.unction should shift the contents
of each cell distance times to the right.

Ex: 10, 5, 2, 7, 3, 9

Function should return : 3, 9, 10, 5, 2, 7

*/

#include <iostream>

using namespace std;

void rotate_right(int array[], int len, int distance);


int main(){
    // Data for proof cheking
    int data[6] = {10, 5, 2, 7, 3, 9}, dataLen = 6, dataDistance = 2;
    rotate_right(data, dataLen, dataDistance);
}

void rotate_right(int array[], int len, int distance){

    int temp;
    while (distance)
    {

        temp = array[len - 1];
        for (int i = len - 1; i > 0; i--)
            array[i] = array[i - 1];

        array[0] = temp;

        distance--;
    }

    for (int i = 0; i < len; i++)
        cout << array[i] << " ";
    cout << endl;

}
