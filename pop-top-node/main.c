// C program to pop the top node off of a linked list

#include<stdio.h>  // printf()
#include<stdlib.h> // malloc()


// singly linked list (one pointer per list node)
struct node{           // use struct to define the building blocks (elements, nodes) of the linked list
	int data;          // data to be stored
	struct node* next; // pointer to the next node in the linked list, where NULL indicates end of the list
};


// push data onto the top or front of the linked list
void push(struct node** headRef, int dataToPush){ // pass in head reference i.e. address of the head, and the data to be pushed onto the list
	struct node* newNode = malloc(sizeof(struct node)); // create a new linked list node using malloc() which dynamically allocates the number of bytes requested
                                    // on the heap and returns a void pointer (void*) as it does not know the data type being stored, often times this void* is
                                    // cast to the desired pointer type manually, however this unneccessary as the void* is automatically promoted 
                                    // to struct node* type upon assignment in C... however this is not the case for C++
	newNode->data = dataToPush;  // assign dataToPush to member data of newNode, more explicitly written as (*newNode).data = dataToPush
	newNode->next = *headRef;    // assign pointer stored in head to member next of newNode, more explicitly written as (*newNode).next = *headRef
	*headRef = newNode;          // assign address of newNode to the head, thus making it the new head of the list as it was pushed onto the top
	
	// printf("addr of head           (on the stack) %p\n", headRef);
	// printf("addr of ptr to newNode (on the stack) %p\n\n", &newNode);
	printf("addr of newNode (on the heap) %p\n", newNode);
	printf("newNode->data                 %d\n", newNode->data);
	printf("newNode->next                 %p\n\n", newNode->next);
}


// deallocate dynamic memory on the heap
void deallocateMemory(struct node** headRef){ // pass in head reference i.e. address of the head, so that its contents may be altered 
	struct node* currentNode = *headRef;      // pointer to the first node in the list
	struct node* temp;                        // pointer to store the address of the next node while current is being deallocated
	while (currentNode != NULL){         // traverse the linked list
		temp = currentNode;              // remember the address of the current node
		currentNode = currentNode->next; // go to the next node
		free(temp);                      // deallocate the heap memory of the previous node
	}
	*headRef = NULL;  // now that the list is empty there is nothing to point to, thus set the head to NULL
}


int getNth_for(struct node* head, int index){

	struct node* currentNodePtr; // to store a local copy of the head pointer as it is a stack variable and should remain unchanged
	int count = 0;

	// iterated through linked list, starting at the head, going until pointer in current node is NULL
	for(currentNodePtr = head; currentNodePtr != NULL; currentNodePtr = currentNodePtr->next){
		if(count == index)                     // if the desired index has been reached
			return currentNodePtr->data;       // then return the data in that node
		++count;                               // otherwise increment the index count
	}
	return -1; // end of list was reached before desired index value, thus the above return never executed, exit with error
}



int pop(struct node** headRef){    // pass in head reference i.e. address of the head, as its contents will be changed

	struct node* head = *headRef;  // dereference pointer to head, obtain address of the first node in linked list
	int dataToPop = head->data;    // retreive data that is to be popped

	*headRef = head->next;  // assign address of second node in list to head
	free(head);             // deallocate heap memory of the first node 

	return dataToPop;
}


int main(){
	struct node* head = NULL; // list is currently empty, thus initialize a NULL pointer as its head
	push(&head, 101);         // pass in the address of the head pointer, and the value to push onto the list
	push(&head, 33);          // must pass in the address of the head pointer (reference pointer) so that the callee can alter
	push(&head, 96);          // the caller's memory, since the head pointer will change with each push (onto the top of the list)
	push(&head, 21);          // otherwise sending the head pointer itself will pass by value creating a local copy in the push function

	printf("node-0 is %d\n", getNth_for(head, 0));
	printf("node-1 is %d\n", getNth_for(head, 1));
	printf("node-2 is %d\n", getNth_for(head, 2));
	printf("node-3 is %d\n", getNth_for(head, 3));
	printf("node-4 is %d\n\n", getNth_for(head, 4));

	printf("popped value is %d\n", pop(&head));	
	printf("node-0 is %d\n", getNth_for(head, 0));
	printf("node-1 is %d\n", getNth_for(head, 1));
	printf("node-2 is %d\n", getNth_for(head, 2));
	printf("node-3 is %d\n", getNth_for(head, 3));
	printf("node-4 is %d\n\n", getNth_for(head, 4));

	deallocateMemory(&head);
	printf("List memory deallocated, head (on the stack) at address %p set to %p\n", &head, head);
	return 0;
}