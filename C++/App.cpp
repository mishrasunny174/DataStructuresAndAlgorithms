#include <iostream>
#include "DataStructures/AVLTree.h"

using namespace std;

int main(int argc, char* argv[])
{
    AVLTree<int> tree;
    for(int i=0;i<20;i++)
        tree.insert(i);
    tree.traverseInOrder();
    cout<<endl;
    tree.remove(10);
    tree.traverseInOrder();
    return 0;
}