#include<stdio.h>

void print(char tabnine[30])
{
   int i;
  for(i=0;i<30;i++)
  {
  	printf("%c",tabnine[i]);
  }

}
void main()
{

	char tabnine [30]="welcome";
	print(tabnine);
}