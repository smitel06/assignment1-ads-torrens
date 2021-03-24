#include <iostream>
#include <string>
#include <fstream>
#include "List.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <chrono>

using namespace std;
void randomNumGen(vector<int> &randomNumVec, int n)
{
	int randomNum;
	

	//create loop that makes "n" amount of loops and inserts into
	//vector for return
	for (int i = 0; i <= n - 1; i++)
	{
		randomNum = rand() % 100;//create random number
		randomNumVec.push_back(randomNum);//push random number into vector
	}
	
}
void main()
{
	srand(time(NULL));//seeds the random number
	float time1;
	float time2;
	float time3;
	float time4;
	
	List list1;
	List list2;
	vector <int> randomNums1;
	int listLength;
	//open and read file to get list element length
	ifstream inputFile("input-a1q2.txt");
	inputFile >> listLength;
	inputFile.close();

	//generate random numbers for list
	randomNumGen(randomNums1, listLength);
	//insert random numbers at beginning of list 
	//record start time for timing
	chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
	for (int i = 0; i < randomNums1.size() ; i++)
	{
		//loop until finished and out of numbers
		list1.insertAtBeginning(randomNums1[i]);
	}
	chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
	time1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1).count();
	
	chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
	//insert random numbers at end of list
	for (int i = 0; i < randomNums1.size(); i++)
	{
		//loop until finished and out of numbers
		list2.insertAtEnd(randomNums1[i]);
	}
	chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
	time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2).count();

	chrono::steady_clock::time_point begin3 = std::chrono::steady_clock::now();
	//delete from beginning to remove all data
	for (int i = 0; i < randomNums1.size(); i++)
	{
		//loop until finished and out of numbers
		list1.deleteAtBeginning();
	}
	chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();
	time3 = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - begin3).count();
	
	chrono::steady_clock::time_point begin4 = std::chrono::steady_clock::now();
    //delete from end of list
	for (int i = 0; i < randomNums1.size(); i++)
	{
		//loop until finished and out of numbers
		list2.deleteAtEnd();
	}
	chrono::steady_clock::time_point end4 = std::chrono::steady_clock::now();
	time4 = std::chrono::duration_cast<std::chrono::milliseconds>(end4 - begin4).count();
	
	//write times to output file
	ofstream outputFile;
	outputFile.open("output-a1q2.txt");
	outputFile << time1 << endl;
	outputFile << time2 << endl;
	outputFile << time3 << endl;
	outputFile << time4 << endl;
	outputFile.close();




	




		




	system("pause");
}