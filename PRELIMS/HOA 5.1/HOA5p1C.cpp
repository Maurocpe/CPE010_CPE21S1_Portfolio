#include <iostream>
#include <string>

class Job {
private:
    int jobID;
    std::string userName;
    int pages;
public:
    // Constructor
    Job(int id = 0, std::string name = "", int pageCount = 0) {
        jobID = id;
        userName = name;
        pages = pageCount;
    }

    // Display job information
    void Display() const {
        std::cout << "Job ID: " << jobID
                  << " | User: " << userName
                  << " | Pages: " << pages << "\n";
    }
};
class Printer {
private:
    Job* jobs;
    int capacity;
    int front;
    int back;
    int size;
public:
    // Constructor
    Printer(int maxJobs = 10) {
        capacity = maxJobs;
        jobs = new Job[capacity];
        front = 0;
        back = 0;
        size = 0;
    }
    // Destructor
    ~Printer() {
        delete[] jobs;
    }
    // Check if the printer queue is empty
    bool Empty() const {
        return size == 0;
    }
    // Add a new print job
    void AddJob(const Job& job) {
        if (size == capacity) {
            std::cout << "Printer queue is full.\n";
            return;
        }
        jobs[back] = job;
        back = (back + 1) % capacity;
        size++;
        std::cout << "Job added to printer queue.\n";
    }

    // Process the first job in the queue
    void ProcessJob() {
        if (Empty()) {
            std::cout << "No jobs to process.\n";
            return;
        }
        std::cout << "Processing: ";
        jobs[front].Display();
        front = (front + 1) % capacity;
        size--;
    }

    // Process all remaining jobs
    void ProcessAllJobs() {
        std::cout << "\nProcessing all remaining jobs:\n";
        while (!Empty()) {
            ProcessJob();
        }
    }
    // Display all pending jobs
    void DisplayQueue() const {
        if (Empty()) {
            std::cout << "Printer queue is empty.\n";
            return;
        }
        std::cout << "Pending printer jobs:\n";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            jobs[index].Display();
        }
    }
};
int main() {
    Printer printer(5);

    // Add multiple print jobs
    std::cout << "\n--- Adding Print Jobs ---\n";

    Job job1(101, "Ryan", 5);
    Job job2(102, "Lewis", 10);
    Job job3(103, "Bibiano", 3);
    Job job4(104, "Mauro", 8);

    printer.AddJob(job1);
    printer.AddJob(job2);
    printer.AddJob(job3);
    printer.AddJob(job4);

    // Display pending jobs
    std::cout << "\n--- Current Printer Queue ---\n";
    printer.DisplayQueue();

    // Process jobs one by one
    std::cout << "\n--- Processing Jobs ---\n";

    printer.ProcessJob();
    printer.ProcessJob();

    // Display remaining jobs
    std::cout << "\n--- Remaining Jobs ---\n";
    printer.DisplayQueue();

    // Add another job
    std::cout << "\n--- Adding New Job ---\n";

    Job job5(105, "RyMauro", 6);
    printer.AddJob(job5);

    printer.DisplayQueue();

    // Process all remaining jobs
    printer.ProcessAllJobs();

    std::cout << "\n--- Final Queue ---\n";
    printer.DisplayQueue();

    return 0;
}