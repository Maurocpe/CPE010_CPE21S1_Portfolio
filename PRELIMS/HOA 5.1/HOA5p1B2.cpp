#include <iostream>

class ArrayQueue {
private:
    int* q;
    int capacity;
    int q_front;
    int q_back;
    int q_size;
public:
    // Create an empty queue
    ArrayQueue(int size = 5) {
        capacity = size;
        q = new int[capacity];
        q_front = 0;
        q_back = 0;
        q_size = 0;
    }
    // Copy constructor
    ArrayQueue(const ArrayQueue& other) {
        capacity = other.capacity;
        q_front = other.q_front;
        q_back = other.q_back;
        q_size = other.q_size;

        q = new int[capacity];
        // Copy the whole array
        for (int i = 0; i < capacity; i++) {
            q[i] = other.q[i];
        }
    }
    // Copy assignment
    ArrayQueue& operator=(const ArrayQueue& other) {
        if (this != &other) {
            delete[] q;

            capacity = other.capacity;
            q_front = other.q_front;
            q_back = other.q_back;
            q_size = other.q_size;

            q = new int[capacity];

            // Copy every array position
            for (int i = 0; i < capacity; i++) {
                q[i] = other.q[i];
            }
        }
        return *this;
    }
    // Free the array
    ~ArrayQueue() {
        delete[] q;
    }
    bool Empty() const {
        return q_size == 0;
    }
    int Size() const {
        return q_size;
    }
    void Clear() {
        q_size = 0;
        q_front = 0;
        q_back = 0;
    }
    int Front() const {
        if (Empty()) {
            throw std::runtime_error("Queue is empty.");
        }
        return q[q_front];
    }
    int Back() const {
        if (Empty()) {
            throw std::runtime_error("Queue is empty.");
        }
        // Back points to the next available position
        int index = (q_back - 1 + capacity) % capacity;
        return q[index];
    }
    void Enqueue(int value) {
        if (q_size == capacity) {
            throw std::runtime_error("Queue is full.");
        }
        q[q_back] = value;
        // Move back in a circular way
        q_back = (q_back + 1) % capacity;
        q_size++;
    }
    void Dequeue() {
        if (Empty()) {
            throw std::runtime_error("Queue is empty.");
        }
        // Move front to the next item
        q_front = (q_front + 1) % capacity;
        q_size--;
    }
    void Display() const {
        if (Empty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        for (int i = 0; i < q_size; i++) {
            int index = (q_front + i) % capacity;
            std::cout << q[index] << " ";
        }
        std::cout << "\n";
    }
};
int main() {
    ArrayQueue queue(5);
    // Add some values
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);

    std::cout << "Initial queue: ";
    queue.Display();

    std::cout << "Front: " << queue.Front() << "\n";
    std::cout << "Back: " << queue.Back() << "\n";
    std::cout << "Size: " << queue.Size() << "\n";

    // Remove the front item
    queue.Dequeue();

    std::cout << "\nAfter dequeue: ";
    queue.Display();

    // Add another value
    queue.Enqueue(40);
    queue.Enqueue(50);

    std::cout << "After adding 40 and 50: ";
    queue.Display();

    // Demonstrate the circular array
    queue.Dequeue();
    queue.Enqueue(60);

    std::cout << "After dequeue and adding 60: ";
    queue.Display();

    // Test copy constructor
    ArrayQueue copiedQueue(queue);

    std::cout << "\nCopied queue: ";
    copiedQueue.Display();

    // Test copy assignment
    ArrayQueue assignedQueue;
    assignedQueue = queue;

    std::cout << "Assigned queue: ";
    assignedQueue.Display();

    // Test Clear
    queue.Clear();

    std::cout << "\nAfter Clear(): ";
    queue.Display();

    return 0;
}