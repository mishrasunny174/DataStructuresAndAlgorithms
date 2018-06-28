class Node(object):
    def __init__(self, data, parentNode):
        self.data = data
        self.parentNode = parentNode
        self.leftNode = None
        self.rightNode = None

    def insert(self, data, parentNode):
        if data < self.data:
            if self.leftNode is None:
                self.leftNode = Node(data, parentNode)
            else:
                self.leftNode.insert(data, parentNode)
        else:
            if self.rightNode is None:
                self.rightNode = Node(data, parentNode)
            else:
                self.rightNode.insert(data, parentNode)
        return parentNode
    
    def getMax(self):
        if self.rightNode is None:
            return self
        return self.rightNode.getMax()
    
    def getMin(self):
        if self.leftNode is None:
            return self
        return self.leftNode.getMin()

    def traverseInOrder(self):
        if self.leftNode is not None:
            self.leftNode.traverseInOrder()
        print(self.data+' ')
        if self.rightNode is not None:
            self.rightNode.traverseInOrder()
    
    @staticmethod
    def height(node):
        if node == None:
            return -1
        return 1 + max(Node.height(node.leftNode), Node.height(node.rightNode))
    
    def setBalance(self):
        self.balance = Node.height(self.leftNode) - Node.height(self.rightNode)