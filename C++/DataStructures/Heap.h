#ifndef HEAP_H
#define HEAP_H

#include<iostream>

template <class T>
class MaxHeap
{
    T *heap;
    const int size;
    int currentPosition;

  public:
    MaxHeap(int size) : size(size)
    {
        heap = new T[size];
        currentPosition = -1;
    }
    MaxHeap(const MaxHeap<T> &heap)
    {
        this->heap = new T[heap.size];
        this->size = heap.size;
    }
    ~MaxHeap()
    {
        delete[] heap;
    }
    void insert(T data)
    {
        this->currentPosition++;
        this->heap[currentPosition] = data;
        this->fixUp();
    }

    T getMax()
    {
        T result = this->heap[0];
        this->heap[0] = this->heap[this->currentPosition];
        this->currentPosition--;
        this->fixDown(0);
        return result;
    }

    void printHeap()
    {
        for(int i=0;i<=currentPosition;i++)
        {
            std::cout<<this->heap[i]<<' ';
        }
        std::cout<<std::endl;
    }

  protected:
    void fixUp()
    {
        int index = this->currentPosition;
        int parentIndex = (int)((index-1)/2);
        while(parentIndex >= 0  && this->heap[parentIndex] < this->heap[index])
        {
            T temp = this->heap[index];
            this->heap[index] = this->heap[parentIndex];
            this->heap[parentIndex] = temp;
            index = parentIndex;
            parentIndex = (int)((index-1)/2);
        }
    }

    void fixDown(int index)
    {
        if (index<=this->currentPosition)
        {
            int leftChildPosition = 2*index+1;
            int rightChildPosition = 2*index+2;
            if(leftChildPosition <= this->currentPosition)
            {
                if(this->heap[index] < this->heap[leftChildPosition])
                {
                    T temp = this->heap[index];
                    this->heap[index] = this->heap[leftChildPosition];
                    this->heap[leftChildPosition] = temp;
                    this->fixDown(leftChildPosition);
                }
            }
            if(rightChildPosition <= this->currentPosition)
            {
                if(this->heap[index] < this->heap[rightChildPosition])
                {
                    T temp = this->heap[index];
                    this->heap[index] = this->heap[rightChildPosition];
                    this->heap[rightChildPosition] = temp;
                    this->fixDown(rightChildPosition);
                }
            }
        }
    }
};
#endif
