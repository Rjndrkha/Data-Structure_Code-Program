

#include <iostream>

using namespace std;

int main()
{
    
    int num, key;
    
    cout << "Enter the number of elements in array: ";
    cin >> num;   
    
    int arr[1000]; 

    for (int i = 0; i < num; i++)
    {
        
        cin >> arr[i];
        
    }
    
    
    cout << "Enter the element you want to search:  " ;
    cin >> key;
    
    cout<<endl;
    
    int i;
    
    for ( i = 0; i < num; i++)
    {
        
        if (arr[i] == key)
        {
            
            cout << key << " is found at index "<< i;
            
            break;
        }
        
        
    }
    
    if (i == num )
    {
        
        cout << key << " is not found in array ";
        
    }

    return 0;
}
