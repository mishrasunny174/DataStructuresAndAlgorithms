#ifndef QUEUE_H
#define QUEUE_H

#include <exception>
#include <string>

class QueueUnderflowException : public std::exception
{
  public:
    std::string getMsg()
    {
        return "ERROR: QUEUE UNDERFLOW";
    }
};

template <class T>
class Queue
{
    T *array;
    int size;
    int head, tail;
    int numOfElements;

  public:
    Queue()
    {
        this->size = 4;
        this->array = new T[size];
        this->head = -1;
        this->tail = -1;
        this->numOfElements = 0;
    }
    Queue(const Queue &queue)
    {
        this->size = queue.size;
        this->array = new T[this->size];
        for (int i = 0; i < size; i++)
        {
            this->array[i] = queue.array[i];
        }
        this->head = queue.head;
        this->tail = queue.tail;
        this->numOfElements = queue.numOfElements;
    }
    ~Queue()
    {
        delete[] array;
    }
    void enqueue(T data)
    {
        if (tail == -1)
        {
            head = tail = 0;
            this->array[tail] = data;
        }
        else if (numOfElements < this->size)
        {
            tail = (tail + 1) % this->size;
            array[tail] = data;
        }
        else
        {
            int tempSize = this->size * 2;
            T *tempArray = new T[tempSize];
            for (int i = 0; i < this->size; i++)
            {
                tempArray[i] = this->array[i];
            }
            delete[] this->array;
            this->array = tempArray;
            this->size = tempSize;
            tail = (tail + 1) % this->size;
            this->array[tail] = data;
        }
        this->numOfElements++;
    }

    void dequeue() throw(QueueUnderflowException)
    {
        if (this->isEmpty())
        {
            QueueUnderflowException e;
            throw e;
        }
        else if(head == tail)
        {
            head = tail = -1;
        }
        else
        {
            this->numOfElements--;
            head = (head + 1) % this->size;
        }
    }

    T front()
    {
        if (this->isEmpty())
        {
            QueueUnderflowException e;
            throw e;
        }
        return this->array[head];
    }
    bool isEmpty()
    {
        return head==-1 && tail ==-1;
    }
};

#endif