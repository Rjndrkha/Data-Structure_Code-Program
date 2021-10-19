
 #include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void create();
void search();
void list();
void dlt();
void sval(int);

struct produc
{
	int p;       //price
	int q;       //quantity
	float gst;
	float total;
}p[5];
struct bill
{
	char no[5];           //bill no
	char fname[10];      //First name
	char lname[10];    //Last name
	char m_no[11];     //customer mobile no
	char date[9];
	float total;
}b;

FILE *fp,*flist;
int n,i;

void main()
{
	p[0].p=1200;
	p[1].p=1600;
	p[2].p=1100;
	p[3].p=1880;
	p[4].p=1300;

	clrscr();
	printf("\n\n\n");
	printf("\t_____________________________\n");
	printf("\t===CUSTOMER BILLING SYSTEM===\n");
	printf("\t-----------------------------\n\n");
	printf("\t1. CREATE BILL \n");
	printf("\t2. SEARCH BILL \n");
	printf("\t3. DELETE BILL \n");
	printf("\t4. LIST OF ALL BILLS \n");
	printf("\t0. EXIT \n\n");
	printf("\t=============================\n\n");

	do
	{
	printf("\tWhat you want to do ?");
	scanf("%d",&n);
	}while(n<0 || n>4);

	switch(n)
	{
	case 0:
	exit(0);
	break;

	case 1:
	create();
	break;

	case 2:
	search();
	break;

	case 3:
	dlt();
	break;

	case 4:
	list();
	break;
	}

	getch();
}

void create()
{
	int tmp;
	char ch;
	clrscr();

	n=101;
	flist=fopen("list.txt","r");
	while(fscanf(flist,"%d",&tmp)!=EOF)
	{
	if(n==tmp)
	n++;
	}
	fclose(flist);
	flist=fopen("list.txt","a");
	fprintf(flist,"%d ",n);
	fclose(flist);


	itoa(n,b.no,10);
	printf("====================================================");
	printf("\n   BILL NO : %s",b.no);// scanf("%s",b.no);
	printf("\n   NAME : "); scanf("%s %s",b.fname,b.lname);
	printf("   DATE(dd/mm/yy) : ");  scanf("%s",b.date);
	printf("   MOBILE NO : "); scanf("%s",b.m_no);
	printf("====================================================");
	printf("\n\n");

	b.total=0;

	fp=fopen(b.no,"w");
	fprintf(fp,"%s ",b.fname);fprintf(fp,"%s ",b.lname);
	fprintf(fp,"%s ",b.date);
	fprintf(fp,"%s ",b.m_no);

	repeat:

	printf("\n======================");
	printf("\n NO\tNAME\tPRICE");
	printf("\n----------------------");
	for(i=0;i<5;i++)
	{
	printf("\n %d",i+1);
	sval(i);
	}
	printf("\n======================");

	printf("\nEnter product number you want to buy ?");
	scanf("%d",&i);
	printf("Enter Quantity : ");
	scanf("%d",&p[i].q);
	fprintf(fp,"%d ",i-1);
	fprintf(fp,"%d ",p[i].q);
	printf("\nWant to buy another product ? (Y/N)");
	ch=getch();
	if(ch=='y' || ch=='Y')
	{
		goto repeat;
	}

	fclose(fp);

	clrscr();
	fp=fopen(b.no,"r");
	fscanf(fp,"%s",b.fname);fscanf(fp,"%s",b.lname);
	fscanf(fp,"%s",b.date);
	fscanf(fp,"%s",b.m_no);
	printf("====================================================");
	printf("\n   BILL NO   : %s",b.no);
	printf("\n   NAME      : %s %s",b.fname,b.lname);
	printf("\n   DATE(dd/mm/yy) : %s",b.date);
	printf("\n   MOBILE NO : %s",b.m_no);
	printf("\n----------------------------------------------------");
	printf("\nPRODUCT NAME\tPRICE \tQTY\tGST\tTOTAL");
	printf("\n----------------------------------------------------");
	while(fscanf(fp,"%d",&i)!=EOF)
	{
	fscanf(fp,"%d",&p[i].q);
	p[i].total=p[i].p*p[i].q;
	p[i].gst=p[i].total*0.28;
	p[i].total=p[i].total+p[i].gst;
	b.total=b.total+p[i].total;
	printf("\n");
	sval(i);
	printf("%d\t",p[i].q); printf("%.1f\t",p[i].gst); printf("%.1f",p[i].total);
	}
	printf("\n----------------------------------------------------");
	printf("\n   TOTAL\t\t\t\t%.1f",b.total);
	printf("\n====================================================");
	fclose(fp);
	getch();
	main();
}


void sval(i)
{
	if(i==0)
	{
		printf("    TV       \t%d\t",p[i].p);
	}
	else if(i==1)
	{
		printf("    AC       \t%d\t",p[i].p);
	}
	else if(i==2)
	{
		printf("    COOLER   \t%d\t",p[i].p);
	}
	else if(i==3)
	{
		printf("    FRIGER   \t%d\t",p[i].p);
	}
	else
	{
		printf("    LAPTOP   \t%d\t",p[i].p);
	}
}

void search()
{
	char bno[4];
	int i,g;
	clrscr();
	printf("Enter Bill No : ");
	scanf("%s",bno);
	fp=fopen(bno,"r");
	if(fp==NULL || fscanf(fp,"%s",b.fname)==EOF)
	{
		printf("There are no record via this bill no....");
	}
	else
	{
		clrscr();
		fseek(fp,0,0);
		fscanf(fp,"%s",b.fname);
		fscanf(fp,"%s",b.lname);
		fscanf(fp,"%s",b.date);
		fscanf(fp,"%s",b.m_no);
		printf("====================================================");
		printf("\n   BILL NO   : %s",bno);
		printf("\n   NAME      : %s %s",b.fname,b.lname);
		printf("\n   DATE      : %s",b.date);
		printf("\n   MOBILE NO : %s",b.m_no);
		printf("\n----------------------------------------------------");
		printf("\nPRODUCT NAME\tPRICE \tQTY\tGST($)\tTOTAL");
		printf("\n----------------------------------------------------");
		b.total=0;
		while(fscanf(fp,"%d",&i)!=EOF)
		{
		fscanf(fp,"%d",&p[i].q);
		p[i].total=p[i].p*p[i].q;
		p[i].gst=p[i].total*0.28;
		p[i].total=p[i].total+p[i].gst;
		b.total=b.total+p[i].total;
		printf("\n");
		sval(i);
		printf("%d\t",p[i].q); printf("%.1f\t",p[i].gst); printf("%.1f",p[i].total);
		}
		printf("\n----------------------------------------------------");
		printf("\n   TOTAL\t\t\t\t%.1f",b.total);
		printf("\n====================================================");
	}
	fclose(fp);
	getch();
	main();
}

void dlt()
{
	char bno[4];
	clrscr();
	printf("Enter Bill No : ");
	scanf("%s",bno);
	fp=fopen(bno,"r");
	if(bno==NULL || fscanf(fp,"%s",b.fname)==EOF)
	{
		printf("There are no record via this bill no....");
	}
	else
	{
		fclose(fp);
		fp=fopen(bno,"w");
		printf("your file is deleted successfully.....");
	}
	fclose(fp);
	getch();
	main();
}


void list()
{
	char bno[4];
	int i;
	clrscr();
	printf("===============================================================================");
	printf("\nBILL NO\tCUSTOMER_NAME\t\tDATE\t\tMOBILE NO\tTOTAL");
	printf("\n-------------------------------------------------------------------------------");
	flist=fopen("list.txt","r");
	fseek(flist,0,0);
	while(fscanf(flist,"%s",bno)!=EOF)
	{
		fp=fopen(bno,"r");
		if(fscanf(fp,"%s",b.fname)!=EOF)
		{
		b.total=0;
		fscanf(fp,"%s",b.lname);
		fscanf(fp,"%s",b.date);
		fscanf(fp,"%s",b.m_no);
		while(fscanf(fp,"%d",&i)!=EOF)
		{
		fscanf(fp,"%d",&p[i].q);
		p[i].total=p[i].p*p[i].q;
		p[i].gst=p[i].total*0.28;
		p[i].total=p[i].total+p[i].gst;
		b.total=b.total+p[i].total;
		}
		printf("\n%s\t%s %s",bno,b.fname,b.lname);

		if(strlen(b.fname)<6 || strlen(b.lname)<6)
		printf("\t");

		printf("\t%s\t%s\t%.1f",b.date,b.m_no,b.total);
		}
		fclose(fp);

	}
	fclose(flist);
	printf("\n-------------------------------------------------------------------------------");
	printf("\n===============================================================================");
	getch();
	main();
}
