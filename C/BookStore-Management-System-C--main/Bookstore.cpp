#include <iostream>
using namespace std;



class Author
{
private:
	char* Name;
	int Age;
	char Gender;
public:
	Author()
	{
		Name = new char[20];
		Name[0] = '\0';
		Age = 0;
		Gender = 'M'; //assumed to be M or F
	}
	Author(const char* name, int age, char gender)
	{
		cout << "Constructor of Author called." << endl;
		Name = new char[20];
		Age = 0;
		Gender = 'M'; //assumed to be M or F

		int i = 0;
		while (name[i] != '\0')
		{
			Name[i] = name[i];
			i++;
		}
		Name[i] = '\0';

		Age = age;
		Gender = gender;
	}
	void SetDetails() //To set the biographic details of Author
	{
		cout << "Author Name: ";
		cin >> Name;
		cout << "Age: ";
		cin >> Age;
		cout << "Gender(M or F): ";
		cin >> Gender;

	}
	void printData()const
	{
		if (Age != 0)
		{
			cout << "Author Name: " << Name << endl;
			cout << "Age: " << Age << endl;
			cout << "Gender: " << Gender << endl;
		}
	}
	char* GetName()const  //To get Name of author for book search using author's name
	{
		return Name;
	}
	~Author()
	{
		cout << "Destructor of Author called." << endl;
		//delete[]Name;
		//Name = nullptr;
	}
};

class Book
{
private:
	char* Title;
	double Price;
	char* Genre;
	Author* Authors; //Aggregation
public:
	Book()
	{
		Title = new char[25];
		Title[0] = '\0';
		Genre = new char[10];
		Genre[0] = '\0';
		Price = 0.0;
		Authors = new Author[3]; //it is assumed that a book can't have more than 3 authors
	}
	Book(const char* title, double price, const char* genre)
	{
		cout << "Constructor of Book called." << endl;
		Title = new char[25];
		Genre = new char[10];
		Price = 0.0;
		Authors = new Author[3]; //it is assumed that a book can't have more than 3 authors

		int i = 0;
		while (title[i] != '\0')
		{
			Title[i] = title[i];
			i++;
		}
		Title[i] = '\0';

		Price = price;
		
		int j = 0;
		while (genre[j] != '\0')
		{
			Genre[j] = genre[j];
			j++;
		}
		Genre[j] = '\0';
	}
	double GetPrice()const  //To get price of book for selling
	{
		return Price;
	}
	void printData()
	{
		cout << "Title: " << Title << endl;
		cout << "Price: " << Price << endl;
		cout << "Genre: " << Genre << endl;
		for (int i = 0;i < 3;i++)
		{
			Authors[i].printData();
		}
	}
	char* GetTitle()const  //to get title of book for search purpose
	{
		return Title;
	}
	char* GetGenre()const //To get genre for book search using genre
	{
		return Genre;
	}
	char* GetAuthorsName(int AuthorNum)const
	{
			return Authors[AuthorNum].GetName();
	
	}
	void AddAuthor(const Author author, int authornumber)
	{
		Authors[authornumber] = author;
	}
	~Book()
	{
		cout << "Destructor of Book called." << endl;
		/*delete[]Title;
		delete[]Genre;
		delete[]Authors;
		Title = nullptr;
		Genre = nullptr;
		Authors = nullptr;*/
	}
};


class BookStore
{
private:
	char* NameOfShop;
	double totalSales;
	Book* listOfBooks; //composition
	int BookNumber; //Serial number for book
public:
	BookStore()
	{
		NameOfShop = new char[10];
		NameOfShop[0] = '\0';
		totalSales = 0.0;
		listOfBooks = new Book[10];
		BookNumber = 0;
	}
	BookStore(const char* name)
	{
		cout << "Constructor of BookStore called." << endl;
		listOfBooks = new Book[10];
		NameOfShop = new char[10];
		totalSales = 0.0;
		BookNumber = 0;

		int i = 0;
		while (name[i] != '\0')
		{
			NameOfShop[i] = name[i];
			i++;
		}
		NameOfShop[i] = '\0';
	}
	
	void addBook(Book book)
	{
		if (BookNumber > 9)
		{
			cout << "Library is full!" << endl;
		}
		else
		{
			//check if already present
			bool block = false;
			for (int j = 0;j <= BookNumber;j++)
			{
				int cmp = strcmp(listOfBooks[j].GetTitle(), book.GetTitle());
				if(cmp==0)
				{
					cout << "Book Already Present!" << endl;
					block = true;
					break;
				}
			}

			if (block == false) // means no restriction, now book can be added!
			{
				listOfBooks[BookNumber] = book;
				BookNumber++;
			}
		}
	}
	void sellBook(const Book book)
	{

		bool present = false;
		for (int j = 0;j <= BookNumber;j++)
		{
			int cmp = strcmp(listOfBooks[j].GetTitle(), book.GetTitle());
			if (cmp == 0)
			{
				present = true;
				totalSales = totalSales + book.GetPrice();
				break;
			}
		}
		if (present == false)
		{
			cout << "Book not present!" << endl;
		}
		cout << "SALES AMOUNT: " << totalSales << endl;
	}
	void printAllBooks()
	{
		for (int i = 0;i < BookNumber;i++)
		{
			listOfBooks[i].printData();
		}
	}
	void printAllBooksByAuthor(const char* name)
	{
		for (int i = 0;i < BookNumber;i++)
		{
			char* tempAuthor = new char[20];
			for (int j = 0;j < 3;j++)
			{
				tempAuthor = listOfBooks[i].GetAuthorsName(j);
				int s1 = strlen(tempAuthor);
				int s2 = strlen(name);

				bool found = false;

				if (s1 != s2)
				{
					found = false;
				}
				else
				{
					for (int k = 0;k < s1;k++)
					{
						if (tempAuthor[k] == name[k])
						{
							found = true;

						}
						else
						{
							found = false;
							break;
						}
					}
				}
				if (found == true)
				{
					listOfBooks[i].printData();
				}
			}
		}
	}
	void printAllBooksOfGenre(const char* genre)
	{
		for (int i = 0;i < BookNumber;i++)
		{
			char* tempGenre = new char[10];
			tempGenre = listOfBooks[i].GetGenre();
			int s1 = strlen(tempGenre);
			int s2 = strlen(genre);
			
			bool found = false;
			
			if (s1 != s2)
			{
				found = false;
			}
			else

			{
				for (int j = 0;j < s1;j++)
				{

					if (tempGenre[j] == genre[j])
					{
						found = true;
					}
					else
					{
						found = false;
						break;
					}

				}
			}
			if (found==true)
			{
				listOfBooks[i].printData();
			}
		}
	}
	~BookStore()
	{
		cout << "Destructor of BookStore called." << endl;
		delete[]NameOfShop;
		NameOfShop = nullptr;
	}
};



int main()
{
	BookStore store1("Sultan");		//assumed that a bookstore can have no more than 10 books.
	Book b1("C++", 25.5, "study");
	Author a1("DS.MALIK", 45, 'M');
	b1.AddAuthor(a1, 0);		//It is assumed that a book cannot have more than 3 authors. authornumber should be(0-2).
	Author a2("Thomas", 32, 'M');
	b1.AddAuthor(a2, 1);
	Author a3("Sulaiman", 18, 'M');
	b1.AddAuthor(a3, 2);
	
	store1.addBook(b1);
	
	Book b2("DLD", 15.8, "electrical");
	Author a4("Morris", 43, 'M');
	b2.AddAuthor(a4, 0);
	
	store1.addBook(b2);
	
	store1.printAllBooksOfGenre("electrical");
	store1.printAllBooksByAuthor("Thomas");
	store1.sellBook(b2);

	return 0;
}