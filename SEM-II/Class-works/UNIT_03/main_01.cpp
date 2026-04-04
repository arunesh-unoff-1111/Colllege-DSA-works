//---------------------------------------Insertion-Sort-------------------------------------------------//
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter no of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Insertion Sort works like arranging cards in your hand.
    // We assume the first element is already sorted.
    // Then we take one element at a time and insert it into its correct position
    // in the already sorted part (left side).
    // Example Dry Run:
    // arr = [5, 3, 4]
    // Step 1: i=1 → compare 3 with 5 → swap → [3,5,4]
    // Step 2: i=2 → compare 4 with 5 → swap → [3,4,5]
    for (int i = 1; i < n; i++) {
        int j = i;

        // Move element left until it is in correct position
        while (j > 0 && arr[j] < arr[j - 1]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

//---------------------------------------Bubble-Sort-------------------------------------------------//
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter no. of Elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " Elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bubble Sort compares adjacent elements and swaps them if needed.
    // After each pass, the largest element moves to the end.
    // Example Dry Run:
    // arr = [5, 3, 4]
    // Pass 1: [3,5,4] → [3,4,5]
    // Pass 2: [3,4,5] (already sorted)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

//---------------------------------------Selection-Sort-------------------------------------------------//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Selection Sort selects the smallest element and puts it in correct position.
    // Example Dry Run:
    // arr = [5, 3, 4]
    // Step 1: smallest = 3 → swap with 5 → [3,5,4]
    // Step 2: smallest = 4 → swap with 5 → [3,4,5]
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {  
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) {
            int temp = arr[i];      
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

//---------------------------------------Counting-Sort-------------------------------------------------//
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " non-negative elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Counting Sort counts frequency instead of comparing elements.
    // Example Dry Run:
    // arr = [2,1,2]
    // count = [0,1,2]
    // Rebuild → [1,2,2]

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int count[max + 1] = {0};

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//---------------------------------------Radix-Sort-------------------------------------------------//
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Radix Sort sorts numbers digit by digit.
    // Example Dry Run:
    // arr = [21, 13, 32]
    // Step 1 (units): [21,32,13]
    // Step 2 (tens): [13,21,32]

    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int exp = 1;

    while(max / exp > 0) {
        int output[100];
        int count[10] = {0};

        for(int i = 0; i < n; i++) {
            int index = (arr[i] / exp) % 10;
            count[index]++;
        }

        for(int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for(int i = n - 1; i >= 0; i--) {
            int index = (arr[i] / exp) % 10;
            output[count[index] - 1] = arr[i];
            count[index]--;
        }

        for(int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

//---------------------------------------Bucket-Sort-------------------------------------------------//
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements (0–99 range):\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Bucket Sort divides elements into groups and sorts each group.
    // Example Dry Run:
    // arr = [23, 45, 12]
    // Buckets: [12], [23], [45]
    // Merge → [12,23,45]

    int bucket[10][100];
    int count[10] = {0};

    for(int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i] - 1; j++) {
            for(int k = 0; k < count[i] - j - 1; k++) {
                if(bucket[i][k] > bucket[i][k + 1]) {
                    int temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }

    int index = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


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
