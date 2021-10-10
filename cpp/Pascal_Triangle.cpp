#include <iostream>
using namespace std;

int main()
{
    int number=8,a;
    for (int i = 0; i <= number; i++)
	{
        for (int k = 0; k <= ((2*number)-(2*i)); k++)
		{
            cout<<" ";
        }
        for (int j = 0; j <= i; j++)
		{
            if (j==0||i==j)
			{
                a = 1;
            }
			else
			{
                a = a*(i+1-j)/j;
            }
            cout <<"  ";
            cout <<a;
            cout <<" ";
        }
            cout <<" ";
        cout << endl << endl;
    }
   return 0;
}

