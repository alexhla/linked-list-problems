# OOP Python program to sort an unsorted list

from sys import argv

class node:
	def __init__(self, data):  # constructor
		self.data = data  # data to be stored
		self.next = None  # pointer to the next node in the linked list, where None indicates end of the list

class linkedList:
	def __init__(self):  # initialize head
		self.head = None

	def getNth(self, index):
		current = self.head
		count = 0
		while(current is not None):
			if count == index:
				return current.data
			count += 1
			current = current.next
		return -1

	def push(self, dataToPush):
		newNode = node(dataToPush)
		newNode.next = self.head
		self.head = newNode


	def insertIntoSortedList(self, dataToInsert):
		current = self.head

		if(current == None or dataToInsert <= current.data):
			self.push(dataToInsert)

		else:
			while(current.next is not None):
				if dataToInsert <= current.next.data:
					break
				current = current.next

			newNode = node(dataToInsert)
			newNode.next = current.next
			current.next = newNode		


	def sortList(self):
		current = self.head
		tempList = linkedList()
		nextNode = None

		while(current is not None):
			nextNode = current.next
			tempList.insertIntoSortedList(current.data)
			current = nextNode

		self.head = tempList.head



myList = linkedList()
myList.push(33)
myList.push(21)
myList.push(101)
myList.push(96)

print("node-0 is {}" .format(myList.getNth(0)))
print("node-1 is {}" .format(myList.getNth(1)))
print("node-2 is {}" .format(myList.getNth(2)))
print("node-3 is {}" .format(myList.getNth(3)))
print("node-4 is {}\n" .format(myList.getNth(4)))


myList.sortList()

print("node-0 is {}" .format(myList.getNth(0)))
print("node-1 is {}" .format(myList.getNth(1)))
print("node-2 is {}" .format(myList.getNth(2)))
print("node-3 is {}" .format(myList.getNth(3)))
print("node-4 is {}\n" .format(myList.getNth(4)))

print("head -> data is {}" .format(myList.head.data))
print("head -> next is {}\n" .format(myList.head.next))
print("node-1 -> data is {}" .format(myList.head.next.data))
print("node-1 -> next is {}\n" .format(myList.head.next.next))
print("node-2 -> data is {}" .format(myList.head.next.next.data))
print("node-2 -> next is {}\n" .format(myList.head.next.next.next))
print("node-3 -> data is {}" .format(myList.head.next.next.next.data))
print("node-3 -> next is {}\n" .format(myList.head.next.next.next.next))