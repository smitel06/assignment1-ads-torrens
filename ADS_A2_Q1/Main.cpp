#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;

//functions

//sorts by swapping two values
void bubbleSort(vector<int>& numbers, int vectorSize)
{
	bool sorted = false;//loop while not sorted
	while (!sorted)
	{
		//assume sorted until proven otherwise
		sorted = true;
		for (int i = 0; i < vectorSize - 1 - 1; i++)
		{
			//check if curren arr[i] value is bigger then i + 1
			if (numbers[i] > numbers[i + 1])
			{
				//swap them
				//mySwap(arr, i, i + 1);
				swap(numbers[i], numbers[i + 1]);
				sorted = false;
				//start again
			}
		}
	}
}

void insertionSort(vector<int>& numbers, int vectorSize)
{
	for (int i = 1; i <= vectorSize - 1; i++)
	{
		//makes a copy of value at index i in array
		int key = numbers[i];
		int j = i - 1;

		//while j is index 0 or higher
		//and also as long value in j is bigger then key
		while (j >= 0 && numbers[j] > key)
		{
			//move value in index j up one
			numbers[j + 1] = numbers[j];
			//keep moving j to the left
			j = j - 1;
		}
		//we've moved everything up put key value back in where it should fit
		numbers[j + 1] = key;
	}
}


void main()
{
	//record start time for timing
	chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	bool isError = false;
	string errorReport;
	int ascOrDesc; //ascending or descending order 0 ascending, 1 descending
	int algType; //easy or hard algorithm 0 being almost sorted 1 being unsorted
	int elementAmount; //number of data elements to sort
	vector<int> dataElements; //vector of line 4 data elements

	ifstream inputFile("input-a1q1.txt");
	//read first line in file
	inputFile >> ascOrDesc;
	//read second line in file
	inputFile >> algType;
	//read third line in file
	inputFile >> elementAmount;
	//count number of elements in last line
	int numCount = 0;
	int i;
	while (inputFile >> i)
	{
		numCount++;
	}

	inputFile.close();//close the file we are reading to reset 
	inputFile.open("input-a1q1.txt");//reopen to go back to start
	int temp;
	for (int i = 1; i <= 3; i++)
	{
		inputFile >> temp;
	}

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
		errorReport = "Error: The first line of the file contained an invalid number!";
		isError = true;
	}
	//line 2 error
	if (algType != 0 && algType != 1)
	{
		errorReport = "Error: The second line of the file contained an invalid number!";
		isError = true;
	}
	//line 3 error
	if (elementAmount < 0)
	{
		errorReport = "Error: The amount of data elements cannot be a negative number";
		isError = true;
	}
	//line 4 error
	if (elementAmount != numCount)
	{
		errorReport = "Error: The amount of data elements to be sorted is incorrect!";
		isError = true;
	}
	//check for error

	//if type of algorithm requested is partially sorted use bubblesort
	//else use insertion sort
	if (algType == 0)
	{
		bubbleSort(dataElements, elementAmount + 1);
	}
	else
	{
		insertionSort(dataElements, elementAmount);
	}

	//recording end time for timer
	chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	if (isError == false)//checks for error before writing to file
	{
		//ascending or descending order conditional
		//open output file to write into
		ofstream outputFile;
		outputFile.open("output-a1q1.txt");
		//displays time in milliseconds for program
		outputFile << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << endl;


		if (ascOrDesc == 1)
		{
			for (int i = 0; i <= elementAmount - 1; i++)
			{
				outputFile << dataElements[i] << " ";
			}
		}
		else
		{
			for (int i = elementAmount - 1; i >= 0; i--)
			{
				outputFile << dataElements[i] << " ";
			}
		}
	}
	//exit program once algorithm has finished
	if (isError == true)
	{
		cout << errorReport << endl;
	}
	
	system("pause");
}