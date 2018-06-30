#ifndef AVLTREE_H
#define AVLTREE_H

#include <cmath>
#include <iostream>

template <class T>
class Node
{
    T data;
    Node<T> *leftChild;
    Node<T> *rightChild;
    int balance;
    template <class D>
    friend class AVLTree;

  public:
    Node(T data)
    {
        this->data = data;
        this->leftChild = 0;
        this->rightChild = 0;
        this->balance = 0;
    }
};

template <class D>
class AVLTree
{
    Node<D> *root;

  public:
    AVLTree()
    {
        root = 0;
    }
    void insert(D data)
    {
        if (this->root == 0)
            this->root = new Node<D>(data);
        else
            this->root = this->insert(this->root, data);
    }

    void traverseInOrder()
    {
        if (this->root == 0)
        {
            std::cerr << "ERROR: tree is empty" << std::endl;
        }
        else
        {
            this->traverseInOrder(this->root);
        }
    }

    void remove(D data)
    {
        if(root == 0)
        {
            std::cerr<<"ERROR: tree is empty"<<std::endl;
        }
        else
        {
            this->root = this->remove(this->root, data);
        }
    }
  protected:
    Node<D> *insert(Node<D> *node, D data)
    {
        if (data < node->data)
        {
            if (node->leftChild == 0)
                node->leftChild = new Node<D>(data);
            else
                node->leftChild = this->insert(node->leftChild, data);
        }
        else
        {
            if (node->rightChild == 0)
                node->rightChild = new Node<D>(data);
            else
                node->rightChild = this->insert(node->rightChild, data);
        }
        node = this->balanceTree(node);
        return node;
    }

    Node<D> *balanceTree(Node<D> *node)
    {
        this->calculateBalance(node);
        if (node->balance > 1)
        {
            if (node->rightChild->balance == 1)
            {
                node = this->rotateLeft(node);
            }
            else if(node->rightChild->balance==-1)
            {
                node->rightChild = this->rotateRight(node->rightChild);
                node = this->rotateLeft(node);
            }
        }
        else if (node->balance < -1)
        {
            if (node->leftChild->balance == -1)
            {
                node = this->rotateRight(node);
            }
            else if(node->leftChild->balance == 1)
            {
                node->leftChild = this->rotateLeft(node->leftChild);
                node = this->rotateRight(node);
            }
        }
        return node;
    }

    void calculateBalance(Node<D> *node)
    {
        node->balance = this->calculateHeight(node->rightChild) - this->calculateHeight(node->leftChild);
    }

    int calculateHeight(Node<D> *node)
    {
        if (node == 0)
            return -1;
        return std::max(this->calculateHeight(node->leftChild), this->calculateHeight(node->rightChild)) + 1;
    }

    Node<D> *rotateLeft(Node<D> *node)
    {
        Node<D> *temp = node->rightChild;
        node->rightChild = temp->leftChild;
        temp->leftChild = node;
        return temp;
    }

    Node<D> *rotateRight(Node<D> *node)
    {
        Node<D> *temp = node->leftChild;
        node->leftChild = temp->rightChild;
        temp->rightChild = node;
        return temp;
    }

    void traverseInOrder(Node<D> *node)
    {
        if (node != 0)
        {
            if (node->leftChild != 0)
                this->traverseInOrder(node->leftChild);
            std::cout << node->data << std::endl;
            if (node->rightChild != 0)
                this->traverseInOrder(node->rightChild);
        }
    }

    Node<D> *remove(Node<D> *node, D data)
    {
        if(data < node->data)
        {
            node->leftChild = this->remove(node->leftChild, data);
        }
        else if(data > node->data)
        {
            node->rightChild = this->remove(node->rightChild, data);
        }
        else
        {
            if (node->leftChild == 0)
            {
                node = node->rightChild;
            }
            else if(node->rightChild == 0)
            {
                node = node->leftChild;
            }
            else
            {
                node->data = this->getMaximum(node->leftChild);
                node->leftChild = this->remove(node->leftChild, node->data);
            }
        }
        if(node != 0)
            node = this->balanceTree(node);
        return node;
    }

    D getMaximum(Node<D> *node)
    {
        if(node->rightChild == 0)
            return node->data;
        return this->getMaximum(node->rightChild);
    }
};

#endif