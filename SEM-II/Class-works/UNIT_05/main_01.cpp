#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() {
    set<int> set1, set2;

    set1.insert(1);
    set1.insert(2);
    set1.insert(3);

    set2.insert(1);
    set2.insert(2);

    set1.erase(3);
    set1.insert(set2.begin(), set2.end());

    if (set1 == set2)
        cout << "sets are equal" << endl;
    else
        cout << "sets are not equal" << endl;

    if (includes(set1.begin(), set1.end(), set2.begin(), set2.end()))
        cout << "set2 is subset of set1" << endl;
    else
        cout << "set2 is not the subset of set1" << endl;

    int x = 2;

    if (set1.count(x) || (set1.find(x) != set1.end()))
        cout << x << " exists in set" << endl;
    else
        cout << x << " does not exist" << endl;

    cout << "Elements of set1: ";
    for (int val : set1)
        cout << val << " ";

    cout << endl;
    return 0;
}