#include <iostream>
#include <bits/stdc++.h>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    set<int> mySet = {10, 20, 30, 40, 50};

    int sum = accumulate(mySet.begin(), mySet.end(), 0);
    cout << "Sum of set: " << sum << endl;

    int mx = *max_element(mySet.begin(), mySet.end());
    cout << "Max of set: " << mx << endl;

    int mn = *min_element(mySet.begin(), mySet.end());
    cout << "Min of set: " << mn << endl;

    cout << "Looping through mySet: ";
    for (int val : mySet) {
        cout << val << " ";
    }
    cout << endl << endl;

    set<int> set1 = {1, 2, 3};
    set<int> set2 = {3, 4, 5};

    set1.insert(set2.begin(), set2.end());

    cout << "Union in place (set1): ";
    for (int val : set1) {
        cout << val << " ";
    }
    cout << endl;

    set<int> newSet = {1, 2, 3};
    set<int> tempSet2 = {3, 4, 5};

    set<int> unionSet = newSet;
    unionSet.insert(tempSet2.begin(), tempSet2.end());

    cout << "Union in new variable (ordered set): ";
    for (int val : unionSet) {
        cout << val << " ";
    }
    cout << endl;

    unordered_set<int> uset1 = {1, 2, 3};
    unordered_set<int> uset2 = {3, 4, 5};

    unordered_set<int> newUSet = uset1;
    newUSet.insert(uset2.begin(), uset2.end());

    cout << "Union in new variable (unordered set): ";
    for (int val : newUSet) {
        cout << val << " ";
    }
    cout << endl;

    set<int> a = {1, 2, 3};
    set<int> b = {3, 4, 5};
    set<int> result;

    set_union(a.begin(), a.end(),
              b.begin(), b.end(),
              inserter(result, result.begin()));

    cout << "Union using set_union(): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}