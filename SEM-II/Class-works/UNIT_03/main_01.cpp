//------------------------------------------------Linked-List-----------------------------------------------//
//-------------without function----------------//
#include <iostream>
using namespace std;

int main() {
    int data[10], next[10];
    int n, start = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    // Here we are implementing a Linked List using arrays.
    // 'data' array stores the actual values.
    // 'next' array stores the index of the next element.
    // This simulates how pointers work in real linked lists.

    // Example Dry Run:
    // Suppose user enters: 10, 20, 30
    // data = [10, 20, 30]
    // next = [1, 2, -1]
    // This means:
    // 10 -> 20 -> 30 -> NULL

    // Input values and create links
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> data[i];
        next[i] = i + 1; // point to next index
    }

    next[n - 1] = -1; // last element points to NULL

    // Traversal means visiting each node one by one
    cout << "Linked List: ";
    int i = start;

    // Start from first node and follow 'next' until -1
    while (i != -1) {
        cout << data[i] << " -> ";
        i = next[i]; // move to next node
    }
    cout << "NULL";

    return 0;
}

//-------------with function----------------//
#include <iostream>
using namespace std;

// This function creates the linked list
// It fills data[] and builds connections in next[]
void createList(int data[], int next[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> data[i];
        next[i] = i + 1; // linking to next node
    }
    next[n - 1] = -1; // last node ends the list
}

// This function displays the linked list
// It starts from 'start' and follows next[] step by step
void displayList(int data[], int next[], int start) {
    int i = start;

    // Traverse until we reach -1 (end of list)
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

    // Create list using function
    createList(data, next, n);

    // Display list using function
    cout << "Linked List: ";
    displayList(data, next, start);

    return 0;
}

// Key Understanding (Very Important):
// In real linked lists, we use pointers to store address of next node.
// Here, instead of memory addresses, we use array indexes.
// So next[i] behaves like a pointer, telling us where to go next.
// -1 means NULL, which tells us the list has ended.
