#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Item
{
public:
    char name[10];
    int quantity, cost, code;

    bool operator==(const Item &i) const { return code == i.code; }
    bool operator<(const Item &i) const { return cost < i.cost; }
};

vector<Item> items;

void insert()
{
    Item i;
    cout << "\nEnter Item Name: ";
    cin >> i.name;
    cout << "Enter Item Quantity: ";
    cin >> i.quantity;
    cout << "Enter Item Cost: ";
    cin >> i.cost;
    cout << "Enter Item Code: ";
    cin >> i.code;
    items.push_back(i);
}

void display()
{
    for (const auto &i : items)
    {
        cout << "\nItem Name: " << i.name
             << "\nItem Quantity: " << i.quantity
             << "\nItem Cost: " << i.cost
             << "\nItem Code: " << i.code << "\n";
    }
}

void search()
{
    Item i;
    cout << "\nEnter Item Code to search: ";
    cin >> i.code;
    auto it = find(items.begin(), items.end(), i);
    cout << (it != items.end() ? "\nFound!!!" : "\nNot found!!!");
}

void dlt()
{
    Item i;
    cout << "\nEnter Item Code to delete: ";
    cin >> i.code;
    auto it = find(items.begin(), items.end(), i);
    if (it != items.end())
    {
        items.erase(it);
        cout << "\nDeleted!!!";
    }
    else
    {
        cout << "\nNot found!!!";
    }
}

int main()
{
    int ch;
    do
    {
        cout << "\n* * * Menu * * *\n1. Insert\n2. Display\n3. Search\n4. Sort\n5. Delete\n6. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            sort(items.begin(), items.end());
            display();
            break; // Sort by default less than operator
        case 5:
            dlt();
            break;
        case 6:
            exit(0);
        default:
            cout << "\nInvalid choice.";
        }
    } while (ch != 6);
    return 0;
}
