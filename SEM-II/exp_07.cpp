#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the size of hash table: ";
    cin >> size;

    int table[size];

    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }

    int key;
    cout << "Enter the key to insert: ";
    cin >> key;

    int index = key % size;

    while (table[index] != -1) {
        index = (index + 1) % size;
    }

    table[index] = key;

    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << " : " << table[i] << endl;
    }

    return 0;
}