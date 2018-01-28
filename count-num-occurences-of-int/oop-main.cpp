// OOP C++ program to count the number of times an integer occurs in a linked list

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
		void push(int data);
		int count_while(int numberToSearchFor);
		int count_for(int numberToSearchFor);
};


linkedList::linkedList(){
	this->head = NULL; // list is currently empty, thus initialize a NULL pointer as its head
		cout << "constructor called, the head at address " << this << ", has been set to " << this->head << endl << endl;
}


linkedList::~linkedList(){
	cout << "deconstructor called and list deleted" << endl;
}


void linkedList::push(int data){
	node* newNode = new node;    // create a new linked list node, storing its address in newNode
	newNode->data = data;        // store data to be pushed in the newly created node
	newNode->next = this->head;  // new node must point to the previous first node
	this->head = newNode;        //  head points to new node

	cout << "addr of the myList class object (on the heap) " << this << endl;
	cout << "addr of pointer to newNode     (on the stack) " << &newNode << endl;
	cout << "addr of newNode (on the heap) " << newNode << endl;
	cout << "newNode->data " << newNode->data << endl;
	cout << "newNode->next " << newNode->next << endl << endl;
}

// count the number of times an integer occurs in a linked list
int linkedList::count_while(int numberToSearchFor){ // pass in the pointer to the head of the list, and the int to search for
	node* currentNodePtr = this->head; // make a local copy of the head pointer as it is a stack variable and should remain unchanged
	int count = 0;                      // initialize the count variable as local variables contain garbage upon allocation
	while (currentNodePtr != NULL){     // iterate through the list until the next pointer is NULL i.e. pointing to nothing or end of list
		if (currentNodePtr->data == numberToSearchFor) // if data in the node is equal to the integer being searched
			++count;                                   // then increment count
		currentNodePtr = currentNodePtr->next;         // continue to the next node in the list
	}
	return count;
}


int linkedList::count_for(int numberToSearchFor){
	node* currentNodePtr;
	int count = 0;

	for(currentNodePtr = this->head; currentNodePtr != NULL; currentNodePtr = currentNodePtr->next){
		if(currentNodePtr->data == numberToSearchFor)
		++count;
	}
	return count;
}


int main(){

	linkedList* myList = new linkedList();  // create variable myList that is of type linkedList*, which points to a linkedList class object

	myList->push(1);
	myList->push(3);
	myList->push(1);
	myList->push(2);
	myList->push(3);
	myList->push(1);				

	cout << "1 occurs " << myList->count_while(1) << " times " << endl;
	cout << "2 occurs " << myList->count_while(2) << " times " << endl;
	cout << "3 occurs " << myList->count_while(3) << " times " << endl << endl;

	cout << "1 occurs " << myList->count_for(1) << " times " << endl;
	cout << "2 occurs " << myList->count_for(2) << " times " << endl;
	cout << "3 occurs " << myList->count_for(3) << " times " << endl;

	cout << "pointer to myList object (on the stack) is at address " << &myList << endl;
	cout << "myList object (on the heap) is at address             " << myList << endl;

	delete myList;

	return 0;
}