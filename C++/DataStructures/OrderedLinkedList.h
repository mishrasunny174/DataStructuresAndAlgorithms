#ifndef ORDERED_LINKED_LIST_H
#define ORDERED_LINKED_LIST_H
#include <cstdlib>
#include <iostream>

template <typename T>
class OrderedLinkedList;

template <typename T>
class Node
{
    T data;
    Node<T> *next;
    Node(T data, Node<T> *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
    friend class OrderedLinkedList<T>;
};

template <typename T>
class OrderedLinkedList
{
    Node<T> *head;

  public:
    OrderedLinkedList()
    {
        this->head = NULL;
    }
    OrderedLinkedList(const OrderedLinkedList &list)
    {
        head = NULL;
        Node<T> *temp;
        for (temp = list.head; temp != NULL; temp = temp->next)
            this->insert(temp->data);
    }

    void insert(T data)
    {
        Node<T> *temp = head;
        if (head == NULL)
        {
            head = new Node<T>(data);
        }
        else if (head->data > data)
        {
            head = new Node<T>(data, head);
        }
        else
        {
            while (temp->next != NULL && temp->next->data < data)
                temp = temp->next;
            temp->next = new Node<T>(data, temp->next);
        }
    }
    void diplay()
    {
        Node<T> *temp;
        for (temp = head; temp != NULL; temp = temp->next)
            std::cout << temp->data << " ";
        std::cout << std::endl;
    }

    OrderedLinkedList &operator+(const OrderedLinkedList &list)
    {
        Node<T> *itr1 = this->head, *itr2 = list.head;
        OrderedLinkedList<T> *temp = new OrderedLinkedList();
        while (itr1 != NULL)
        {
            temp->insert(itr1->data);
            itr1 = itr1->next;
        }
        while (itr2 != NULL)
        {
            temp->insert(itr2->data);
            itr2 = itr2->next;
        }
        return *temp;
    }

    OrderedLinkedList &operator=(const OrderedLinkedList &list)
    {
        this->head = NULL;
        Node<T> *temp;
        for (temp = list.head; temp != NULL; temp = temp->next)
        {
            this->insert(temp->data);
        }
        return *this;
    }
};

#endif