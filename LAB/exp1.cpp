// Question: Given an array of integers as input from the user, rearrange its elements in the order: smallest, largest, second smallest, second largest, third smallest, third largest, and continue this pattern until all elements have been arranged.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    cout << "Rearranged array: ";

    while (left < right) {
        cout << arr[left] << " ";   
        cout << arr[right] << " ";  
        left++;
        right--;
    }

    if (left == right) {
        cout << arr[left];
    }

    return 0;
}
