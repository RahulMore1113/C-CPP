#include <iostream>
#include <string>
using namespace std;

struct Member
{
    string prn;
    string name;
    Member *next;

    Member(string prn, string name)
    {
        this->prn = prn;
        this->name = name;
        this->next = nullptr;
    }
};

class Club
{
private:
    Member *head; // Head points to the president
    Member *tail; // Tail points to the secretary

public:
    Club() : head(nullptr), tail(nullptr) {}

    // Function to add a member to the club
    void addMember(string prn, string name)
    {
        Member *newMember = new Member(prn, name);
        if (!head)
        { // If the list is empty, new member becomes both head and tail
            head = tail = newMember;
        }
        else
        {
            tail->next = newMember;
            tail = newMember;
        }
    }

    // Function to delete a member by PRN
    void deleteMember(string prn)
    {
        if (!head)
        {
            cout << "The list is empty. No member to delete." << endl;
            return;
        }

        // If the member to be deleted is the first (President)
        if (head->prn == prn)
        {
            Member *temp = head;
            head = head->next;
            delete temp;
            if (!head)
            { // If list becomes empty after deletion
                tail = nullptr;
            }
            cout << "Member with PRN " << prn << " deleted." << endl;
            return;
        }

        Member *current = head;
        Member *prev = nullptr;

        // Traverse the list to find the member with the given PRN
        while (current != nullptr && current->prn != prn)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Member with PRN " << prn << " not found." << endl;
            return;
        }

        // If the member is found, remove it
        prev->next = current->next;
        if (current == tail)
        { // If the member is the last (Secretary)
            tail = prev;
        }
        delete current;
        cout << "Member with PRN " << prn << " deleted." << endl;
    }

    // Function to display all members in the club
    void displayMembers()
    {
        if (!head)
        {
            cout << "No members in the club." << endl;
            return;
        }

        Member *current = head;
        while (current != nullptr)
        {
            cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    // Function to compute the total number of members in the club
    int getTotalMembers()
    {
        int count = 0;
        Member *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    // Function to concatenate two lists (representing two divisions)
    void concatenateLists(Club &other)
    {
        if (other.head == nullptr)
        {
            cout << "Second list is empty, nothing to concatenate." << endl;
            return;
        }

        if (head == nullptr)
        {
            head = other.head;
            tail = other.tail;
        }
        else
        {
            tail->next = other.head;
            tail = other.tail;
        }
        other.head = other.tail = nullptr; // Clear the second list after concatenation
    }

    // Destructor to free memory
    ~Club()
    {
        Member *current = head;
        while (current != nullptr)
        {
            Member *temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main()
{
    Club division1, division2;

    // Adding members to division1
    division1.addMember("A123", "Alice");
    division1.addMember("A124", "Bob");
    division1.addMember("A125", "Charlie");

    // Adding members to division2
    division2.addMember("B123", "David");
    division2.addMember("B124", "Eva");

    cout << "Division 1 Members:" << endl;
    division1.displayMembers();
    cout << "Total Members in Division 1: " << division1.getTotalMembers() << endl;

    cout << "\nDivision 2 Members:" << endl;
    division2.displayMembers();
    cout << "Total Members in Division 2: " << division2.getTotalMembers() << endl;

    // Concatenating division2 into division1
    division1.concatenateLists(division2);
    cout << "\nAfter concatenation:" << endl;
    division1.displayMembers();
    cout << "Total Members after concatenation: " << division1.getTotalMembers() << endl;

    // Deleting a member
    cout << "\nDeleting member with PRN A124 (Bob):" << endl;
    division1.deleteMember("A124");
    division1.displayMembers();
    cout << "Total Members after deletion: " << division1.getTotalMembers() << endl;

    return 0;
}
