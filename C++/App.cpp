#include <iostream>
#include "DataStructures/QueueArray.h"

using namespace std;

int main(int argc, char *argv[])
{
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(11);
    queue.enqueue(12);
    queue.enqueue(13);
    queue.enqueue(14);
    queue.enqueue(15);
    queue.enqueue(45);
    try
    {
        while (true)
        {
            cout << queue.front() << endl;
            queue.dequeue();
        }
    }
    catch (QueueUnderflowException e)
    {
        cout << e.getMsg() << endl;
    }
    return 0;
}