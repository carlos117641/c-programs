//Carlos Sibrian
//Lab 9
//This program will simulate a check out register

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	//opening reciept and list of variables
	ofstream outputFile;
	outputFile.open ("Sales.txt");
	outputFile << "Funny Stuff Retail INC" << endl;
	outputFile << "_______________________" << endl;
	outputFile << "Receipt" << endl;
	outputFile << "--------" << endl;
	double tax = .08, total, subtotal, stockPrice, change, cash, cash2;
	int partNumber;
	int count;
	int howMany;
	int num = 0;
	int min = 1;
	int max = 9;
	
	struct stockInfo
	{
		double price;
		string description;
		int stockNumber;
	};
	stockInfo Info ;

	cout << fixed << showpoint << setprecision (2);
	//get part number
	cout << "Please enter a part number.\n";
	cout << "Enter 0 when finished.\n";
	cin >> partNumber;
	
	while (partNumber != 0)
	{
		ifstream inputFile;
		 //open file
		inputFile.open("Stock.txt");
		char description [20];
		
		for (count = min; count <= max; count++)
		{
			inputFile >> Info.stockNumber;
			inputFile >> Info.description;
			inputFile >> Info.price;
		
			if (partNumber == Info.stockNumber)
			{
				num = 1;
				cout << "How many " << Info.description << " for $" << Info.price << " they like? " << endl;
				cin >> howMany;
				subtotal = subtotal + (Info.price * howMany);
				outputFile << showpoint << fixed << setprecision (2);		
				stockPrice = Info.price * howMany;
				outputFile << "Item #" << Info.stockNumber << endl;
				outputFile << Info.description << " on sale now for : " << "$" << Info.price << endl; 
				outputFile << "x " << howMany << " = $" << stockPrice << endl;
			}
		}	
		if (num == 0)
		{
			cout << "Sorry that part number was not found.\n";
		}
	//close file
	inputFile.close ();	
	cout << "Please enter a part number. Enter 0 when finished.\n";
	cin >> partNumber;
	}
	//set decimals
	outputFile << showpoint << fixed << setprecision (2);
	//calculate subtotal
	cout << "Your subtotal is: " << "$" << subtotal << endl;
	outputFile << "Subtotal: " << "$" << subtotal << endl;
	//calculate tax
	tax = subtotal * .08;
	cout << "Taxes: " << "$" << tax << endl;
	outputFile << "Taxes: " << "$" << tax << endl;
	//calculating total
	total = subtotal + tax;
	cout << "The total is: " << "$" << total << endl;
	outputFile << "Total: " << "$" << total << endl;
	//calculating change
	cout << "Enter amount recieved.\n";
	cin >> cash;
	if (cash < total)
	{
		cout << "You do not have enough money.\n";
		cout << "Kindly ask for more money and enter whats recieved.\n";
		cin >> cash2;
		cout << "Cash Tendered: " << "$" << (cash + cash2) << endl;
		change = (cash + cash2) - total;
		cout << "Your change is: " << "$" << change << endl;
		outputFile << "Cash Tendered: " << "$" << (cash + cash2) << endl;
		outputFile << "Change: " << "$" << change << endl;
	}
	else
	{
		if (cash > total)
		{
			change = cash - total;
			cout << "Cash Tendered: " << "$" << cash << endl;
			cout << "Your change is: " << "$" << change << endl;
			outputFile << "Cash Tendered: " << "$" << cash << endl;
			outputFile << "Change: " << "$" << change << endl;
		}
	}
outputFile << "____________________________________" << endl;
outputFile << "Thank you for shopping. Come again!";
//close the file
outputFile .close ();
return 0;
}
