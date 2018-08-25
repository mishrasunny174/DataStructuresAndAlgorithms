#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST

#include <exception>
#include <string>
#include <iostream>

class ListEmptyException : public std::exception
{
  public:
    std::string getMsg()
    {
        return "ERROR: List is empty\n";
    }
};

template <class T>
class node
{
    T data;
    node *prev;
    node *next;
    template <class P>
    friend class CircularList;

  public:
    node(T data, node *prev = 0, node *next = 0)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

template <class T>
class CircularList
{
    node<T> *head, *tail;
    int size;

  public:
    CircularList()
    {
        this->head = this->tail = 0;
    }

    ~CircularList()
    {   if(this->head!=0)
        {
            while (this->head != 0)
            {
                this->deleteFromHead();
            }
        }
    }

    void insertAtHead(T data)
    {
        if (this->head == 0)
        {
            this->head = this->tail = new node<T>(data);
            this->head->prev = this->tail;
            this->head->next = this->tail;
        }
        else
        {
            this->head = new node<T>(data, this->tail, this->head);
            this->tail->next = this->head;
        }
    }

    void insertAtTail(T data)
    {
        if (this->tail == 0)
        {
            this->head = this->tail = new node<T>(data);
            this->tail->prev = this->tail;
            this->tail->next = this->tail;
        }
        else
        {
            this->tail->next = new node<T>(data, this->tail, this->head);
            this->tail = this->tail->next;
            this->head->prev = this->tail;
        }
    }

    T atHead() throw(ListEmptyException)
    {
        if (this->head == 0)
        {
            ListEmptyException lee;
            throw lee;
        }
        return this->head->data;
    }

    T atTail() throw(ListEmptyException)
    {
        if (this->tail == 0)
        {
            ListEmptyException lee;
            throw lee;
        }
        return this->tail->data;
    }

    void deleteFromHead() throw(ListEmptyException)
    {
        if (this->head == 0)
        {
            ListEmptyException lee;
            throw lee;
        }
        else if (this->head == this->tail)
        {
            delete this->head;
            this->head = this->tail = 0;
        }
        else
        {
            node<T> *temp = this->head;
            this->head = this->head->next;
            this->head->prev = this->tail;
            this->tail->next = this->head;
            delete temp;
        }
    }

    void deleteFromTail() throw(ListEmptyException)
    {
        if (this->tail == 0)
        {
            ListEmptyException lee;
            throw lee;
        }
        else if (this->tail == this->head)
        {
            delete this->tail;
            this->head = this->tail = 0;
        }
        else
        {
            node<T> *temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = this->head;
            this->head->prev = this->tail;
            delete temp;
        }
    }

    void display()
    {
        node<T> *temp = this->head;
        do
        {
            std::cout<<temp->data<<" -> ";
            temp = temp->next;
        }while(temp!=this->head);
        std::cout<<" to head"<<std::endl;
    }
};

#endif