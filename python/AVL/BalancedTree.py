class Node(object):
    def __init__(self, data):
        self.data = data
        self.leftChild = None
        self.rightChild = None
        self.balance = 0


class AVLTree(object):
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self.root = self._insert(node=self.root, data=data)

    def inOrderTraversal(self):
        if self.root is not None:
            self._inOrderTraversal(self.root)
        else:
            print('ERROR: tree is empty')
    
    def remove(self, data):
        if self.root is None:
            print('ERROR: tree is empty')
        else:
            self.root = self._remove(node=self.root, data=data)

    def getMinimum(self):
        return self._getMinimum(self.root)
    
    def getMaximum(self):
        return self._getMaximum(self.root)

    def _inOrderTraversal(self, node):
        if node.leftChild is not None:
            self._inOrderTraversal(node.leftChild)
        print(node.data)
        if node.rightChild is not None:
            self._inOrderTraversal(node.rightChild)

    def _insert(self, node, data):
        if data < node.data:
            if node.leftChild is None:
                node.leftChild = Node(data)
            else:
                node.leftChild = self._insert(node=node.leftChild, data=data)
        else:
            if node.rightChild is None:
                node.rightChild = Node(data)
            else:
                node.rightChild = self._insert(node=node.rightChild, data=data)
        node = self._balanceTree(node)
        return node

    def _balanceTree(self, node):
        self._calculateBalance(node)
        if node.balance > 1:
            if node.rightChild.balance == 1:
                node = self._rotateLeft(node)
            elif node.rightChild.balace == -1:
                node.rightChild = self._rotateRight(node.rightChild)
                node = self._rotateLeft(node)
        elif node.balance < -1:
            if node.leftChild.balance == -1:
                node = self._rotateRight(node)
            elif node.leftChild.balance == 1:
                node.leftChild = self._rotateLeft(node.leftChild)
                node = self._rotateRight(node)
        return node

    def _rotateLeft(self, node):
        temp = node.rightChild
        node.rightChild = temp.leftChild
        temp.leftChild = node
        return temp

    def _rotateRight(self, node):
        temp = node.leftChild
        node.leftChild = temp.rightChild
        temp.rightChild = node
        return temp

    def _calculateBalance(self, node):
        node.balance = self._calculateHeight(
            node.rightChild) - self._calculateHeight(node.leftChild)

    def _calculateHeight(self, node):
        if node is None:
            return -1
        return max(self._calculateHeight(node.leftChild), self._calculateHeight(node.rightChild)) + 1

    def _remove(self, node, data):
        if data < node.data:
            if node.leftChild is not None:
                node.leftChild = self._remove(node=node.leftChild, data=data)
        elif data > node.data:
            if node.rightChild is not None:
                node.rightChild = self._remove(node=node.rightChild, data=data)
        else:
            if node.leftChild is None:
                node = node.rightChild
            elif node.rightChild is None:
                node = node.leftChild
            else:
                node.data = self._getMaximum(node.leftChild)
                node.leftChild = self._remove(node=node.leftChild, data=node.data)
        if node is not None:
            node = self._balanceTree(node)
        return node
    
    def _getMaximum(self, node):
        if node.rightChild is None:
            return node.data
        return self._getMaximum(node.rightChild)
    
    def _getMinimum(self, node):
        if node.leftChild is None:
            return node.data
        return self._getMinimum(node.leftChild)