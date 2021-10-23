Question:-

Print the following pattern for the given number of rows.
Note: N is always odd.


Pattern for N = 5



The dots represent spaces.



Input format :
N (Total no. of rows and can only be odd)
Output format :
Pattern in N lines
Constraints :
1 <= N <= 49
Sample Input 1:
5
Sample Output 1:
  *
 ***
*****
 ***
  *
Sample Input 2:
3
Sample Output 2:
  *
 ***
  *
  
    
Code:-
  
#include<iostream>
using namespace std;


int main()
{
     int n,n1,n2,i,j,k,x=1;
       cin>>n;
    n1=(n/2)+1;
    n2=(n/2);
      for(i=1;i<=n1;i++)
      {
          for(j=1;j<=n1-i;j++)
          {
              cout<<" ";
          }
          for(k=1;k<=i*2-1;k++)
          {
              cout<<"*";
          }
          cout<<endl;
      }
    
    
       for(i=1;i<=n2;i++)
       {
           for(j=1;j<=i;j++)
           {
               cout<<" ";
           }

           for(k=1;k<=n2*2-x;k++)
           {
               cout<<"*";
           }
           x=x+2;
           cout<<endl;
      }



}

  
