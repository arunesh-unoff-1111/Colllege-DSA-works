#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> Set1 = {1, 2, 3, 4};
    unordered_set<int> Set2 = {3, 4, 5, 6};

    unordered_set<int> newSet;

    for (auto num : Set1) {
        if (Set2.count(num)) {
            newSet.insert(num);
        }
    }

    return 0;
}
// -------------------------------------------------------- //
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    set<int> A = {1, 2, 3, 4};
    set<int> B = {3, 4, 5, 6};
    set<int> set1;

    set_intersection(A.begin(), A.end(), B.begin(), B.end(),inserter(set1, set1.begin()));

    return 0;
}
// -------------------------------------------------------------- //
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    set<int> A = {1, 2, 3};
    set<int> B = {2, 3, 4};

    vector<int> res;

    set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(res));
    cout << "Union: ";
    for(int x : res) cout << x << " ";
    cout << endl;

    res.clear();

    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(res));
    cout << "Intersection: ";
    for(int x : res) cout << x << " ";
    cout << endl;

    res.clear();

    set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(res));
    cout << "Difference (A-B): ";
    for(int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
// ---------------------------------------------------------------------------------------- //
#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> uniqueNumbers;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        uniqueNumbers.insert(x);
    }

    for (int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << uniqueNumbers.size() << endl;

    return 0;
}