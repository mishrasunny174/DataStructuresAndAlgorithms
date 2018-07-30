#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include<exception>
#include<string>
#include<iostream>

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
        this->size = 2;
        this->array = new T[size];
        this->topIndex = -1;
    }

    void push(T data){
        if(this->topIndex < this->size-1)
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
            this->array[++topIndex] = data;
        }
    }

    T top() throw(StackEmptyException)
    {
        if(topIndex<0){
            throw StackEmptyException("ERROR: Stack is empty");           
        } 
        // std::cout<<"DEBUG: "<<topIndex<<std::endl;
        return this->array[topIndex];
        
    }

    void pop() throw(StackEmptyException)
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