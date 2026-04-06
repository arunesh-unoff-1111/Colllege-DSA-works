// -------------Linear-Search------------//
#include <iostream>
using namespace std;

int main() {

    int arr[] = {10, 15, 7, 14, 99, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 14;

    int index = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Number found at " << index + 1 << " position";
    } else {
        cout << "Not found";
    }

    return 0;
}

// -------------Binary-Search------------//
#include <iostream>
using namespace std;

int main() {

    int arr[] = {3, 7, 10, 14, 15, 99};  
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 14;
    int index = -1;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            index = mid;
            break;
        }else if (arr[mid] < key) {
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }

    if (index != -1) {
        cout << "Found at position " << index + 1;
    }else {
        cout << "Not Found";
    }

    return 0;
}

//-----------------------------Without-function & with user input
// -------------Linear-Search------------//

#include <iostream>
using namespace std;

int main() {
    int n, key, found = -1;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = i;
            break;
        }
    }

    if(found != -1)
        cout << "Element found at index " << found;
    else
        cout << "Element not found";

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid;
    int found = -1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            found = mid;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if(found != -1)
        cout << "Element found at index " << found;
    else
        cout << "Element not found";

    return 0;
}