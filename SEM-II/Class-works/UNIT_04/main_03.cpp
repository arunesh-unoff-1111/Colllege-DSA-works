#include <iostream>
using namespace std;

int main() {
    int size, key;
    cin >> size;

    int table[size];

    for (int i = 0; i < size; i++) {
        cin >> table[i];
    }

    cin >> key;

    int index = key % size;
    int startingIndex = index;

    while (table[index] != -1) {
        if (table[index] == key) {
            cout << "ELMENT FOUND AT POSTION :  " << index << endl;
            return 0;
        }

        index = (index + 1) % size;

        if (index == startingIndex) {
            break;
        }
    }

    cout << "Element not found" << endl;

    return 0;
}