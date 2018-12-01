#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <queue>
#include <stack>
#include <iostream>
template <class T>
class BST;

template <class T>
class Node
{
    T data;
    Node *left;
    Node *right;
    template <class P>
    friend class BST;

  public:
    Node()
    {
        this->data = 0;
        this->left = 0;
        this->right = 0;
    }
    Node(T data, Node *left = 0, Node *right = 0)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <class T>
class BST
{
    Node<T> *root;
    int size;

  public:
    BST()
    {
        size = 0;
        root = 0;
    }

    ~BST()
    {
        clear(root);
    }

    void insert(T data)
    {
        if (root == 0)
            root = new Node<T>(data);
        else
            insert(root, data);
    }

    T *search(T data)
    {
        return search(root, data);
    }

    void inorderTraversal()
    {
        inorderTraversal(root);
    }

    void preorderTravesal()
    {
        preorderTravesal(root);
    }

    void postorderTraversal()
    {
        postorderTraversal(root);
    }

    void iterativeInorderTraversal()
    {
        std::stack<Node<T> *> stck;
        Node<T> *temp = root;
        while (temp != 0)
        {
            while (temp != 0)
            {
                if (temp->right != 0)
                    stck.push(temp->right);
                stck.push(temp);
                temp = temp->left;
            }
            temp = stck.top();
            stck.pop();
            while (!stck.empty() && temp->right == 0)
            {
                visit(temp);
                temp = stck.top();
                stck.pop();
            }
            visit(temp);
            if (!stck.empty())
            {
                temp = stck.top();
                stck.pop();
            }
            else
            {
                temp = 0;
            }
        }
    }

    void iterativePostorderTraversal()
    {
        std::stack<Node<T> *> stck;
        Node<T> *p = root, *q;
        while (p != 0)
        {
            for (; p->left != 0; p = p->left)
                stck.push(p);
            while (p->right == 0 || p->right == q)
            {
                visit(p);
                q = p;
                if (stck.empty())
                {
                    return;
                }
                p = stck.top();
                stck.pop();
            }
            stck.push(p);
            p = p->right;
        }
    }

    void iterativePreorderTraversal()
    {
        std::stack<Node<T> *> stck;
        Node<T> *temp = root;
        if (root != 0)
        {
            stck.push(temp);
            while (!stck.empty())
            {
                temp = stck.top();
                stck.pop();
                visit(temp);
                if (temp->right != 0)
                    stck.push(temp->right);
                if (temp->left != 0)
                    stck.push(temp->left);
            }
        }
    }

    void morisInorderTraversal()
    {
        Node<T> *p, *q;
        p = root;
        while (p != 0)
        {
            if (p->left == 0)
            {
                visit(p);
                p = p->right;
            }
            else
            {
                q = p->left;
                while (q->right != 0 && q->right != p)
                {
                    q = q->right;
                }
                if (q->right == 0)
                {
                    q->right = p;
                    p = p->left;
                }
                else
                {
                    visit(p);
                    q->right = 0;
                    p = p->right;
                }
            }
        }
    }

    void breadthFirstTraversal()
    {
        std::queue<Node<T> *> q;
        Node<T> *temp = root;
        if (temp != 0)
        {
            q.push(temp);
            while (!q.empty())
            {
                temp = q.front();
                q.pop();
                visit(temp);
                if (temp->left != 0)
                    q.push(temp->left);
                if (temp->right != 0)
                    q.push(temp->right);
            }
        }
    }

    void findAndDeleteByMerging(T data)
    {
        Node<T> *temp = root, *prev = 0;
        while (temp != 0)
        {
            if (temp->data == data)
                break;
            prev = temp;
            if (data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (temp != 0 && temp->data == data)
        {
            if(temp == root)
                deleteByMerging(root);
            else if(temp->left == temp)
                deleteByMerging(prev->left);
            else
                deleteByMerging(prev->right);
        }
        else if (root != 0)
        {
            std::cout << "Element not found in tree" << std::endl;
        }
        else
        {
            std::cout << "Tree is empty" << std::endl;
        }
    }

    void findAndDeleteByCopying(T data)
    {
        Node<T> *temp = root, *prev = 0;
        while (temp != 0)
        {
            if (temp->data == data)
                break;
            prev = temp;
            if (data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (temp != 0 && temp->data == data)
        {
            if(temp == root)
                deleteByCopying(root);
            else if(temp->left == temp)
                deleteByCopying(prev->left);
            else
                deleteByCopying(prev->right);
        }
        else if (root != 0)
        {
            std::cout << "Element not found in tree" << std::endl;
        }
        else
        {
            std::cout << "Tree is empty" << std::endl;
        }
    }

    int countLeaves()
    {
        return countLeaves(this->root);
    }

  protected:
    void insert(Node<T> *node, T data)
    {
        if (data < node->data)
        {
            if (node->left == 0)
                node->left = new Node<T>(data);
            else
                insert(node->left, data);
        }
        else
        {
            if (node->right == 0)
                node->right = new Node<T>(data);
            else
                insert(node->right, data);
        }
    }

    void deleteByMerging(Node<T> *&node)
    {
        Node<T>* temp = node;
        if (node != 0)
        {
            if (node->left == 0)
            {
                node = node->right;
            }
            else if (node->right == 0)
            {
                node = node->left;
            }
            else
            {
                temp = node->left;
                while (temp->right != 0)
                    temp = temp->right;
                temp->right = node->right;
                temp = node;
                node = node->left;
            }
            delete temp;
        }
    }

    void deleteByCopying(Node<T> *&node)
    {
        Node<T> *temp = node, *prev = 0;
        if(node->left == 0)
        {
            node = node->right;
        }
        else if(node->right == 0)
        {
            node = node->left;
        }
        else
        {
            temp = node->left;
            prev = node;
            while(temp->right!=0)
            {
                prev = temp;
                temp = temp->right;
            }
            node->data = temp->data;
            if(prev == node)
                prev->left = temp->left;
            else
                prev->right = temp->left;
        }
    }

    T *search(Node<T> node, T data)
    {
        Node<T> *temp = node;
        while (temp != 0)
        {
            if (temp->data == data)
                return &temp->data;
            else if (data < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return 0; //if not found return null pointe return root->search(data);
    }

    void clear(Node<T> *node)
    {
        if (node->left != 0)
            clear(node->left);
        if (node->right != 0)
            clear(node->right);
        delete node;
    }

    void visit(Node<T> *node)
    {
        std::cout << node->data << std::endl;
    }

    void inorderTraversal(Node<T> *node)
    {
        if (node != 0)
        {
            inorderTraversal(node->left);
            visit(node);
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(Node<T> *node)
    {
        if (node != 0)
        {
            visit(node);
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(Node<T> *node)
    {
        if (node != 0)
        {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            visit(node);
        }
    }

    int countLeaves(Node<T>* root)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }
};

#endif