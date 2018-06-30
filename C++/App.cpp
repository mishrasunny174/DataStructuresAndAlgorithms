#include <iostream>
#include "DataStructures/Heap.h"

using namespace std;

int main(int argc, char* argv[])
{
    MaxHeap<int> heap(10);
    heap.insert(2);
    heap.insert(30);
    heap.insert(40);
    heap.insert(10);
    heap.printHeap();
    cout<<endl;
    cout<<heap.getMax()<<endl;
    heap.printHeap();
    return 0;
}