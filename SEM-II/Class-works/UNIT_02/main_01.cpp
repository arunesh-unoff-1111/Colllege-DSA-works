
// -------------Insertion-Sort------------//
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

    for (int i = 1; i < n; i++) {
        int j = i;
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

// -------------Bubble-Sort------------//
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

// -------------Selection-Sort------------//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
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

// -------------Counting-Sort------------//
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

// -------------Radix-Sort------------//
#include<iostream>
using namespace std;
int finding_max(int arr[], int n){
    int maximum = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > maximum){
            maximum = arr[i];
        }
    }return maximum;
}

// void counting_unsorted(int arr[], int n, int exp){
    
// }
int main(){

    int n;
    cout << "Enter the number of elements of array : ";
    cin >> n;

    int arr[100];

    cout << "Enter the elements of your array : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // radixsorting(arr,n);

    cout << "SORTED ARRAY using radix sorting ==";
    for(int i=0; i<n; i++){
        cout << arr[i] << "  ";
    }
    return 0;
}
