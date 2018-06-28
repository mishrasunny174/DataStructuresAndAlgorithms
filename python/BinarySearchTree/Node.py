class Node(object):
    def __init__(self, data):
        self.data = data
        self.leftNode = None
        self.rightNode = None
    
    def insert(self, data):
        if data < self.data:
            if self.leftNode is None:
                self.leftNode = Node(data=data)
            else:
                self.leftNode.insert(data=data)
        else:
            if self.rightNode is None:
                self.rightNode = Node(data=data)
            else:
                self.rightNode.insert(data=data)
    
    def getMin(self):
        if self.leftNode is None:
            return self.data
        else:
            return self.leftNode.data
    
    def getMax(self):
        if self.rightNode is None:
            return self.data
        else:
            return self.rightNode.getMax()
    
    def inOrderTraversal(self):
        if self.leftNode is not None:
            self.leftNode.inOrderTraversal()
        print(self.data, end=' ')
        if self.rightNode is not None:
            self.rightNode.inOrderTraversal()
    
    def remove(self, data, parentNode=None):
        if data < self.data:
            if self.leftNode is not None:
                self.leftNode.remove(data, parentNode=self)
        elif data > self.data:
            if self.rightNode is not None:
                self.rightNode.remove(data, parentNode=self)
        else:
            if self.leftNode is not None and self.rightNode is not None:
                self.data = self.rightNode.getMin()
                self.rightNode.remove(self.data, parentNode=self)
            elif parentNode.leftNode == self:
                if self.leftNode is not None:
                    tempNode = self.leftNode
                else:
                    tempNode = self.rightNode
                parentNode.leftNode = tempNode
            elif parentNode.rightNode == self:
                if self.leftNode is not None:
                    tempNode = self.leftNode
                else:
                    tempNode = self.rightNode
                parentNode.rightNode = tempNode
