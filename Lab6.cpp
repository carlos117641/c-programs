//Carlos Sibrian
//Lab 6
//This program will sort the soldiers

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	//variables
	char firstName[10][20];
	char lastName[10][20];
	double height[10];
	double temp1;
	char nameTemp[20];
	int loops, count;
	
	ifstream inputFile;
	//get filename from user
	char filename[20];
	cout << "Enter the filename:  " << endl;
	cin >> filename;
	//open file
	inputFile.open(filename);
	//get the information
	for (int counter = 0; counter < 10; counter++)
	{
		inputFile >> lastName[counter];
		inputFile >> firstName[counter];
		inputFile >> height[counter];
	}
		//close file
		inputFile.close();
	loops = 1;
	while(loops <= 10)
	{
	count = 0;
		while (count < 9)
		{
			if (height[count] > height[count + 1])
			{
				temp1 = height[count];
				height[count] = height[count + 1];
				height[count + 1] = temp1;
				strcpy (nameTemp, firstName[count]);
				strcpy (firstName[count], firstName[count +1]);
				strcpy (firstName[count + 1], nameTemp);
				strcpy (nameTemp, lastName[count]);
				strcpy (lastName[count], lastName[count + 1]);
				strcpy (lastName[count + 1], nameTemp);
			}
			count = count + 1;
		}		
		loops = loops + 1;	
	}
	loops = 1;
	while(loops <= 10)
	{
	count = 0;
		while(count < 9)
		{
			if (height[count] == height[count + 1])
			{
				if (strcmp(lastName[count], lastName[count + 1]) > 0)
				{
					temp1 = height[count];
					height[count] = height[count + 1];
					height[count + 1] = temp1;
					strcpy (nameTemp, firstName[count]);
					strcpy (firstName[count], firstName[count +1]);
					strcpy (firstName[count + 1], nameTemp);
					strcpy (nameTemp, lastName[count]);
					strcpy (lastName[count], lastName[count + 1]);
					strcpy (lastName[count + 1], nameTemp);
				}
				if (strcmp(lastName[count], lastName[count + 1]) == 0)
					{
						if (strcmp(firstName[count], lastName[count + 1]) > 0)
						{
							temp1 = height[count];
							height[count] = height[count + 1];
							height[count + 1] = temp1;
							strcpy (nameTemp, firstName[count]);
							strcpy (firstName[count], firstName[count +1]);
							strcpy (firstName[count + 1], nameTemp);
							strcpy (nameTemp, lastName[count]);
							strcpy (lastName[count], lastName[count + 1]);
							strcpy (lastName[count + 1], nameTemp);
						}
					}
			}
			count = count + 1;	
		}
		loops = loops + 1;
	}
//display everything	
for (int counter = 0; counter < 10; counter++)
{
	cout << lastName[counter] << ",";
	cout << firstName[counter] << "-";
	cout << height[counter] << endl;
}
	
return 0;
}
