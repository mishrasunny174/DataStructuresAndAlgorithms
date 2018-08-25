#include <iostream>
#include "DataStructures/CircularLinkedList.h"

using namespace std;

int main()
{
    CircularList<int> list;
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtHead(30);
    list.display();
    try
    {
        while (true)
        {
            cout<<"Deleted "<<list.atHead()<<endl;
            list.deleteFromHead();
        }
    }
    catch (ListEmptyException lee)
    {
        cerr << lee.getMsg();
    }
}