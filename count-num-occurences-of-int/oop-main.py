# OOP Python program to count the number of times an integer occurs in a linked list

class node:
	def __init__(self, data):  # constructor
		self.data = data  # data to be stored
		self.next = None  # pointer to the next node in the linked list, where None indicates end of the list

class linkedList:
	def __init__(self):  # initialize head
		self.head = None

	def count(self, numberToSearchFor):
		current = self.head
		count = 0
		while(current is not None):
			if current.data == numberToSearchFor:
				count += 1
			current = current.next
		return count

	def push(self, dataToPush):
		newNode = node(dataToPush)  # create new node assigning address to newNode
		newNode.next = self.head
		self.head = newNode
		print(newNode)


myList = linkedList()
myList.push(1)
myList.push(3)
myList.push(1)
myList.push(2)
myList.push(3)
myList.push(1)

print("1 occurs {} times" .format(myList.count(1)))
print("2 occurs {} times" .format(myList.count(2)))
print("3 occurs {} times" .format(myList.count(3)))

print("head -> data is {}" .format(myList.head.data))
print("head -> next is {}\n" .format(myList.head.next))
print("node-1 -> data is {}" .format(myList.head.next.data))
print("node-1 -> next is {}\n" .format(myList.head.next.next))
print("node-2 -> data is {}" .format(myList.head.next.next.data))
print("node-2 -> next is {}\n" .format(myList.head.next.next.next))
print("node-3 -> data is {}" .format(myList.head.next.next.next.data))
print("node-3 -> next is {}\n" .format(myList.head.next.next.next.next))
print("node-4 -> data is {}" .format(myList.head.next.next.next.next.data))
print("node-4 -> next is {}\n" .format(myList.head.next.next.next.next.next))
print("node-5 -> data is {}" .format(myList.head.next.next.next.next.next.data))
print("node-5 -> next is {}\n" .format(myList.head.next.next.next.next.next.next))