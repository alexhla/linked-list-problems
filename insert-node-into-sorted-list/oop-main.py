# OOP Python program to insert node into a sorted list

from sys import argv

class Node:
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
		newNode = Node(dataToPush)
		newNode.next = self.head
		self.head = newNode


	def insertIntoSortedList(self, dataToInsert):
		current = self.head

		if(current == None or dataToInsert <= current.data):
			myList.push(dataToInsert)

		else:
			while(current.next is not None):
				if dataToInsert <= current.next.data:
					break
				current = current.next

			newNode = Node(dataToInsert)
			newNode.next = current.next
			current.next = newNode		



myList = linkedList()
myList.push(101)
myList.push(96)
myList.push(33)
myList.push(21)

print("node-0 is {}" .format(myList.getNth(0)))
print("node-1 is {}" .format(myList.getNth(1)))
print("node-2 is {}" .format(myList.getNth(2)))
print("node-3 is {}" .format(myList.getNth(3)))
print("node-4 is {}\n" .format(myList.getNth(4)))

if len(argv) > 1:					# if the user has passed in an argument use it as the script option
	commandLineArg = int(argv[1])
else:
	commandLineArg = 0

myList.insertIntoSortedList(commandLineArg)

print("node-0 is {}" .format(myList.getNth(0)))
print("node-1 is {}" .format(myList.getNth(1)))
print("node-2 is {}" .format(myList.getNth(2)))
print("node-3 is {}" .format(myList.getNth(3)))
print("node-4 is {}" .format(myList.getNth(4)))