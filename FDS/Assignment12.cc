#include <iostream>
using namespace std;

class Deque
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor to initialize the deque
    Deque(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor to release memory
    ~Deque()
    {
        delete[] arr;
    }

    // Check if the deque is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Check if the deque is full
    bool isFull()
    {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    // Add element at the front
    void addFront(int x)
    {
        if (isFull())
        {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1)
        { // If deque is empty, set both front and rear to 0
            front = rear = 0;
        }
        else if (front == 0)
        { // If front is at the beginning, wrap around
            front = capacity - 1;
        }
        else
        { // Move front backwards
            front--;
        }
        arr[front] = x;
    }

    // Add element at the rear
    void addRear(int x)
    {
        if (isFull())
        {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1)
        { // If deque is empty, set both front and rear to 0
            front = rear = 0;
        }
        else if (rear == capacity - 1)
        { // If rear is at the end, wrap around
            rear = 0;
        }
        else
        { // Move rear forward
            rear++;
        }
        arr[rear] = x;
    }

    // Delete element from the front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        if (front == rear)
        {                      // If there's only one element
            front = rear = -1; // Reset deque
        }
        else if (front == capacity - 1)
        { // Wrap around
            front = 0;
        }
        else
        {
            front++;
        }
    }

    // Delete element from the rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        if (front == rear)
        {                      // If there's only one element
            front = rear = -1; // Reset deque
        }
        else if (rear == 0)
        { // Wrap around
            rear = capacity - 1;
        }
        else
        {
            rear--;
        }
    }

    // Display the elements of the deque
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main()
{
    // Create a deque with capacity of 5
    Deque dq(5);

    // Add elements to the front and rear
    dq.addRear(10);
    dq.addRear(20);
    dq.addFront(5);
    dq.addFront(1);
    dq.addRear(30); // This should work

    cout << "Deque elements: ";
    dq.display();

    // Try adding more elements to see if it handles the full case
    dq.addFront(50); // This should show "Deque is full!"

    // Remove elements from front and rear
    dq.deleteFront();
    dq.deleteRear();

    cout << "Deque elements after deletions: ";
    dq.display();

    // Try deleting from an empty deque
    dq.deleteFront();
    dq.deleteFront();
    dq.deleteFront();
    dq.deleteFront(); // Should show "Deque is empty!"

    return 0;
}
