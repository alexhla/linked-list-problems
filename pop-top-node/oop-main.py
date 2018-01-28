# OOP Python program to pop the top node off of a linked list

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

	def pop(self):
		nodeToPop = self.head
		self.head = nodeToPop.next
		return nodeToPop.data


myList = linkedList()
myList.push(101)
myList.push(33)
myList.push(96)
myList.push(21)

print("node-0 is {}" .format(myList.getNth(0)))
print("node-1 is {}" .format(myList.getNth(1)))
print("node-2 is {}" .format(myList.getNth(2)))
print("node-3 is {}" .format(myList.getNth(3)))
print("node-4 is {}" .format(myList.getNth(4)))

print("popped value is {}" .format(myList.pop()))
print("node-0 is {}" .format(myList.getNth(0)))
print("node-1 is {}" .format(myList.getNth(1)))
print("node-2 is {}" .format(myList.getNth(2)))
print("node-3 is {}" .format(myList.getNth(3)))
print("node-4 is {}" .format(myList.getNth(4)))