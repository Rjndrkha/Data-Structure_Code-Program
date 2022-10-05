#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include<bits/stdc++.h>
using namespace std;
char f[10] = "f";
char s[10] = "s";
int addr, ad, flag, f1, d, m, i, amt;
float tamt;
class login
{
	public:
	char id[100];
	char pass[100];
	char password[10];
	void getid()
	{
		cout << "\nEnter your id:";
		std::cin >> id;
		std::cout << "Enter the Password: ";
		std::cin >> password;
		std::cout << "\n";
		strcpy(pass,password);
	}
	void displayid()
	{
	    std::cout << "\n|" << "User_ID:" << "\t" << "|" << "Password\n";
		std::cout << "|" << id << "\t\t" << "|" << pass << "\n\n";
	}
};
class Detail
{
	public:
		int tno;
		char tname[100];
		char bp[100];
		char dest[100];

		int c1,c1fare;
		int c2,c2fare;
		int d,m,y;
		void getDetail()
		{
			std::cout << "\n--Add New details--\n";
			std::cout << "Train no: ";
			std::cin >> tno;
			std::cout << "Train Name: ";
			std::cin >> tname;
			std::cout << "Boarding point: ";
			std::cin >> bp;
			std::cout << "Destination pt: ";
			std::cin >> dest;
			std::cout << "No of seats in 1 class & fare per ticket: ";
			std::cin >> c1 >> c1fare;
			std::cout << "No of seats in 2 class & fare per ticket: ";
			std::cin >> c2 >> c2fare;
			std::cout << "Date of travel\n";
			std::cout << "Day: ";
			std::cin >> d;
			std::cout << "Month: ";
			std::cin >> m;
			std::cout << "Year: ";
			std::cin >> y;
		}
		void displaydetail()
		{
		    std::cout << "\n|Train No." << "\t" << "|Train Name" << "\t" << "|Boarding pt." << "\t" << "|Destination pt."  <<"\t";
			std::cout << "|F-Class" << "\t"<< "|F-Class Fare" << "\t" << "|S-Class" << "\t" << "|S-Class Fare" <<"\t";
			std::cout << "|Day" << "-" << "Month" << "-" << "Year" << "\n";

			std::cout << "|" << tno << "\t\t" << "|" << tname << "\t\t" << "|" << bp << "\t\t" << "|" << dest <<"\t\t\t";
			std::cout << "|" << c1 << "\t\t" << "|"<< c1fare << "\t\t" << "|" << c2<< "\t\t" << "|" << c2fare <<"\t\t";
			std::cout << "|" << d << "-" << m << "-" << y << "\n";
		}
};
class reser
{
	public:
	int pnr;
	int tno;
	char tname[100];
	char bp[10];
	char dest[100];
	char pname[10][100];
	int age[20];
	char clas[10];
	int nosr;
	int i;
	int d,m,y;
	int con;

	float amc;
	void getresdet()
	{
		cout<<"Enter the details as follows\n";
		cout<<"Train no:";
		cin>>tno;
		cout<<"Train name:";
		cin>>tname;
		cout<<"Boarding point:";
		cin>>bp;
		cout<<"Destination pt:";
		cin>>dest;
		cout<<"No of seats required:";
		cin>>nosr;
		for(i=0;i<nosr;i++)
		{
			cout<<"Passenger name:";
			std::cin >> pname[i];
			cout<<"Passenger age:";
			std::cin>>age[i];
		}
		cout<<"Enter the class f-first class s-second class:";
		std::cin >> clas;
		cout<<"Date of travel:";
		std::cin>>d>>m>>y;
		cout<<"Enter the concession category\n";
		cout<<"1.Military\n2.Senior citizen\n";
		cout<<"3.Children below 5 yrs\n4.None\n";
		std::cin>>con;
		cout<<"…………END OF GETTING DETAILS…………\n";
	}
	void displayresdet()
	{
		cout<<"Pnr no: "<<pnr;
		cout<<"\nTrain no: "<<tno;
		cout<<"\nTrain name: "<<tname;
		cout<<"\nBoarding point: "<<bp;
		cout<<"\nDestination pt: "<<dest;
		cout<<"\nNo of seats reserved: "<<nosr;
		for(i=0;i<nosr;i++)
		{
			cout<<"\nPassenger name: ";puts(pname[i]);
			cout<<"Passenger age: "<<age[i];
		}

		cout<<"\nYour class: ";puts(clas);
		cout<<"\nDate of reservation: "<<d<<"-"<<m<<"-"<<y;
		cout<<"\nYour concession category: "<<con;
		cout<<"\nYou must pay: "<<amc<<endl;
		cout<<"***********************************\n";
	}
};
class canc
{
    public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    int i;
    char clas[10];
    int nosc;
    int d, m, y;
    float amr;
    void getcancdet()
    {
        std::cout << "Enter the details as follows\n";
        std::cout << "Pnr no:";
        std::cin >> pnr;
        std::cout << "Date of cancellation:";
        std::cin >> d >> m >> y;
        std::cout << "………..END OF GETTING DETAILS………..\n";
    }
    void displaycancdet()
    {
        std::cout << "…………………………………….\n";
        std::cout << "…………………………………….\n";
        std::cout << "Pnr no:" << pnr;
        std::cout << "\nTrain no:" << tno;
        std::cout << "\nTrain name:";
        std::cout << tname;
        std::cout << "Boarding point:";
        std::cout << bp;
        std::cout << "Destination pt:";
        std::cout << dest;
        cout << "\nYour class:";
        std::cout << clas;
        cout << "no of seats to be cancelled:" << nosc;
        for (i = 0; i < nosc; i++)
        {
            std::cout << "Passenger name:";
            std::cout << pname[i];
            std::cout << "passenger age:" << age[i];
        }
        std::cout << "\nDate of cancellation:" << d << "-" << m << "-" << y;
        std::cout << "\nYou can collect:" << amr << "rs" << endl;
        std::cout << "*****************************************\n";
        std::cout << "………END OF CANCELLATION………….\n";
        std::cout << "*****************************************\n";
    }
};
void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();
int main(void)
{
	int ch;
	std::cout << "----- RAILWAY RESERVATION SYSTEM ----- \n";
	do
	{
		std::cout << "\n MAIN MENU \n";
		std::cout << "1.Admin mode\n2.User mode\n3.Exit \n";
		std::cout << "Enter your choice : ";
		std::cin >> ch;
		switch(ch)
		{
			case 1:
				database();
				break;
			case 2:
				user();
				break;
			default:
				exit(0);
		}
	}while(ch<3);

	return 0;
}

void database()
{
	char password[10];
	char pass[10] = "admin";
	std::cout << "\nEnter the Admin Password: ";
	std::cin >> password;
	Detail a;
	fstream f;
	int ch;
	char c;
	if(strcmp(pass,password)!=0)
	{
		std::cout << "Enter the password correctly \n";
		std::cout << "You are not permitted to login this mode\n";
	}
	if(strcmp(pass,password)==0)
	{
		char c;
		do
		{
			std::cout << "\n --- ADMINISTRATOR MENU --- \n";
			std::cout << "1. Create detail Database \n";
			std::cout << "2. Add details \n";
			std::cout << "3. Display details \n";
			std::cout << "4. User Management \n";
			std::cout << "5. Diplay Passenger details \n";
			std::cout << "6. Return to Main Menu \n";
			std::cout << "Enter your choice : ";
			std::cin >> ch;

			switch(ch)
			{
				case 1:
					f.open("t.txt",ios::out|ios::binary);
					do
					{
					a.getDetail();
					f.write((char *) & a,sizeof(a));
					cout << "\nDo you want to add one more record?\n";
					cout << "y-for Yes\nn-for No\n";
					cin >> c;
					}while(c=='y');
					f.close();
					break;
				case 2:
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					a.getDetail();
					f.write((char *) & a,sizeof(a));
					f.close();
					break;
				case 3:
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					f.seekg(0);
					while(f.read((char *) & a,sizeof(a)))
					{
					a.displaydetail();
					}
					f.close();
					break;
				case 4:
					manage();
					break;
				case 5:
					displaypassdetail();
					break;
			}
		}while(ch<=5);
	}
}

void reserve()
{
    int ch;
    do
    {
        std::cout << "1.Reserve\n2.Return to the main menu\n";
        std::cout << "Enter your choice:";
        std::cin >> ch;
        std::cout << endl;
        switch (ch)
        {
        case 1:
            res();
            break;
        }
    } while (ch == 1);
}

void res()
{
    Detail a;
    reser b;
    fstream f1, f2;
    time_t t;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);
    int ch;
    b.getresdet();
    while (f1.read((char *)&a, sizeof(a)))
    {
        if (a.tno == b.tno)
        {
            if (strcmp(b.clas, f) == 0)
            {
                if (a.c1 >= b.nosr)
                {
                    amt = a.c1fare;
                    addr = f1.tellg();
                    ad = sizeof(a.c1);
                    f1.seekp(addr - (7 * ad));
                    a.c1 = a.c1 - b.nosr;
                    f1.write((char *)&a.c1, sizeof(a.c1));
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PERSONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
                    srand((unsigned)time(&t));
                    b.pnr = rand();
                    f2.write((char *)&b, sizeof(b));
                    b.displayresdet();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "**********Sorry req seats not available********\n";
                }
            }
            else if (strcmp(b.clas, s) == 0)
            {
                if (a.c2 >= b.nosr)
                {
                    amt = a.c2fare;
                    addr = f1.tellg();
                    ad = sizeof(a.c2);
                    f1.seekp(addr - (5 * ad));
                    a.c2 = a.c2 - b.nosr;
                    f1.write((char *)&a.c2, sizeof(a.c2));
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PRESONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
                    f2.write((char *)&b, sizeof(b));
                    b.displayresdet();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "********Sorry req no of seats not available*******\n";
                }
            }
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "!\n";
    }
    f1.close();
    f2.close();
}

void displaypassdetail()
{
	std::cout << "\n--------Passenger Details--------\n";
	fstream f;
	reser b;
	f.open("p.txt",ios::in|ios::out|ios::binary);
	f.seekg(0);
	while(f.read((char *) & b,sizeof(b)))
	{
		b.displayresdet();
	}
	f.close();
}
void enquiry()
{
    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);
    Detail a;
    while(f.read((char *) & a,sizeof(a)))
    {
            a.displaydetail();
    }
}
void cancell()
{
    Detail a;
    reser b;
    canc c;
    fstream f1, f2, f3;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary);
    f3.open("cn.txt",ios::in|ios::out|ios::binary);
    cout<<"**********CANCELLATION MENU*********\n";
    c.getcancdet();
    while(f2.read((char *) & b,sizeof(b)))
    {
        if (b.pnr == c.pnr)
        {
            c.tno = b.tno;
            strcpy(c.tname, b.tname);
            strcpy(c.bp, b.bp);
            strcpy(c.dest, b.dest);
            c.nosc = b.nosr;
            for (int j = 0; j < c.nosc; j++)
            {
                strcpy(c.pname[j], b.pname[j]);
                c.age[j] = b.age[j];
            }
            strcpy(c.clas, b.clas);
            if (strcmp(c.clas, f) == 0)
            {
                while (f1.read((char *)&a, sizeof(a)))
                {
                    if (a.tno == c.tno)
                    {
                        a.c1 = a.c1 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.c1);
                        f1.seekp(addr - (7 * ad));
                        f1.write((char *)&a.c1, sizeof(a.c1));
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        goto h;
                        c.displaycancdet();
                    }
                }
            }
            else if (strcmp(c.clas, s) == 0)
            {
                while (f1.read((char *)&a, sizeof(a)))
                {
                    if (a.tno == c.tno)
                    {
                        a.c2 = a.c2 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.c2);
                        f1.seekp(addr - (5 * ad));
                        f1.write((char *)&a.c2, sizeof(a.c2));
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        goto h;
                        c.displaycancdet();
                    }
                }
            }
        }
        else
        {
            flag = 0;
        }
    }
    h:
    if(flag==0)
    {
            cout << "Enter the correct pnr no\n";
    }
    f1.close();
    f2.close();
    f3.close();
}
void can()
{
    int ch;
    do
    {
        cout << "……………..CANCELLATION MENU………\n";
        cout << "1.Cancel\n2.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            cancell();
            break;
        }
    } while (ch == 1);
}
void user()
{
	login a;
	int ch;
	cout<<"\n-----Login User-----\n";
	char password[10];
	fstream f;
	f.open("id.txt",ios::in|ios::out|ios::binary);
	char id[100];
	std::cout << "Enter your ID : ";
	std::cin >> id;
	std::cout << "Enter your Password : ";
	std::cin >> password;
	while(f.read((char *) & a,sizeof(a)))
	{
		if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
		{
			do
			{
				std::cout<<"\n1.Reserve\n2.Cancel\n3.Enquiry\n4.Return to the main menu\n";
				cout<<"Enter your choice:";
				cin>>ch;
				switch(ch)
				{
					case 1:
						reserve();
						break;
					case 2:
						cancell();
						break;
					case 3:
						enquiry();
						break;
				}
			}while(ch<=3);
		}
		else
		{
			d=1;
		}
	}
	if(d==1)
	{
		cout<<"Enter your user id and password correctly\n";
	}
}

void manage()
{
	int ch;
	fstream f;
	char c;
	login a;
	std::cout<<"\n---WELCOME TO THE USER MANAGEMENT MENU---\n";
	do
	{
		std::cout << "1. Create id database\n";
		std::cout << "2. Add details\n";
		std::cout << "3. Display details\n";
		std::cout << "4. Return to the main menu\n";
		std::cout << "Enter your choice: ";
		std::cin>>ch;
		switch(ch)
		{
			case 1:
				f.open("id.txt",ios::out|ios::binary);
				do
				{
					a.getid();
					f.write((char *) & a,sizeof(a));
					std::cout << "Do you want to add one more record\n";
					std::cout << "y-Yes\nn-No\n";
					std::cin>>c;
				}while(c == 'y');
				f.close();
				break;
			case 2:
				f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
				a.getid();
				f.write((char *) & a,sizeof(a));
				f.close();
				break;
			case 3:
				f.open("id.txt",ios::in|ios::out|ios::binary);
				f.seekg(0);
				while(f.read((char *) & a,sizeof(a)))
				{
					a.displayid();
				}
				f.close();
				break;
			}
		}while(ch<=3);
}
