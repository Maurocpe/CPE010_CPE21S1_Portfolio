#ifndef BSTA_H
#define BSTA_H

#include <iostream>

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* firstChild;
    TreeNode<T>* nextSibling;

    TreeNode(T value) {
        data = value;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

template <typename T>
class GeneralTree {
private:
    TreeNode<T>* root;

    void displayTree(TreeNode<T>* node, int level) {
        if (node == nullptr)
            return;

        for (int i = 0; i < level; i++)
            std::cout << "  ";

        std::cout << node->data << std::endl;

        displayTree(node->firstChild, level + 1);
        displayTree(node->nextSibling, level);
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    TreeNode<T>* createNode(T value) {
        return new TreeNode<T>(value);
    }

    void setRoot(TreeNode<T>* node) {
        root = node;
    }

    TreeNode<T>* getRoot() {
        return root;
    }

    void addChild(TreeNode<T>* parent, TreeNode<T>* child) {
        if (parent == nullptr || child == nullptr)
            return;

        if (parent->firstChild == nullptr) {
            parent->firstChild = child;
        }
        else {
            TreeNode<T>* current = parent->firstChild;

            while (current->nextSibling != nullptr) {
                current = current->nextSibling;
            }

            current->nextSibling = child;
        }
    }

    void display() {
        displayTree(root, 0);
    }
};

#endif