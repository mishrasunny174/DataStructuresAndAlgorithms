class Node(object):
    def __init__(self, data, nextNode=None):
        self.data = data
        self.nextNode = nextNode

    def remove(self, data, previous_node):
        if data == self.data:
            previous_node.nextNode = self.nextNode
            del self.data
            del self.nextNode
        else:
            if self.nextNode is not None:
                self.nextNode.remove(data, self)