#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;



void main()
{
	bool exitProgram = false;
	bool isError = false;
	string errorReport;

	//while error is false run program
	while (!exitProgram)
	{
		int ascOrDesc; //ascending or descending order 0 ascending, 1 descending
		int algType; //easy or hard algorithm 0 being easy 1 being hard
		int elementAmount; //number of data elements to sort
		vector<int> dataElements; //vector of line 4 data elements



		//read first line in file
		ifstream inputFile("input-a1q1.txt");
		inputFile >> ascOrDesc;
		//read second line in file
		inputFile >> algType;
		//read third line in file
		inputFile >> elementAmount;
		//add elements to be sorted into vector using a loop
		for (int i = 1; i <= elementAmount; i++)
		{
			int temp;
			inputFile >> temp;
			dataElements.push_back(temp);
		}

		//error reports
		//line 1 error report
		if (ascOrDesc != 0 && ascOrDesc != 1)
		{
			isError = true;
			errorReport = "Error: The first line of the file contained an invalid number!";
		}
		//line 2 error
		else if (algType != 0 && algType != 1)
		{
			isError = true;
			errorReport = "Error: The second line of the file contained an invalid number!";
		}
		//line 3 error
		else if (elementAmount < 0)
		{
			isError = true;
			errorReport = "Error: The amount of data elements cannot be a negative number";
		}
		//line 4 error
		else if (elementAmount != dataElements.size())
		{
			isError = true;
			errorReport = "Error: The amount of data elements to be sorted is incorrect!";
		}


		

		
		












		








		exitProgram = true;
	}

	if (isError)
	{
		cout << errorReport << endl;
	}


	system("pause");
}