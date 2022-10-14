//Binary Search

//only logic part

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        for(int i=0;i<n;i++){
            if(arr[i] == k){
                return i;
            }
        }
        return -1;
    }
};