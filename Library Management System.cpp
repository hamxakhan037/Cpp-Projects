#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
using namespace std;

	struct books
	{
		string bookName ;
		string authorName;
		int pub_Y;
		float price;		
	};
	struct issueBook
	{
		
		string personName;
		string personAddres;
		char phone[13];
	};
	
	// Functions here
	void add(int);
	void display();
	void del();
	void search();
	void issue_Book();
	void unIssueBook();
	void viewIssuedBooks();
	void end();
	void header();
	void show(int);
	
	// Global variables
	books book[100];
	books issuedBook[100];
	issueBook issue[100];
	// This variable keep tracks of total records
	int count=0;
	int issueCount=0;
	bool isIssued[100];
	char ch;
	
main()
{
	int num;
	int choice;

	while (true)
	{

	cout<<setw(84)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<setw(60)<<"Library\n";
	cout<<setw(84)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<setw(57)<<"||- 1. Add Books \t\t\t\t||"<<endl;
	cout<<setw(58)<<"||- 2. View Books \t\t\t\t||"<<endl;
	cout<<setw(60)<<"||- 3. Delete Books \t\t\t\t||"<<endl;
	cout<<setw(60)<<"||- 4. Search Books \t\t\t\t||"<<endl;
	cout<<setw(59)<<"||- 5. Issue Books \t\t\t\t||"<<endl;
	cout<<setw(61)<<"||- 6. Unissue Books \t\t\t\t||"<<endl;
	cout<<setw(64)<<"||- 7. View Issued Books \t\t\t||"<<endl;
	cout<<setw(57)<<"||- 8. Close App \t\t\t\t||"<<endl;
	cout<<setw(84)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<setw(84)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	cout<<setw(52)<<"| Select option: ";
	cin>>choice;
	cout<<endl;
	switch (choice)
	{
		case 1:
			system("cls");
			cout<<endl;
			cout<<setw(74)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
			cout<<setw(68)<<" | Enter num of books: ";
			cin>>num;
			add(num);
		break;
		case 2:
			system("cls");
			display();
		break;
		case 3:
			system("cls");
			del();
		break;
		case 4:
			system("cls");
			search();
		break;
		case 5:
			system("cls");
			issue_Book();
		break;
		case 6:
			system("cls");
			unIssueBook();
		break;
		case 7:
			system("cls");
			viewIssuedBooks();
		break;
		case 8:
			cout<<setw(72)<<"--------------------------\n";
			cout<<setw(64)<<"Thank you\n";
			cout<<setw(72)<<"--------------------------\n";
			exit(0);
			
		break;
	}
	}
	
}

void add(int num)
{	
	char ch;
	do
	{
		for (int i=0;i<num;i++)
		{

			cin.ignore(256, '\n');
			cout<<setw(59)<<" | Book Name: ";	
			getline(cin,book[i].bookName);
			cout<<setw(61)<<" | Author Name: ";
			getline(cin,book[i].authorName);
			cout<<setw(66)<<" | Publication Year: ";
			cin>>book[i].pub_Y;
			cout<<setw(55)<<" | Price: ";
			cin>>book[i].price;
			cout<<endl;
			// Increment n when new record is added
			count++;
		}
		cout<<setw(74)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<setw(71)<<" | Add a more book?(y/n): ";
		cin>>ch;
		if (ch == 'n' || ch == 'N')
		{
			cout<<endl;
			cout<<setw(72)<<"--------------------------\n";
			cout<<setw(70)<<"Books added sucessfully\n";
			cout<<setw(72)<<"--------------------------\n";
		}
	}
	while (ch != 'n' && ch !='N');
	end();
}

void display()
{	if (count !=0)
	{	
		header();	
		for (int i=0;i<count;i++)	
		{
			show(i);
		}
		end();		
	}
	else
	{
		cout<<"There is no book in library\n";
		end();
	}
	
}

void del()
{
	string name;
	int location;
	bool found = 0;
	
	if (count!=0)
	{
		cin.ignore(256, '\n');
		cout<<endl;
		cout<<setw(77)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<setw(75)<<"Enter book name to delete book: ";
		getline(cin,name);
		
		for (int i=0;i<count;i++)
		{
			if (book[i].bookName == name)
			{
				location = i;
				found = 1;
				cout<<endl;	
				for (int i=location;i<count;i++)
				{
					book[i] = book[i+1];
				}
				count--;
				cout<<setw(72)<<"Book found and deleted"<<endl;
				end();
			}
		}
		if (!found)
		{
			cout<<endl;
			cout<<setw(67)<<"Book not found"<<endl;
			end();
		}
		}
		else
		{
			cout<<"There is no book in the library\n";
			system("cls");
			end();
		}

}

void search()
{
	string name;
	bool isFound = false;
	
	if (count !=0)
	{	
		cout<<endl;
		cout<<setw(75)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<setw(70)<<"Enter book name to search: ";
		cin.ignore(256, '\n');
		getline(cin,name);
		
		for (int i=0;i<count;i++)
		{
			if (book[i].bookName == name)
			{
				isFound = true;
				cout<<endl;
				cout<<setw(65)<<"Book found\n"<<endl;
				cout<<setw(75)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
				header();
				show(i);
				
			}
			 
		}
		if (isFound == false)
			cout<<setw(65)<<"Book Not Found\n";
			end();
	}
	else
	{
	cout<<"There is no book in the library\n";
	end();
	}
	
}

void issue_Book()
{
	
	
	bool isFound = 0;
	if (count !=0)
	{	string name;
		cout<<endl;
		cout<<setw(77)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<setw(70)<<"Enter book name to issue: ";
		cin.ignore(256, '\n');
		getline(cin,name);
		
		for (int i=0;i<count;i++)
		{
			if (book[i].bookName == name)
			{
			
				cout<<setw(63)<<"Book Found"<<endl;
				isFound = 1;
				cout<<setw(70)<<"Enter borrower details"<<endl;
				cout<<setw(67)<<"Borrower name: ";
				cin>>issue[issueCount].personName;
				cout<<setw(64)<<"Adress: ";
				cin>>issue[issueCount].personAddres;
				cout<<setw(64)<<"Phone: ";
				cin>>issue[issueCount].phone;
				cout<<setw(72)<<"Book issued succesfully"<<endl;
				
				issuedBook[issueCount].bookName = book[i].bookName;
				issuedBook[issueCount].authorName = book[i].authorName;
				issuedBook[issueCount].pub_Y = book[i].pub_Y;
				issuedBook[issueCount].price = book[i].price;
				//Changing value of isIssued variable to true
				isIssued[i] = true;	
				issueCount++;
				end();
			}
		
		}
		if (isFound == 0)
		{
			cout<<setw(67)<<"Book Not Found\n";
			end();
		}
	
	


	}
		else 
		{
			cout<<"There is no book in the library\n";
			end();
		}
}

void unIssueBook()
{
	string name;
	int location;
	bool isFound = false;
	if (issueCount!=0)
	{
		cout<<setw(77)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<setw(75)<<"Enter book name to unissue: ";
		cin.ignore(256, '\n');
		getline(cin,name);
		
		for (int i=0;i<issueCount;i++)
		{
			if (issuedBook[i].bookName == name)
			{
				location = i;
				isFound = true;
				for (int j=location;j<issueCount;j++)
				{
					issuedBook[j] = issuedBook[j+1];
				}
				isIssued[i] = false;
				cout<<setw(75)<<"Book unissued\n";
				issueCount--;
			}
		}
		if (isFound == false)
		{
			cout<<setw(67)<<"Book Not Found\n";
			end();
		}
	}
	else
	{
		cout<<"There are no issued books\n";
		end();
	}
}

void viewIssuedBooks()	
{
	if (issueCount !=0)
	{
		cout<<"Issued Books are"<<endl;
		for (int i=0;i<issueCount;i++)
		{
			header();
			cout<<setw(12)<<issuedBook[i].bookName<<setw(23);
			cout<<issuedBook[i].authorName<<setw(23);
			cout<<issuedBook[i].pub_Y<<setw(25);
			cout<<issuedBook[i].price<<endl<<setw(20);
	
			cout<<setw(50)<<"Borrower Details"<<endl;
			cout<<"-----------------------------------------------------------";
			cout<<"-----------------------------------------------------------\n";
			cout<<"\tPerson Name\t\t\t\tPerson Adress\t\t\t\t\t\tPhone\n";
			cout<<"-----------------------------------------------------------";
			cout<<"-----------------------------------------------------------\n";
			cout<<setw(12)<<issue[i].personName<<setw(40);
			cout<<issue[i].personAddres<<setw(60);
			cout<<issue[i].phone<<endl<<setw(30);	
			end();
		}
	}
	else
	{
		cout<<endl;
		cout<<setw(75)<<"There are no issued books\n";
		end();
	}
}

void end()
{
	cout<<setw(77)<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	cout<<setw(70)<<"\t Any key to continue... ";
	getch();
	
	system("cls");
}
void header()
{
	cout<<"-----------------------------------------------------------";
	cout<<"-----------------------------------------------------------\n";
	cout<<"\tBook Name\t\tAuthor Name\t\tPublication Year\t\tPrice\t\tStatus\n";
	cout<<"-----------------------------------------------------------";
	cout<<"-----------------------------------------------------------\n";
}
void show(int i)
{	
	cout<<setw(12)<<book[i].bookName<<setw(25);
	cout<<book[i].authorName<<setw(25);
	cout<<book[i].pub_Y<<setw(27);
	cout<<book[i].price<<setw(20);
	if (isIssued[i] == true)
	cout<<"Issued\n\n";
	else
	cout<<"Available\n\n";
}

