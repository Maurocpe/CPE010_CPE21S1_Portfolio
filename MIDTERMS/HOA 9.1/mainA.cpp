#include <iostream>
#include "BSTA.h"

int main() {

    GeneralTree<char> tree;

    // Create the root node
    TreeNode<char>* A = tree.createNode('A');
    tree.setRoot(A);

    // Create nodes B to G
    TreeNode<char>* B = tree.createNode('B');
    TreeNode<char>* C = tree.createNode('C');
    TreeNode<char>* D = tree.createNode('D');
    TreeNode<char>* E = tree.createNode('E');
    TreeNode<char>* F = tree.createNode('F');
    TreeNode<char>* G = tree.createNode('G');

    // Create nodes H to N
    TreeNode<char>* H = tree.createNode('H');
    TreeNode<char>* I = tree.createNode('I');
    TreeNode<char>* J = tree.createNode('J');
    TreeNode<char>* K = tree.createNode('K');
    TreeNode<char>* L = tree.createNode('L');
    TreeNode<char>* M = tree.createNode('M');
    TreeNode<char>* N = tree.createNode('N');

    // Create nodes P and Q
    TreeNode<char>* P = tree.createNode('P');
    TreeNode<char>* Q = tree.createNode('Q');

    // Add B, C, D, E, F, and G as children of A
    tree.addChild(A, B);
    tree.addChild(A, C);
    tree.addChild(A, D);
    tree.addChild(A, E);
    tree.addChild(A, F);
    tree.addChild(A, G);

    // Add H as child of D
    tree.addChild(D, H);

    // Add I and J as children of E
    tree.addChild(E, I);
    tree.addChild(E, J);

    // Add P and Q as children of J
    tree.addChild(J, P);
    tree.addChild(J, Q);

    // Add K, L, and M as children of F
    tree.addChild(F, K);
    tree.addChild(F, L);
    tree.addChild(F, M);

    // Add N as child of G
    tree.addChild(G, N);

    // Display the tree
    std::cout << "General Tree:" << std::endl;
    tree.display();

    return 0;
}