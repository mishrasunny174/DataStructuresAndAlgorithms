from Node import Node

class LinkedList(object):
    def __init__(self):
        self.head = None
        self.size = 0

    # O(1) complexity
    def insertBegin(self, data):
        if self.head is None:
            self.head = Node(data=data)
        else:
            self.head = Node(data=data, nextNode=self.head)
        self.size += 1

    # O(n) complexity
    def insertEnd(self, data):
        if self.head is None:
            self.head = Node(data=data)
        else:
            tempNode = self.head
            while tempNode.nextNode is not None:
                tempNode = tempNode.nextNode
            tempNode.nextNode = Node(data=data)
        self.size += 1

    # O(n) complexity
    def remove(self, data):
        if self.head:
            if self.head.data == data:
                self.head = self.head.nextNode
            else:
                self.head.nextNode.remove(data, previous_node=self.head)
        self.size -= 1

    # O(n) complexity
    def traverse(self):
        tempNode = self.head
        while tempNode is not None:
            yield tempNode.data
            tempNode = tempNode.nextNode
                