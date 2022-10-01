
//Program to input 10 integers in 1D array and search for a specific number

#define max 1000
int main()
{
	int n[max],i,a,loc;
	printf("Enter how many numbers:- \n");
	scanf("%d",&a);
	if(a>=max)
	{
		printf("Not Possible");
		return 0;
	}
	for(i=0; i<a; i++)
	{
		printf("Enter integers:- \n");
		scanf("%d",&n[i]);
	}
	printf("Enter the location:- \n");
	scanf("%d",&loc);
	if(loc>=a)
	{
		printf("yes, its possible");
		return 0;
	}
	printf("%d",n[loc]);
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
/* 

Output :-

Enter how many numbers:-
5
Enter integers:-
4
Enter integers:-
9
Enter integers:-
7
Enter integers:-
15
Enter integers:-
22
Enter the location:-
2
7

*/
