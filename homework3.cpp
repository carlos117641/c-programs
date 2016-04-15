#include <iostream>
using namespace std;

//my header
void displayHeader()
{
	cout << "+---------------------------------------------+" << endl;
	cout << "|     Computer Science and Engineering        |" << endl;
	cout << "|       CSCE 1030 - Computer Science          |" << endl;
	cout << "|  Carlos Sibrian chs0066 chs0066@my.unt.edu  |" << endl;
	cout << "+---------------------------------------------+" << endl;
	cout << " " << endl;
}

//what the program does
void displayInstructions()
{
	cout << "This program will display a trapezoid by asking the user to\n"
		 << "input both the top and bottom bases. Along with any character to display in." << endl;
	cout << " " << endl;
}

//get bases from the user
int getBases(int& b1, int& b2)
{
	//getting top base
	cout << "Please enter the top base which must be in between 1 and 17,\n"
		 << "but also an odd number: ";
	cin >> b1;
	cout << " " << endl;
	//input validation for top base
	while(b1 <= 0 || b1 >= 18)
	{
		cout << "Please enter a number between 1 and 17: ";
		cin >> b1;
		cout << " " << endl;
	}
	//input validation for when top base isn't odd
	if(b1==2 ||b1==4 ||b1==6 ||b1==8 ||b1==10 ||b1==12 ||b1==14 ||b1==16)
	{
		cout << "The base cannot be even! Try an odd number: " << endl;
		cin >> b1;
		cout << " " << endl;
	}
	//getting bottom base
	cout << "Please enter the bottom base which must be in between 3 and 19,\n" 
		 << "but also an odd number: ";
	cin >> b2;
	cout << " " << endl;
	//input validation for bottom base
	while(b2 <= 2 || b2 >= 20)
	{
		cout << "Please enter a number between 3 and 19: ";
		cin >> b2;
	}
	//input validation for when bottom base isn't odd
	if(b2==4 ||b2==6 ||b2==8 ||b2==10 ||b2==12 ||b2==14 ||b2==16 ||b2==18)
	{
		cout << "The base cannot be even! Try an odd number: " << endl;
		cin >> b2;
		cout << " " << endl;
	}
	//input validation for when bottom base > top base
	if(b2 < b1)
	{
		cout << "The bottom base must be greater than the top base which is " << b1 << "." << endl; 
		cout << "Enter a greater number, but also odd: ";
		cin >> b2;
		cout << " " << endl;
	}	
}

//get what the user wants to display for the trap
int getChar(char& print)
{
	cout << "Choose a character to display the shape: ";
	cin >> print;
	cout << " " << endl;
}

//this displays the trapezoid
void show(int& b1, int& b2, int& height, char& print)
{
	//initiate variables
	double area;
	int temp, temp2, temp3;
	getBases(b1, b2); //calls the base function
	getChar(print); //calls the character function
	//calculates height
	temp = b2-b1;
	temp2= temp/2;
	temp3= temp2+1;
	height = temp3;
	
	//makes the shape
	for (int row = 0; row < height; row++)
	{
		for (int col = height - row; col > 0; --col)
		{
			cout << " ";
		}
		for(int col = 0; col < (b1 + 2 * row); ++col)
		{
			cout << print;
		}
		cout << endl;
	}
	//calclates area/displays area
	area = .5 * height * (b1 + b2);
	cout << " " << endl;
	cout << "The area is " << area << " square units." << endl;
}

int main()
{
	//initiate variables
	int b1, b2, height;
	char print;
	displayHeader();
	displayInstructions(); //calls instructions/description
	show(b1, b2, height, print);

return 0;
}
