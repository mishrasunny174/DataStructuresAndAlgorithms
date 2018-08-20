#ifndef CIRCULAR_LINKED_LIST
#define CIRCULAR_LINKED_LIST

template <class T>
class node
{
    T data;
    node *prev;
    node *next;
    template <class P>
    friend class CircularList;
public:
    node(T data,node* prev=-1,node* next=-1)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

template <class T>
class CircularList
{
    node<T> *head,*tail;
};

#endif