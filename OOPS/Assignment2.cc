#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Data
{
    string address;
    long *telephone, *dl_no;

public:
    Data() : address(""), telephone(new long), dl_no(new long) {}
    ~Data()
    {
        delete telephone;
        delete dl_no;
    }
    void input()
    {
        cout << "Contact Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Mobile Phone Number: ";
        cin >> *telephone;
        cout << "Driving License Number: ";
        cin >> *dl_no;
    }
    void display() const
    {
        cout << "Address: " << address << "\nMobile: " << *telephone << "\nDL No: " << *dl_no << endl;
    }
};

class Student
{
    string name, className, division, dob, bloodGroup;
    int roll;
    static int count;

public:
    Student() { count++; }
    ~Student() {}
    static int get_count() { return count; }
    void input(Data *data)
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Class: ";
        cin.ignore();
        getline(cin, className);
        cout << "Enter Division: ";
        getline(cin, division);
        cout << "Enter DOB (dd/mm/yyyy): ";
        getline(cin, dob);
        cout << "Enter Blood Group: ";
        getline(cin, bloodGroup);
        data->input();
    }
    void display(Data *data) const
    {
        cout << "Name: " << name << "\nRoll: " << roll << "\nClass: " << className
             << "\nDivision: " << division << "\nDOB: " << dob << "\nBlood: " << bloodGroup << endl;
        data->display();
        cout << "----------------------------------" << endl;
    }
};

int Student::count = 0;

int main()
{
    vector<Student *> students;
    vector<Data *> data_records;
    int choice;

    do
    {
        cout << "MENU\n1. New Student\n2. View Database\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Student *newStudent = new Student;
            Data *newData = new Data;
            newStudent->input(newData);
            students.push_back(newStudent);
            data_records.push_back(newData);
            cout << "Student registered!\n";
            break;
        }
        case 2:
            if (students.empty())
                cout << "No students registered yet.\n";
            else
            {
                cout << "********** Student Database **********\n";
                for (size_t i = 0; i < students.size(); ++i)
                    students[i]->display(data_records[i]);
            }
            break;
        case 3:
            for (size_t j = 0; j < students.size(); ++j)
            {
                delete students[j];
                delete data_records[j];
            }
            cout << "Thanks for using the program!\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 3);

    return 0;
}
