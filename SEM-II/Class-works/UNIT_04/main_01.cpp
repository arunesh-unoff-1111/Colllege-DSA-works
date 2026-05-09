#include <iostream>
using namespace std;

const int SIZE = 10;
int table[SIZE];

void initializeTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = -1;
    }
}

void insertion()
{
    int key, index;

    cout << "Enter the key to insert: ";
    cin >> key;

    index = key % SIZE;

    table[index] = key;

    cout << "Key inserted at index " << index << endl;
}

void searching()
{
    int key, index;

    cout << "Enter the key to search: ";
    cin >> key;

    index = key % SIZE;

    if (table[index] == key)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
}

void deletion()
{
    int key, index;

    cout << "Enter the key to delete: ";
    cin >> key;

    index = key % SIZE;

    if (table[index] == key)
    {
        table[index] = -1;
        cout << "Element Deleted" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}

void display()
{
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Index " << i << " : " << table[i] << endl;
    }
}

int main()
{
    int choice;

    initializeTable();

    do
    {
        cout << "\n---HASH TABLE MENU----\n";
        cout << "1. Insertion\n";
        cout << "2. Searching\n";
        cout << "3. Deletion\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertion();
                break;

            case 2:
                searching();
                break;

            case 3:
                deletion();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}