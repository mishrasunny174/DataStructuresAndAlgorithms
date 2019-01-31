from BalancedTree import AVLTree

tree = AVLTree()

tree.insert(10)
tree.insert(20)
tree.insert(30)
tree.insert(40)
tree.insert(50)
tree.inOrderTraversal()
tree.remove(20)
print('\n')
tree.inOrderTraversal()
