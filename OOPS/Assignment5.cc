#include <iostream>
using namespace std;

#define SIZE 10 // Corrected the size definition
int n;

template <class T>
void sel(T A[SIZE])
{
    int i, j, min;
    T temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "\nSorted array:";
    for (i = 0; i < n; i++)
    {
        cout << " " << A[i];
    }
}

int main()
{
    int A[SIZE];   // Array for integers
    float B[SIZE]; // Array for floats
    int i;         // Corrected the type declaration for i
    int ch;

    do
    {
        cout << "\n* * * * * SELECTION SORT SYSTEM * * * * *";
        cout << "\n MENU ";
        cout << "\n1. Integer Values";
        cout << "\n2. Float Values";
        cout << "\n3. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter total number of int elements (max " << SIZE << "): ";
            cin >> n;
            if (n > SIZE)
            {
                cout << "Number exceeds maximum size. Setting to " << SIZE << ".\n";
                n = SIZE; // Limit to the size defined
            }
            cout << "\nEnter int elements:";
            for (i = 0; i < n; i++)
            {
                cin >> A[i];
            }
            sel(A);
            break;
        case 2:
            cout << "\nEnter total number of float elements (max " << SIZE << "): ";
            cin >> n;
            if (n > SIZE)
            {
                cout << "Number exceeds maximum size. Setting to " << SIZE << ".\n";
                n = SIZE; // Limit to the size defined
            }
            cout << "\nEnter float elements:";
            for (i = 0; i < n; i++)
            {
                cin >> B[i];
            }
            sel(B);
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid choice. Please select again.";
        }
    } while (ch != 3);

    return 0;
}
