// C program to count the number of times an integer occurs in a linked list

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
                                    // to struct node* type upon assignment in C... however this is not the case for C++ where new/delete should be used instead
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


// count the number of times an integer occurs in a linked list
int count_while(struct node* head, int numberToSearchFor){ // pass in the pointer to the head of the list, and the int to search for
	struct node* currentNodePtr = head; // make a local copy of the head pointer as it is a stack variable and should remain unchanged
	int count = 0;                      // initialize the count variable as local variables contain garbage upon allocation
	while (currentNodePtr != NULL){     // iterate through the list until the next pointer is NULL i.e. pointing to nothing or end of list
		if (currentNodePtr->data == numberToSearchFor) // if data in the node is equal to the integer being searched
			++count;                                   // then increment count
		currentNodePtr = currentNodePtr->next;         // continue to the next node in the list
	}
	return count;
}


int count_for(struct node* head, int numberToSearchFor){
	struct node* currentNodePtr;
	int count = 0;

	for(currentNodePtr = head; currentNodePtr != NULL; currentNodePtr = currentNodePtr->next){
		if(currentNodePtr->data == numberToSearchFor)
			++count;
	}
	return count;
}


int main(){
	struct node* head = NULL; // list is currently empty, thus initialize a NULL pointer as its head
	push(&head, 1);           // pass in the address of the head pointer, and the value to push onto the list
	push(&head, 3);
	push(&head, 1);           // must pass in the address of the head pointer (reference pointer) so that the callee can alter
	push(&head, 2);           // its memory, since the head pointer will point to a new node with each push (onto the top of the list)
	push(&head, 3);
	push(&head, 1);

	printf("1 occurs %d times \n", count_while(head, 1));
	printf("2 occurs %d times \n", count_while(head, 2));
	printf("3 occurs %d times \n\n", count_while(head, 3));

	printf("1 occurs %d times \n", count_for(head, 1));
	printf("2 occurs %d times \n", count_for(head, 2));
	printf("3 occurs %d times \n", count_for(head, 3));

	deallocateMemory(&head);
	printf("List memory deallocated, head (on the stack) at address %p set to %p\n", &head, head);
	return 0;
}