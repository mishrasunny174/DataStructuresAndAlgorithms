#ifndef STACK_H
#define STACK_H

#include <exception>
#include <string>

template <class T>
class node
{
    T data;
    node<T> *next;
    template <class P>
    friend class Stack;

  public:
    node(T data, node *next = 0)
    {
        this->data = data;
        this->next = next;
    }
};

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

template <class T>
class Stack
{
    node<T> *head;
    int size;

  public:
    Stack()
    {
        this->head = 0;
        this->size = 0;
    }

    void push(T data)
    {
        if(head == 0)
        {
                head = new node<T>(data);
        }
        else
        {
            head = new node<T>(data, head);
        }
        this->size++;
    }

    T top() throw(StackEmptyException)
    {
        if (size == 0)
        {
            StackEmptyException exp("Stack is empty");
            throw exp;
        }
        else
        {
            return this->head->data;
        }
    }

    void pop() throw(StackEmptyException)
    {
        if (size == 0)
        {
            StackEmptyException exp("Stack is empty");
            throw exp;
        }
        else
        {
            this->head = this->head->next;
            this->size--;
        }
    }

    ~Stack()
    {
        node<T> *temp = head;
        while (head != 0)
            {
                *head = *head->next;
                delete temp;
                temp = head;
            }
    }

    bool isEmpty(){
        return size==0;
    }
};
#endif