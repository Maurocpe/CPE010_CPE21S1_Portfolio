#ifndef BSTC_H
#define BSTC_H

#include <iostream>

template <typename T>
class BST
{
private:
    T key;
    BST<T>* leftChild;
    BST<T>* rightChild;

public:
    BST(T value)
    {
        key = value;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    void insert(T value)
    {
        if (value < key)
        {
            if (leftChild == nullptr)
            {
                leftChild = new BST<T>(value);
            }
            else
            {
                leftChild->insert(value);
            }
        }
        else if (value > key)
        {
            if (rightChild == nullptr)
            {
                rightChild = new BST<T>(value);
            }
            else
            {
                rightChild->insert(value);
            }
        }
    }

    void inOrder()
    {
        if (leftChild != nullptr)
        {
            leftChild->inOrder();
        }

        std::cout << key << " ";

        if (rightChild != nullptr)
        {
            rightChild->inOrder();
        }
    }

    void preOrder()
    {
        std::cout << key << " ";

        if (leftChild != nullptr)
        {
            leftChild->preOrder();
        }

        if (rightChild != nullptr)
        {
            rightChild->preOrder();
        }
    }

    void postOrder()
    {
        if (leftChild != nullptr)
        {
            leftChild->postOrder();
        }

        if (rightChild != nullptr)
        {
            rightChild->postOrder();
        }

        std::cout << key << " ";
    }
};

#endif