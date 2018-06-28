from Node import Node

class BinarySearchTree(object):
    def __init__(self):
        self.rootNode = None
    
    def insert(self, data):
        if self.rootNode is None:
            self.rootNode = Node(data)
        else:
            self.rootNode.insert(data)
    
    def remove(self, data):
        if self.rootNode.data == data:
            tempNode = Node(None)
            tempNode.leftNode = self.rootNode
            self.rootNode.remove(data, tempNode)
        else:
            self.rootNode.remove(data)
            
    
    def getMax(self):
        if self.rootNode:
            return self.rootNode.getMax()

    def getMin(self):
        if self.rootNode:
            return self.rootNode.getMin()
    
    def inOrderTraversal(self):
        if self.rootNode:
            self.rootNode.inOrderTraversal()