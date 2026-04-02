
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

// ---------------------------------------Bubble-Sort-------------------------------------------------//
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

// ---------------------------------------Selection-Sort-------------------------------------------------//
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

// ---------------------------------------Counting-Sort-------------------------------------------------//
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

// ---------------------------------------Radix-Sort-------------------------------------------------//
//---User input without using functions---//
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

    // Find maximum number
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int exp = 1;

    // Radix Sort
    while(max / exp > 0) {
        int output[100];
        int count[10] = {0};

        // Count occurrences of digits
        for(int i = 0; i < n; i++) {
            int index = (arr[i] / exp) % 10;
            count[index]++;
        }

        // Convert to prefix sum
        for(int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build output array (IMPORTANT: reverse loop)
        for(int i = n - 1; i >= 0; i--) {
            int index = (arr[i] / exp) % 10;
            output[count[index] - 1] = arr[i];
            count[index]--;
        }

        // Copy back to original array
        for(int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }

    // Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
//---User input using functions---//
#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int exp) {
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
}

void radixSort(int arr[], int n) {
    int max = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    for(int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
// ---------------------------------------Bucket-Sort-------------------------------------------------//
// -----User input | without fucntion-----//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    float arr[100];

    cout << "Enter elements (0 to 1 range):\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create buckets
    vector<float> bucket[100];

    // Put elements into buckets
    for(int i = 0; i < n; i++) {
        int index = n * arr[i];   // bucket index
        bucket[index].push_back(arr[i]);
    }

    // Sort each bucket
    for(int i = 0; i < n; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    // Merge buckets
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < bucket[i].size(); j++) {
            arr[k++] = bucket[i][j];
        }
    }

    // Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
// -----User input | without fucntion | withput vectors-----//
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

    // Buckets
    int bucket[10][100];
    int count[10] = {0};

    // Put elements into buckets
    for(int i = 0; i < n; i++) {
        int index = arr[i] / 10;  // bucket index
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    // Sort each bucket using Bubble Sort
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

    // Merge buckets back into array
    int index = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }

    // Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
// ---upper code without arr 100---//
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Dynamic array
    int* arr = new int[n];

    cout << "Enter elements (0–99 range):\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create buckets dynamically
    int** bucket = new int*[10];
    int* count = new int[10];

    for(int i = 0; i < 10; i++) {
        bucket[i] = new int[n];  // each bucket can hold up to n elements
        count[i] = 0;
    }

    // Put elements into buckets
    for(int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    // Sort each bucket (Bubble Sort)
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

    // Merge buckets
    int idx = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[idx++] = bucket[i][j];
        }
    }

    // Print result
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Free memory
    delete[] arr;
    for(int i = 0; i < 10; i++) {
        delete[] bucket[i];
    }
    delete[] bucket;
    delete[] count;

    return 0;
}
