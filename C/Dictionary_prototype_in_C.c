#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define dictionary dict
int dictionary(int a);

void main()
{
	int a; char b;

  printf("------------------------------ ENGLISH DICTIONARY -----------------------------\n");
  printf("Enter a number form the menu\n");
  a=0;
  do
  {
     if(a==0)
     {
         printf("\n1.Find the meaning of a word");
	     printf("\n2.Enter a new word");
         printf("\n3.Last word in the list");
         printf("\n4.Find the largest word(s)");
         printf("\n5.Count of total words in dictionary");
         printf("\n6.Write all words");
         printf("\n7.End program\n\n");
     }

     scanf("%d",&a);
     a=dict(a);
  }while(a!=7);
}
