#include <iostream>
using namespace std;

int main() {
    int size, key;
    cout << "Enter the size of hash table: ";
    cin >> size;

    int table[size];

    cout << "Enter elements (-1 for empty positions):\n";
    for (int i = 0; i < size; i++) {
        cin >> table[i];
    }

    cout << "Enter key to search: ";
    cin >> key;

    int index = key % size;
    int start = index;

    while (table[index] != -1) {
        if (table[index] == key) {
            cout << "Element found at position " << index << endl;
            return 0;
        }

        index = (index + 1) % size;

        if (index == start) {
            break;
        }
    }

    cout << "Element not found" << endl;

    return 0;
}