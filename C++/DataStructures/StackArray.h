#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include<exception>
#include<string>

class StackEmptyException : public std::exception
{
    std::string error;
  public:
    StackEmptyException(std::string error){
        this->error = error;
    }

    std::string getMsg(){
        return error;
    }

    virtual ~StackEmptyException() throw (){
        
    }
};

template<class T>
class Stack
{
    T* array;
    int size;
    int topIndex;
public:
    Stack()
    {
        this->size = 64;
        this->array = new T[size];
        this->topIndex = -1;
    }

    void push(T data){
        if(this->topIndex < this->size)
        {
            this->array[++topIndex] = data;
        }
        else
        {
            int tempSize=2*this->size;
            T* temp = new T[tempSize];
            for(int i=0;i<size;i++)
            {
                temp[i] = this->array[i];
            }
            delete[] this->array;
            this->array = temp;
            this->size = tempSize;
        }
    }

    T top() throw(std::exception)
    {
        if(topIndex<0){
            throw StackEmptyException("ERROR: Stack is empty");           
        } 
        return this->array[topIndex];
    }

    void pop() throw(std::exception)
    {
        if(topIndex<0){
            throw StackEmptyException("ERROR: Stack is empty");           
        } 
        this->topIndex--;
    }

    int getSize()
    {
        return topIndex+1;
    }
};

#endif