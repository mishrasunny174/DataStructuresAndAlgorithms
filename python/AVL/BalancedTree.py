from Node import Node

class BalancedTree(object):
    def __init(self):
        self.rootNode = None
    
    def insert(self, data):
        parentNode = self.rootNode
        if self.rootNode == None:
            parentNode = Node(data, self.rootNode)
            self.rootNode = parentNode
        else:
            parentNode = self.rootNode.insert(data, self.rootNode)
        self._reBalanceTree(parentNode)
    
    def _reBalanceTree(self, parentNode):
        parentNode.setBalance()
    
