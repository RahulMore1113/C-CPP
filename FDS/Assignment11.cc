#include <iostream>
#include <string>
using namespace std;

// Define the structure for each job in the queue
struct Job
{
    int jobID;      // Unique identifier for the job
    string jobName; // Name or description of the job
    Job *next;      // Pointer to the next job in the queue
};

// Define the class for the JobQueue
class JobQueue
{
private:
    Job *front; // Pointer to the front of the queue
    Job *rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    JobQueue() : front(nullptr), rear(nullptr) {}

    // Function to add a job to the queue (enqueue)
    void addJob(int jobID, const string &jobName)
    {
        Job *newJob = new Job{jobID, jobName, nullptr}; // Create a new job

        if (rear == nullptr)
        {                          // If the queue is empty
            front = rear = newJob; // Both front and rear point to the new job
        }
        else
        {
            rear->next = newJob; // Link the new job at the end of the queue
            rear = newJob;       // Update rear to point to the new job
        }
        cout << "Job added: " << jobName << " (Job ID: " << jobID << ")\n";
    }

    // Function to remove a job from the queue (dequeue)
    void deleteJob()
    {
        if (front == nullptr)
        { // If the queue is empty
            cout << "No jobs to process. The queue is empty.\n";
            return;
        }

        Job *temp = front;   // Temporary pointer to hold the front job
        front = front->next; // Move front to the next job in the queue

        if (front == nullptr)
        {                   // If the queue is now empty
            rear = nullptr; // Set rear to nullptr
        }

        cout << "Job processed: " << temp->jobName << " (Job ID: " << temp->jobID << ")\n";
        delete temp; // Free the memory for the processed job
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Function to display all jobs in the queue
    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty.\n";
            return;
        }

        Job *temp = front;
        cout << "Jobs in the queue:\n";
        while (temp != nullptr)
        {
            cout << "Job ID: " << temp->jobID << ", Job Name: " << temp->jobName << "\n";
            temp = temp->next;
        }
    }
};

// Main function to test the JobQueue class
int main()
{
    JobQueue queue; // Create a JobQueue object

    // Add some jobs to the queue
    queue.addJob(1, "Job 1: Print document");
    queue.addJob(2, "Job 2: Compile code");
    queue.addJob(3, "Job 3: Backup data");

    // Display the jobs in the queue
    queue.displayQueue();

    // Process (delete) jobs from the queue
    queue.deleteJob(); // Process the first job
    queue.deleteJob(); // Process the second job

    // Display the remaining jobs
    queue.displayQueue();

    // Add a new job to the queue
    queue.addJob(4, "Job 4: Send email");

    // Display the final state of the queue
    queue.displayQueue();

    return 0;
}
