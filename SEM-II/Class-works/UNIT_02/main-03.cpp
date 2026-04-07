#include <iostream>
using namespace std;

int main() {
    int n, bucketCount;

    cout << "Enter number of elements: ";
    cin >> n;

    float arr[n];

    cout << "Enter elements (between 0 and 1):" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of buckets: ";
    cin >> bucketCount;

    float buckets[bucketCount][n];
    int count[bucketCount];

    for(int i = 0; i < bucketCount; i++) {
        count[i] = 0;
    }


    for(int i = 0; i < n; i++) {
        int index = arr[i] * bucketCount;
        buckets[index][count[index]] = arr[i];
        count[index]++;
    }

    for(int i = 0; i < bucketCount; i++) {
        for(int j = 0; j < count[i] - 1; j++) {
            for(int k = 0; k < count[i] - j - 1; k++) {
                if(buckets[i][k] > buckets[i][k + 1]) {
                    float temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }

    int index = 0;
    for(int i = 0; i < bucketCount; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    cout << "Sorted array:" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}