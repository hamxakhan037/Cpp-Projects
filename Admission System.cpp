#include <iostream>
#include <iomanip>
using namespace std;

// Structur containing student data
struct student_data
{
	string name;
	int interMarks;
	int mathMarks;
	int birthYear;
	int passYear;
	char isHafiz;	
	int totalMarks;
	int age;
	bool isAdmitted;
};

	// Global Arrays 
	student_data data[10];
	student_data temp[10];

	// Functions
	void display();
	void sort();

main()
{
	
	// Getting user input
	for (int i=0;i<10;i++)
	{
				cout<<"Student "<<i+1<<" data:\n";
		cout<<"Full Name: ";
		getline(cin,data[i].name);
		cout<<"Inter Marks: ";
		cin>>data[i].interMarks;
		cout<<"Math Marks: ";
		cin>>data[i].mathMarks;
		cout<<"Birth Year: ";
		cin>>data[i].birthYear;
		cout<<"Passing Year: ";
		cin>>data[i].passYear;
		cout<<"Hafiz e Quran (y/n): ";
		cin>>data[i].isHafiz;
		
		cin.ignore(256, '\n');
		system("cls");
	}
		
	// Calculations
	for (int i=0;i<10;i++)
	{
		// Initiazlizing isAdmitted variable to true
		data[i].isAdmitted = true;
		
		// Store current year
		int currentYear = 2022;
		data[i].age = currentYear - data[i].birthYear;
		// Calculate age
		data[i].totalMarks = (data[i].mathMarks/2) + data[i].interMarks;
		
		// Other calculations
		if (data[i].isHafiz == 'y')
		{
			data[i].totalMarks += 20;		
		}
		if (data[i].passYear == 2020)
		{
			data[i].totalMarks -= 10;
		}
		 if (data[i].passYear <= 2019)
		{
			data[i].totalMarks -= 20;
		}
		 if (data[i].passYear < 2016 )
		{
			data[i].isAdmitted = false;
		}
		if (data[i].age > 26)
		{
			data[i].isAdmitted = false;
		}	
	}
	
	// Function calling
	sort();
	system("cls");
	display();

}

void display()
{
	cout<<endl<<endl;
	cout<<setw(5)<<"Sr.No\t Name\t\t Age\t Marks\t Passing Year\t Hafiz\t Total Marks\t\t Status\n";
	for (int i=0;i<10;i++)	
	{
		cout<<setw(2)<<i+1<<setw(15)<<data[i].name<<setw(10)<<data[i].age<<setw(10)<<data[i].interMarks<<setw(12)<<data[i].passYear<<setw(11);
		if (data[i].isHafiz == 'y')
		cout<<"Yes";
		else
		cout<<"No";
		
		cout<<setw(12)<<data[i].totalMarks<<setw(25);
		if (data[i].isAdmitted == true)
		cout<<"Admitted"<<endl;
		else
		cout<<"Not Admitted"<<endl;			
	}
}

void sort()
{ 
	for (int i=0;i<10;i++)
	{
		for (int j=i+1;j<10;j++)
		{
			if (data[i].totalMarks < data[j].totalMarks)
			{
				// Swapping struct arrays
				temp[i] = data[i];
				data[i]= data[j];
				data[j] = temp[i];
			}	
		}		
	}	
	
	// Changing admission status of last 5 students 
	for (int k=5;k<10;k++)
	data[k].isAdmitted = false;
				
}


