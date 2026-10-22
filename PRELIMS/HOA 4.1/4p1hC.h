#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

//Node for Linked List
struct Node {
    char data;
    Node* next;
};

//Array Stack
class ArrayStack {
private:
    char arr[100];
    int top;

public:
    //Start with an empty stack
    ArrayStack() {
        top = -1;
    }

    //Add symbol to the stack
    void push(char c) {
        arr[++top] = c;
    }

    //Remove the top symbol
    char pop() {
        if (top == -1)
            return '\0';

        return arr[top--];
    }

    //Check if the stack is empty
    bool empty() {
        return top == -1;
    }
};

//Linked List Stack
class LinkedStack {
private:
    Node* top;

public:
    //Start with an empty linked stack
    LinkedStack() {
        top = nullptr;
    }

    //Add a new node
    void push(char c) {
        Node* temp = new Node;
        temp->data = c;
        temp->next = top;
        top = temp;
    }

    //Remove the top node
    char pop() {

        if (top == nullptr)
            return '\0';

        Node* temp = top;
        char value = temp->data;

        top = top->next;
        delete temp;

        return value;
    }

    //Check if empty
    bool empty() {
        return top == nullptr;
    }
};

//Check matching symbols
bool match(char open, char close) {

    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

//Balance check using Array Stack
bool balancedArray(const std::string& exp) {

    ArrayStack s;
    for (char ch : exp) {

        //Save opening symbols
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);

        //Check closing symbols
        else if (ch == ')' || ch == '}' || ch == ']') {

            if (s.empty())
                return false;
            char temp = s.pop();

            if (!match(temp, ch))
                return false;
        }
    }

    return s.empty();
}

//Balance check using Linked List Stack
bool balancedLinked(const std::string& exp) {

    LinkedStack s;
    for (char ch : exp) {

        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);

        else if (ch == ')' || ch == '}' || ch == ']') {

            if (s.empty())
                return false;
            char temp = s.pop();

            if (!match(temp, ch))
                return false;
        }
    }

    return s.empty();
}

#endif