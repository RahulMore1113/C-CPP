#include <iostream>
#include <string>
using namespace std;

class PizzaParlor
{
private:
    string *queue;   // Array to hold the orders
    int front, rear; // Pointers for front and rear of the queue
    int size;        // Current number of orders in the queue
    int capacity;    // Maximum number of orders (M)

public:
    // Constructor to initialize the queue with a maximum size M
    PizzaParlor(int M)
    {
        capacity = M;
        queue = new string[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor to free the allocated memory
    ~PizzaParlor()
    {
        delete[] queue;
    }

    // Function to add an order to the queue
    void enqueue(string order)
    {
        if (size == capacity)
        {
            cout << "Queue is full! Cannot accept more orders." << endl;
            return;
        }
        if (rear == -1)
        {
            // If the queue is empty, both front and rear will be set to 0
            front = rear = 0;
        }
        else
        {
            // Circular increment
            rear = (rear + 1) % capacity;
        }
        queue[rear] = order;
        size++;
        cout << "Order placed: " << order << endl;
    }

    // Function to serve (dequeue) an order
    void dequeue()
    {
        if (size == 0)
        {
            cout << "No orders to serve." << endl;
            return;
        }
        cout << "Serving order: " << queue[front] << endl;
        // If only one element was in the queue
        if (front == rear)
        {
            front = rear = -1; // Queue becomes empty
        }
        else
        {
            // Circular increment
            front = (front + 1) % capacity;
        }
        size--;
    }

    // Function to display current orders in the queue
    void display()
    {
        if (size == 0)
        {
            cout << "No orders in the queue." << endl;
            return;
        }
        cout << "Current orders in the queue: ";
        int i = front;
        for (int count = 0; count < size; count++)
        {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    // Function to get the number of orders in the queue
    int getSize()
    {
        return size;
    }
};

int main()
{
    int M;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    PizzaParlor parlor(M);

    int choice;
    string order;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Place an order\n";
        cout << "2. Serve an order\n";
        cout << "3. Display current orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Place an order
            cout << "Enter the order description: ";
            cin.ignore(); // To clear the input buffer
            getline(cin, order);
            parlor.enqueue(order);
            break;
        case 2:
            // Serve an order
            parlor.dequeue();
            break;
        case 3:
            // Display current orders
            parlor.display();
            break;
        case 4:
            // Exit
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
