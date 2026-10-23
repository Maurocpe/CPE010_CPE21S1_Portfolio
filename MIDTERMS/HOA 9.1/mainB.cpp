#include <iostream>
#include "BSTB.h"


int main(){
    //NODE
    BinarySearchTree<int> tree(20);

    tree.insert(30);
    tree.insert(70);
    tree.insert(50);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(10);
    tree.insert(15);

    std::cout << "Pre-order Traversal: ";
    tree.preOrder();
    std::cout << std::endl;
    std::cout << "In-order Traversal: ";
    tree.inOrder();
    std::cout << std::endl;
    std::cout << "Post-order Traversal: ";
    tree.postOrder();
    std::cout << std::endl;     

    return 0;
}