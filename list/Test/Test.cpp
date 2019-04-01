// Test.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;
struct Node {
	int data;
	Node *next;
	Node();
	Node(int d, Node *link = NULL);

};
class List {
public:
	List();
	~List();
	int listSize();
	bool isFull();
	bool isEmpty();
	void reverse_copy();
	void duplicate();
	void makeEmpty();
	void addItem(int item);
	void addItemBegin(int item);
	void printList();
	int retrieve(int item);
	//int deleteItem(int item);
	bool search(int item);
private:
	Node *first;
	int count;
};
Node::Node()
{
	next = NULL;
}
Node::Node(int item, Node * link)
{
	data = item;
	next = link;
}	//node constructor with initial values
List::List()
{
	first = NULL;
	count = 0;
}
void List::makeEmpty() {
	Node*temp;
	count = 0;
	while (first != NULL) {
		temp = first;
		first = first->next;
		delete temp;
	}
}
bool List::isEmpty()
{
	return count == 0; // return first == NULL;	
}//empty
List::~List() {
	makeEmpty();
}
void List::addItem(int item) {
	Node*p, *before, *after;
	p = new Node;
	if (p != NULL) {
		p->data = item;
		before = NULL;
		after = first;
		while (after != NULL && after->data < item) {
			before = after;
			after = after->next;
		}
		if (before == NULL) {
			p->next = first;
			first = p;
		}
		else {
			p->next = before->next;
			before->next = p;
		}
		count++;
	}
}
//int List::deleteItem(int item) {
//	if (!isEmpty()) {
//		Node *p, *before;
//		before = NULL;
//		p = first;
//		while (p != NULL && p->data < item) {
//			before = p;
//			p = p->next;
//		}
//		if (p == NULL || p->data != item)
//			throw invalid_argument("Item was not found");
//		else {
//			int dataReturned = p->data;
//			if (before == NULL)
//				first = first->next;
//			else
//				before->next = p->next;
//			delete p;
//			count--;
//			return dataReturned;
//		}
//	}
//	else {
//		throw underflow_error("List underflow");
//	}
//}
void List::printList()
{
	std::cout << "List content:\n";
	if (count == 0)
		cout << "list is empty.\n";
	Node *p = first;
	while (p != NULL)
	{
		cout << p->data << ", ";
		p = p->next;
	}//while
}//printList
int List::listSize()
{
	return count;
}//listSize
bool List::isFull()
{
	bool result = false;
	Node *temp;
	temp = new Node();
	if (temp == NULL) 
		result = true;
	else	     	 
		delete temp;
	return result;
}//isFull
bool List::search(int item)
//returns true if item is in list, false otherwise
{
	Node *p = first, *after = p->next;

	while (p != NULL && after->data < item)
	{
		if (p->data == item) 	return true;
		else			p = p->next;
	}//while
	return false;
}//search
int List::retrieve(int item)
{
	Node *p = first, *after = p->next;;
	while (p != NULL && after->data < item)
	{
		if (p->data == item) 	
			return p->data;
		else			
			p = p->next;
	}
	cout << "item was not found, was not retrieved\n";
	return -10000; //to signal not found
}
void List::addItemBegin(int item)
//item is always inserted at the beginning of a list.
{
	if (isFull()) {
		cout << "List overflow\n";
		return; //return to the calling function
	}
	else {
		first = new Node(item, first);
		count++;
	}
}
//home task 1			
void List::duplicate() {
	Node *p, *before;
	p = first;
	before = NULL;
	while (p != NULL) {
		if ((before == NULL || before->data != p->data) && (p->next == NULL || p->next->data != p->data))
		{
			before = p;
			p = p->next;
			addItem(before->data);

		}
		else 
		{			
			before = p;
			p = p->next;
		}
	}
}
//home task 2
void List::reverse_copy() {
	Node *p;
	p = first;
	List L1;
	while (p != NULL) {
		L1.addItemBegin(p->data);
		p = p->next;
	}
	 L1.printList();
}

int main()
{
	List ob;
	ob.addItem(1);
	ob.addItem(3);
	ob.addItem(2);
	ob.addItem(5);
	ob.printList();
	cout << "\n";
	//ob.deleteItem(10);
	ob.printList();
	cout << "\n";
	ob.retrieve(7);
	ob.duplicate();
	ob.printList();
	cout << "\n";
	ob.reverse_copy();
	cout << "\n";
	ob.~List();
	ob.printList();
	system("pause");
		return 0;
}
