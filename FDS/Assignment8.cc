#include <iostream>
#include <unordered_set>

using namespace std;

// Node structure to represent a student
struct Node
{
    int studentID; // Assuming student ID is an integer
    Node *next;

    Node(int id) : studentID(id), next(nullptr) {}
};

// Function to insert a student into the linked list
void insert(Node *&head, int studentID)
{
    Node *newNode = new Node(studentID);
    newNode->next = head;
    head = newNode;
}

// Function to display the linked list of students
void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->studentID << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to convert linked list to unordered set
unordered_set<int> toSet(Node *head)
{
    unordered_set<int> studentSet;
    Node *temp = head;
    while (temp != nullptr)
    {
        studentSet.insert(temp->studentID);
        temp = temp->next;
    }
    return studentSet;
}

// Function to compute the intersection (students who like both vanilla and butterscotch)
unordered_set<int> intersection(Node *list1, Node *list2)
{
    unordered_set<int> set1 = toSet(list1);
    unordered_set<int> set2 = toSet(list2);
    unordered_set<int> result;

    for (int id : set1)
    {
        if (set2.find(id) != set2.end())
        {
            result.insert(id);
        }
    }
    return result;
}

// Function to compute the symmetric difference (students who like either but not both)
unordered_set<int> symmetricDifference(Node *list1, Node *list2)
{
    unordered_set<int> set1 = toSet(list1);
    unordered_set<int> set2 = toSet(list2);
    unordered_set<int> result;

    // Students who like only vanilla
    for (int id : set1)
    {
        if (set2.find(id) == set2.end())
        {
            result.insert(id);
        }
    }

    // Students who like only butterscotch
    for (int id : set2)
    {
        if (set1.find(id) == set1.end())
        {
            result.insert(id);
        }
    }

    return result;
}

// Function to compute the number of students who like neither vanilla nor butterscotch
int countNeither(Node *list1, Node *list2, unordered_set<int> &allStudents)
{
    unordered_set<int> set1 = toSet(list1);
    unordered_set<int> set2 = toSet(list2);
    int count = 0;

    // Students who are in the set of all students but not in either vanilla or butterscotch
    for (int id : allStudents)
    {
        if (set1.find(id) == set1.end() && set2.find(id) == set2.end())
        {
            count++;
        }
    }

    return count;
}

int main()
{
    Node *vanillaStudents = nullptr;      // Set A: Students who like vanilla
    Node *butterscotchStudents = nullptr; // Set B: Students who like butterscotch

    // Example data for students (can be replaced with user input)
    insert(vanillaStudents, 1);
    insert(vanillaStudents, 2);
    insert(vanillaStudents, 3);
    insert(vanillaStudents, 5);

    insert(butterscotchStudents, 2);
    insert(butterscotchStudents, 3);
    insert(butterscotchStudents, 4);
    insert(butterscotchStudents, 6);

    // Display the sets of students
    cout << "Students who like Vanilla Ice Cream: ";
    display(vanillaStudents);

    cout << "Students who like Butterscotch Ice Cream: ";
    display(butterscotchStudents);

    // Set of students who like both vanilla and butterscotch
    unordered_set<int> both = intersection(vanillaStudents, butterscotchStudents);
    cout << "Students who like both Vanilla and Butterscotch: ";
    for (int id : both)
    {
        cout << id << " ";
    }
    cout << endl;

    // Set of students who like either vanilla or butterscotch, but not both
    unordered_set<int> eitherNotBoth = symmetricDifference(vanillaStudents, butterscotchStudents);
    cout << "Students who like either Vanilla or Butterscotch, but not both: ";
    for (int id : eitherNotBoth)
    {
        cout << id << " ";
    }
    cout << endl;

    // Assuming all students are numbered 1 through 6 (example)
    unordered_set<int> allStudents = {1, 2, 3, 4, 5, 6};

    // Number of students who like neither vanilla nor butterscotch
    int neitherCount = countNeither(vanillaStudents, butterscotchStudents, allStudents);
    cout << "Number of students who like neither Vanilla nor Butterscotch: " << neitherCount << endl;

    return 0;
}
