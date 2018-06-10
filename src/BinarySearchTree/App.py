from BinarySearchTree import BinarySearchTree

tree = BinarySearchTree()

tree.insert(10)
tree.insert(20)
tree.insert(15)
tree.insert(-1)
tree.insert(-2)
tree.insert(-4)

tree.inOrderTraversal()
print('\n')
tree.remove(10)

tree.inOrderTraversal()