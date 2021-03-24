#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class List
{
public:
	//starting reference of linked list
	Node* head = NULL;

	int count();
	void displayList();

	//functions for inserting
	void insertAtBeginning(int data);
	void insertAtEnd(int data);
	void insertAtPosition(int data, int index);

	void deleteAtBeginning();
	void deleteAtEnd();
	void deleteAtPosition(int index);

};

