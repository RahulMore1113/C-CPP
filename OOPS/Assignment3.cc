#include <iostream>
#include <string>
using namespace std;

class Publication
{
protected:
    string title;
    float price;

public:
    void add()
    {
        cout << "\nEnter Title of the Publication: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Price of Publication: ";
        cin >> price;
    }

    void display() const
    {
        cout << "\nTitle of Publication: " << title;
        cout << "\nPublication Price: " << price;
    }
};

class Book : public Publication
{
    int page_count;

public:
    void add()
    {
        Publication::add();
        cout << "Enter Page Count of Book: ";
        cin >> page_count;
        while (page_count <= 0)
        {
            cout << "\nInvalid Page Count! Enter again: ";
            cin >> page_count;
        }
    }

    void display() const
    {
        Publication::display();
        cout << "\nPage Count: " << page_count;
    }
};

class Tape : public Publication
{
    float play_time;

public:
    void add()
    {
        Publication::add();
        cout << "Enter Play Duration of the Tape: ";
        cin >> play_time;
        while (play_time <= 0)
        {
            cout << "\nInvalid Play Time! Enter again: ";
            cin >> play_time;
        }
    }

    void display() const
    {
        Publication::display();
        cout << "\nPlay Time: " << play_time << " min";
    }
};

int main()
{
    Book books[10];
    Tape tapes[10];
    int choice, b_count = 0, t_count = 0;

    do
    {
        cout << "\n* * * * PUBLICATION DATABASE SYSTEM * * * * *";
        cout << "\n1. Add Information to Books";
        cout << "\n2. Add Information to Tapes";
        cout << "\n3. Display Books Information";
        cout << "\n4. Display Tapes Information";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (b_count < 10)
                books[b_count++].add();
            else
                cout << "\nBook limit reached!";
            break;
        case 2:
            if (t_count < 10)
                tapes[t_count++].add();
            else
                cout << "\nTape limit reached!";
            break;
        case 3:
            cout << "\n* * * * BOOK PUBLICATION DATABASE SYSTEM * * * *";
            for (int j = 0; j < b_count; j++)
                books[j].display();
            break;
        case 4:
            cout << "\n* * * * TAPE PUBLICATION DATABASE SYSTEM * * * *";
            for (int j = 0; j < t_count; j++)
                tapes[j].display();
            break;
        case 5:
            return 0;
        default:
            cout << "\nInvalid choice! Please try again.";
        }
    } while (true);

    return 0;
}
