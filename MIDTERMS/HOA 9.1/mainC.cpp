#include <iostream>
#include "BSTC.h"

int main()
{
    BST<int> tree(2);

    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    std::cout << "In-order Traversal: ";
    tree.inOrder();
    std::cout << std::endl;

    std::cout << "Pre-order Traversal: ";
    tree.preOrder();
    std::cout << std::endl;

    std::cout << "Post-order Traversal: ";
    tree.postOrder();
    std::cout << std::endl;

    return 0;
}



                //   2
              //   /   \
             //   0     3
             //    \     \
              //    1     9
             //          / \
              //        4   18
               //        \
                //        5

                // Pre-order = 2, 0, 1, 3, 9, 4, 5, 18
                // In-order = 0, 1, 2, 3, 4, 5, 9, 18
                // Post-order = 1, 0, 5, 4, 18, 9, 3, 2