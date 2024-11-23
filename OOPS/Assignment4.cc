#include <iostream>
#include <fstream>
using namespace std;

class Employee // declaring class Employee
{
    string Name;
    int ID;
    double salary;

public:
    void accept()
    {
        cout << "\nName: ";
        cin.ignore();
        getline(cin, Name);
        cout << "ID: ";
        cin >> ID;
        cout << "Salary: ";
        cin >> salary;
    }

    void display()
    {
        cout << "\nName: " << Name;
        cout << "\nID: " << ID;
        cout << "\nSalary: " << salary << endl;
    }

    // Adding serialization methods
    void writeToFile(fstream &f)
    {
        size_t nameLength = Name.size();
        f.write(reinterpret_cast<char *>(&nameLength), sizeof(nameLength));
        f.write(Name.c_str(), nameLength);
        f.write(reinterpret_cast<char *>(&ID), sizeof(ID));
        f.write(reinterpret_cast<char *>(&salary), sizeof(salary));
    }

    void readFromFile(fstream &f)
    {
        size_t nameLength;
        f.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength));
        Name.resize(nameLength);
        f.read(&Name[0], nameLength);
        f.read(reinterpret_cast<char *>(&ID), sizeof(ID));
        f.read(reinterpret_cast<char *>(&salary), sizeof(salary));
    }
};

int main()
{
    Employee o[5];
    int n;

    fstream f;
    f.open("demo2.txt", ios::out | ios::binary);
    cout << "\nEnter the number of employees you want to store (max 5): ";
    cin >> n;

    if (n > 5)
    {
        cout << "Maximum number of employees is 5. Setting to 5." << endl;
        n = 5;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter information of Employee " << i + 1 << "\n";
        o[i].accept();
        o[i].writeToFile(f);
    }
    f.close();

    f.open("demo2.txt", ios::in | ios::binary);
    cout << "\nInformation of Employees is as follows:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nEmployee " << i + 1 << "\n";
        o[i].readFromFile(f);
        o[i].display();
    }
    f.close();

    return 0;
}
