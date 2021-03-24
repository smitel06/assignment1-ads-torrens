#include "List.h"

int List::count()
{
	int counter = 0;
	//iterator is a pointer that can move through our list
	Node* iterator = head;
	//loop until end of list
	while (iterator != NULL)
	{
		iterator = iterator->next;
		counter++;
	}

	return counter;
}

void List::displayList()
{
	Node* iterator = head;
	while (iterator != NULL)
	{
		cout << iterator->data << endl;

		iterator = iterator->next;
	}

}

void List::insertAtBeginning(int data)
{
	Node* newNode = new Node(data);
	//make new nodes next point to current head
	newNode->next = head;
	//Update head
	head = newNode;
}

void List::insertAtEnd(int data)
{
	//if list is empty use insert at front logic
	if (head == NULL)
	{
		insertAtBeginning(data);
		return;//exits this function early
	}

	Node* newNode = new Node(data);
	//setup iterator and move to end of list
	Node* iterator = head;
	//count to last spot on the list
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
	}
	iterator->next = newNode;
}

void List::insertAtPosition(int data, int index)
{
	if (head == NULL)
	{
		insertAtBeginning(data);
		return;//exits this function early
	}
	//if index requested for insert exceeds size of list
	//then insert at end
	if (index >= count())
	{
		insertAtEnd(data);
	}
	Node* newNode = new Node(data);

	//move 2 iterators up index and previous
	Node* iterator = head;
	Node* previous = head;
	for (int i = 0; i < index; i++)
	{
		previous = iterator;
		iterator = iterator->next;
	}
	//fit new node into list
	newNode->next = iterator;
	previous->next = newNode;
}

void List::deleteAtBeginning()
{
	//if list empty, do nothing
	if (head == NULL)
	{
		return;
	}

	Node* iterator = head;
	//move head to next position
	head = head->next;
	//delete old head
	delete iterator;
}

void List::deleteAtEnd()
{
	//if list empty, do nothing
	if (head == NULL)
	{
		delete (head);
		return;
	}

	Node* iterator = head;
	Node* previous = head;	
	while (iterator->next != NULL)
	{
		previous = iterator;
		iterator = iterator->next;
	}
	//detach
	previous->next = NULL;
	//delete the last node in list
	delete iterator;
}

void List::deleteAtPosition(int index)
{
	//if list empty, do nothing
	if (head == NULL)
	{
		delete(head);
		return;
	}
	//if index is at front
	if (index == 0)
	{
		deleteAtBeginning();
		return;
	}
	//if index is last node
	if (index >= count() - 1)
	{
		deleteAtEnd();
		return;
	}

	//move 2 iterators up index and previous
	Node* iterator = head;
	Node* previous = head;
	for (int i = 0; i < index; i++)
	{
		previous = iterator;
		iterator = iterator->next;
	}
	//detach index node, by rewiring the previous nodes next
	previous->next = iterator->next;
	//safe to delete now
	delete iterator;
	
}
