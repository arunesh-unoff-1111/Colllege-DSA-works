//------------------------------------------------Linked-List-----------------------------------------------//
//-------------without fucntion----------------//
#include <iostream>
using namespace std;

int main() {
    int data[10], next[10];
    int n, start = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    // Input values
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> data[i];
        next[i] = i + 1;
    }

    next[n - 1] = -1; // end of list

    // Traversal
    cout << "Linked List: ";
    int i = start;
    while (i != -1) {
        cout << data[i] << " -> ";
        i = next[i];
    }
    cout << "NULL";

    return 0;
}
//-------------with fucntion----------------//
#include <iostream>
using namespace std;

void createList(int data[], int next[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> data[i];
        next[i] = i + 1;
    }
    next[n - 1] = -1;
}

void displayList(int data[], int next[], int start) {
    int i = start;
    while (i != -1) {
        cout << data[i] << " -> ";
        i = next[i];
    }
    cout << "NULL";
}

int main() {
    int data[10], next[10];
    int n, start = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    createList(data, next, n);

    cout << "Linked List: ";
    displayList(data, next, start);

    return 0;
}