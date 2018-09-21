#ifndef LINKED_LIST
#define LINKED_LIST

template <class T>
class Node
{
  private:
    T data;
    Node<T> *next;

  public:
    Node(T data=0, Node<T>* next=0)
    {
        this->data = data;
        this->next = next;
    }

    Node *getNext()
    {
        return this->next;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }

    T getData()
    {
        return data;
    }
};

template <class T>
class LinkedList
{
  private:
    Node<T> *head, *tail;
    int size;

  public:
    LinkedList()
    {
        head = tail = 0;
        size = 0;
    }

    ~LinkedList()
    {
        Node<T> *temp = head;
        while (head != 0)
        {
            head = head->getNext();
            delete temp;
            temp = head;
        }
    }

    void pushAtHead(T data)
    {
        if (head == 0)
        {
            head = tail = new Node<T>(data);
        }
        else
        {
            head = new Node<T>(data, head);
        }
        size++;
    }

    void pushAtTail(T data)
    {
        if (tail == 0)
        {
            head = tail = new Node<T>(data);
        }
        else
        {
            Node<T> *temp = new Node<T>(data);
            tail->setNext(temp);
            tail = temp;
        }
    }

    T popFromHead()
    {
        if (head != 0)
        {
            T data = head->getData();
            Node<T> *temp = head;
            if (head == tail)
            {
                head = tail = 0;
            }
            else
            {
                head = head->getNext();
            }
            delete temp;
            return data;
        }
    }

    T popFromTail()
    {
        if (tail != 0)
        {
            T data = tail->getData();
            if (head == tail)
            {
                delete head;
                head = tail = 0;
            }
            else
            {
                Node<T> *temp;
                for (temp = head; temp->getNext() != tail; temp = temp->getNext())
                    ;
                delete tail;
                tail = temp;
            }
            return data;
        }
    }

    void deleteNode(T data)
    {
        if (head == tail)
        {
            delete head;
            head = tail = 0;
        }
        else if (head->getData() == data)
        {
            Node<T> *temp = head;
            head = head->getNext();
            delete temp;
        }
        else if (tail->getData() == data)
        {
            Node<T> *temp;
            for (temp = head; temp->getNext() != tail; temp = temp->getNext())
                ;
            delete tail;
            tail = temp;
        }
        else
        {
            Node<T> *temp;
            for (temp = head->getNext(); temp->getNext()->getData() != data && temp != tail; temp = temp->getNext())
                ;
            Node<T> *prev = temp;
            temp = temp->getNext();
            prev->setNext(temp->getNext());
            delete temp;
        }
    }
};

#endif
