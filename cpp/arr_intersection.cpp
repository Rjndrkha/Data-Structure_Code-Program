
// code for array intersection


#include <iostream>
using namespace std;
int main()
{
	// Write your code here.
    int ans;
    int arr1[5]={1,2,3,4,5};
    int arr2[3]={1,2,3};
    for(int i=0;i<5;i++)
    {
        int element=arr1[i];
        for(int j=0;j<3;j++)
        {
            if(element==arr2[j])
            {
                ans=(element);
                cout<< ans<<" ";
                arr2[j]=-1;
                break;
            }
        }
        
    }

}