#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements (0-99 range):" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int bucket[10][100];
    int count[10] = {0};

    for(int i = 0; i < n; i++) {
        int index = arr[i] / 10;  
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }
    for(int i =0; i<10; i++)[
        for(int j=0; j<n;j++){
            
        }
    ]