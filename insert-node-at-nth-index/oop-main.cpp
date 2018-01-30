// OOP C++ program to insert node at nth index

#include <stdlib.h>   // strtol()
#include <iostream>   // cout
using namespace std;  // std::cout --> cout     std::endl --> endl


// singly linked list (one pointer per list node)
struct node{    // use struct to define the building blocks (elements, nodes) of the linked list
	int data;   // data to be stored
	node* next; // pointer to the next node in the linked list, where NULL indicates end of the list
};


class linkedList{
	public:
		node* head;

		linkedList();   // constructor
		~linkedList();  // deconstructor
		void push(node** headRef, int data);
		int getNth(int numberToSearchFor);
		void insertAtNthIndex(int index, int dataToInsert);		
};


linkedList::linkedList(){
	this->head = NULL; // list is currently empty, thus initialize a NULL pointer as its head
		cout << "constructor called, the head at address " << this << ", has been set to " << this->head << endl << endl;
}


linkedList::~linkedList(){
	cout << "deconstructor called and list deleted" << endl;
}


void linkedList::push(node** headRef, int data){
	node* newNode = new node;    // create a new linked list node, storing its address in newNode
	newNode->data = data;        // store data to be pushed in the newly created node
	newNode->next = *headRef;  // new node must point to the previous first node
	*headRef = newNode;        //  head points to new node

	cout << "addr of the myList class object (on the heap) " << this << endl;
	cout << "addr of pointer to newNode     (on the stack) " << &newNode << endl;
	cout << "addr of newNode (on the heap) " << newNode << endl;
	cout << "newNode->data " << newNode->data << endl;
	cout << "newNode->next " << newNode->next << endl << endl;
}


int linkedList::getNth(int index){
	node* currentNodePtr; // to store a local copy of the head pointer as it is a stack variable and should remain unchanged
	int count = 0;

	// iterated through linked list, starting at the head, going until pointer in current node is NULL
	for(currentNodePtr = head; currentNodePtr != NULL; currentNodePtr = currentNodePtr->next){
		if(count == index)                     // if the desired index has been reached
			return currentNodePtr->data;       // then return the data in that node
		++count;                               // otherwise increment the index count
	}
	return -1; // end of list was reached before desired index value, thus the above return never executed, exit with error
}


void linkedList::insertAtNthIndex(int index, int dataToInsert){

	node* current = this->head;
	int i;

	if(index == 0)
		push(&(this->head), dataToInsert);
	else {

		for(i = 0; i< (index-1); i++){
			current = current->next;
			if(current == NULL)
				return;
		}
		push(&(current->next), dataToInsert);
	}
}



int main(int argc, char* argv[]){

	linkedList* myList = new linkedList();  // create variable myList that is of type linkedList*, which points to a linkedList class object

	myList->push(&(myList->head), 101);
	myList->push(&(myList->head), 33);
	myList->push(&(myList->head), 96);
	myList->push(&(myList->head), 21);
			
	cout << "node-0 is " << myList->getNth(0) <<  endl;
	cout << "node-1 is " << myList->getNth(1) <<  endl;
	cout << "node-2 is " << myList->getNth(2) <<  endl;
	cout << "node-3 is " << myList->getNth(3) <<  endl;
	cout << "node-4 is " << myList->getNth(4) <<  endl <<  endl;

	int commandLineArg;
	if(argc > 1)
		commandLineArg = strtol(argv[1], NULL, 10);
	else
		commandLineArg = 0;

	myList->insertAtNthIndex(commandLineArg, 77);
	cout << "node-0 is " << myList->getNth(0) <<  endl;
	cout << "node-1 is " << myList->getNth(1) <<  endl;
	cout << "node-2 is " << myList->getNth(2) <<  endl;
	cout << "node-3 is " << myList->getNth(3) <<  endl;
	cout << "node-4 is " << myList->getNth(4) <<  endl <<  endl;

	cout << "pointer to myList object (on the stack) is at address " << &myList << endl;
	cout << "myList object (on the heap) is at address             " << myList << endl;

	delete myList;

	return 0;

}