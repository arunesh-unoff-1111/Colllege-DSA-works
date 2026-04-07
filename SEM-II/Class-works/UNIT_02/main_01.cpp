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
    // Then we pick the next element and compare it with elements before it.
    // If it is smaller, we keep shifting it left until it reaches the correct position.
    for (int i = 1; i < n; i++) {
        int j = i;

        // This loop keeps moving the current element to the left
        // as long as it is smaller than the element before it.
        while (j > 0 && arr[j] < arr[j - 1]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--; // move one step left
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

    // Bubble Sort repeatedly compares adjacent elements.
    // If the left element is bigger than the right one, they are swapped.
    // After each pass, the largest element moves to the end like a bubble rising up.
    for (int i = 0; i < n - 1; i++) {
        // After every pass, last i elements are already sorted
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
    
    // Selection Sort works by selecting the smallest element
    // from the unsorted part and placing it at the correct position.
    // First position gets the smallest element, second gets next smallest, and so on.
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i; // assume current index has minimum

        // Find the actual smallest element in the remaining array
        for(int j = i + 1; j < n; j++) {  
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap only if a smaller element was found
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

    // First, find the maximum value in the array
    // because we need to create a counting array of that size
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a count array where index represents the number
    // and value represents how many times it appears
    int count[max + 1] = {0};

    // Count frequency of each number
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Rebuild the sorted array using count array
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

    // Find maximum number to know how many digits we need to process
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int exp = 1;

    // Radix Sort processes digits one by one (units, tens, hundreds...)
    while(max / exp > 0) {
        int output[100];
        int count[10] = {0};

        // Count occurrences of digits at current place
        for(int i = 0; i < n; i++) {
            int index = (arr[i] / exp) % 10;
            count[index]++;
        }

        // Convert count array to prefix sum to determine positions
        for(int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build output array from right to left to maintain stability
        for(int i = n - 1; i >= 0; i--) {
            int index = (arr[i] / exp) % 10;
            output[count[index] - 1] = arr[i];
            count[index]--;
        }

        // Copy sorted values back to original array
        for(int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        exp *= 10; // move to next digit place
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

    // Buckets divide the data into groups based on range
    int bucket[10][100];
    int count[10] = {0};

    // Place elements into appropriate buckets
    for(int i = 0; i < n; i++) {
        int index = arr[i] / 10;  // decides bucket range
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    // Sort each bucket individually (using Bubble Sort here)
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

    // Merge all buckets back into original array
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
// --------------using functions-bucket sort--------------//
#include<iostream>
using namespace std;

// Function to sort individual buckets using simple insertion sort
void insertionSort(float bucket[], int n) {
    for (int i = 1; i < n; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    float buckets[10][10];   // 10 buckets, each can hold 10 elements (adjust if needed)
    int count[10] = {0};

    // Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * 10;  // Assuming input is between 0 and 1
        buckets[index][count[index]] = arr[i];
        count[index]++;
    }

    // Sort individual buckets
    for (int i = 0; i < 10; i++) {
        insertionSort(buckets[i], count[i]);
    }

    // Concatenate all buckets into arr[]
    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

// Function to print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = 10;

    cout << "Original array:\n";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}