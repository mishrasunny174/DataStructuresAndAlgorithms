#include <iostream>
#include "DataStructures/BinarySearchTree.h"

using namespace std;

int main(int argc, char* argv[])
{
    BST<int> *bst = new BST<int>();
    bst->insert(10);
    bst->insert(20);
    bst->insert(5);
    bst->insert(15);
    bst->insert(40);
    bst->insert(1);
    bst->insert(2);
    bst->insert(3);
    bst->iterativeInorderTraversal();
    bst->findAndDeleteByCopying(10);
    bst->iterativeInorderTraversal(); 
    delete bst;
    return 0;
}