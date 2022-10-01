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

int dict(int a)
{
  int b,i;

  if(a==1)
  {
    do
    {
        printf("Enter the word to be searched : ");
	    char p[50];
	    scanf("%s",p);
	    //printf("%d,\n",strlen(p));
	    FILE *fp=fopen("Dictionary.txt","r");
	    if (fp==NULL)
        {
            printf("404:FILE NOT FOUND\nTRY AGAIN");
            return(0);
        }
	    else
	    {
	        char s[50];
	        int f=1;
	        //printf("%s",fgets(s,50,fp));
	        //printf("%d",strlen(fgets(s,50,fp)));
	        //printf("%d",fseek(fp,0,SEEK_SET));
	        //printf("%d\n",ftell(fp));
            while(!feof(fp))
            {
                fgets(s,50,fp);
                //strtok(s,"\n");
                s[strcspn(s,"\n")]=0;
		        if(!strcmp(p,s))
                {
                    printf("Word found ,the meaning is ....\n");
                    f=0;
                    goto z;
                }
                //printf("%d , %s",strlen(s),s);
                //printf("%d\n",ftell(fp));
		    }
		    z:
            if(f!=0)
            {
                printf("Word not found\n");
            }
            printf("\nSearch another word? 1 for 'Yes' and 2 for 'No, show menu' : ");
	        scanf("%d",&i);
            printf("\n");
	    }
	    fclose(fp);
    }while(i==1);
    if(i==2)
    {
        return(0);
    }
  }



  else if(a==2)
  { int t;
    do
    {
        printf("Enter length of new word here : ");
        scanf("%d",&b);
	    printf("Enter the new word : ");
        char p[b+1];
        scanf("%s",p);
	    FILE *fp=fopen("Dictionary.txt","a+");
	    if (fp==NULL)
        {
            printf("404:FILE NOT FOUND");
            return(0);
        }
	    else
	    {
	        char s[50];
	        int f=1;
	        while(!feof(fp))
            {
                fgets(s,50,fp);
                s[strcspn(s,"\n")]=0;
		        if(!strcmp(p,s))
                {
                    f=0;
                    break;
                }
		    }
		    if(f==0)
                printf("Word is already in the list\n");
	        else
	        {
	            fseek(fp,0,SEEK_END);
                fprintf(fp,"\n");
		        fputs(p,fp);
		        printf("Word added\n");
	        }
	    }
	    printf("Want to continue adding words? 1 for 'Yes' and 2 for 'No, show menu' : ");
	    scanf("%d",&t);
	    printf("\n");
	    fclose(fp);
    }while(t==1);
    printf("\n");
    if(t==2)
        return(0);
  }

  else if(a==3)
  {
	FILE *fp=fopen("Dictionary.txt","r");
    if (fp==NULL)
    {
        printf("404:FILE NOT FOUND");
        return(0);
    }
    else
    {
	    char* p=(char*)calloc(50,sizeof(char));
		while(!feof(fp))
		{
			fgets(p,50,fp);
		}
		printf("Last word is : ");
		puts(p);
		free(p);
    }
    fclose(fp);
    return(0);
  }

  else if(a==4)
  {
	FILE *fp=fopen("Dictionary.txt","r");
    if (fp==NULL)
    {
        printf("404:FILE NOT FOUND");
        return(0);
    }
	else
	{
		char* p=(char*)calloc(50,sizeof(char));
		char s[50];
		fgets(s,50,fp);
		while(!feof(fp))
		{
			if( strlen(fgets(p,50,fp))>strlen(s) )
                strcpy(s,p);
		}
		printf("\nLargest word is : %s",s);
		free(p);
	}
	fclose(fp);
    return(0);
  }

  else if(a==5)
  {
	FILE *fp=fopen("Dictionary.txt","r");
    if (fp==NULL)
    {
        printf("404:FILE NOT FOUND");
        return(0);
    }
	else
	{
		int count=0;
		char* p=(char*)calloc(50,sizeof(char));
		while(!feof(fp))
		{
	        fgets(p,50,fp);
			count++;
		}
		printf("\nTotal no. of words are : %d\n",count);
		free(p);
	}
	fclose(fp);
	int c=getchar();
    return(0);
  }

  else if(a==6)
  {
	FILE *fp=fopen("Dictionary.txt","r");
    if (fp==NULL)
    {
        printf("404:FILE NOT FOUND");
        return(0);
    }
	else
	{
		char* p=(char*)calloc(50,sizeof(char));
		printf("----------------------------------- List starts -------------------------------\n");
		while(!feof(fp))
		{
	        printf("%s",fgets(p,50,fp));
			//printf("\n");
		}
		printf("\n----------------------------------- List ends ---------------------------------\n");
		free(p);
	}
	fclose(fp);
    return(0);
  }

  else
    return 7;
}
