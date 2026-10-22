#include <iostream>
#include <queue>


void display(std::queue<char> r);


int main() {


    std::queue<char> q;


    q.push('c');
    q.push('p');
    q.push('e');
    q.push('0');
    q.push('1');
    q.push('0');


    // Display
    std::cout << "Initial Queue:";
    display(q);


    // empty()
    std::cout<<"Is the queue empty? "<<q.empty() <<std::endl;

    // size()
    std::cout << "Queue size: " << q.size() << std::endl;

    // front()
    std::cout << "Front element: " << q.front() << std::endl;

    // back()
    std::cout << "Back element: " << q.back() << std::endl;

    // pop()
    std::cout << "\nRemoving the front element...\n";
    q.pop();

    // display
    std::cout << "Queue after pop:";
    display(q);

    // push another element
    std::cout << "\nAdding element 'X'...\n";
    q.push('X');

    // display
    std::cout << "Queue after push:";
    display(q);


    // Delete the queue
    while (!q.empty()) {
        q.pop();
}

std::cout << "Queue deleted.\n";


    // Display after deleting
    std::cout << "Queue after delete:";
    display(q);

    std::cout << "Queue size: " << q.size() << std::endl;

    return 0;
}


void display(std::queue<char> r) {
    // Create a copy of the queue
    std::queue<char> c = r;


    while (!c.empty()) {
        std::cout << " " << c.front();
        c.pop();
    }
    std::cout << std::endl;
}
