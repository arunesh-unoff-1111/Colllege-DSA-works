#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool fun(pair<int, string> P1, pair<int, string> P2) {
    if (P1.second != P2.second) {
        return P1.second < P2.second;
    }
    return P1.first > P2.first;
}

int main() {

    unordered_map<int, string> Map = {{10, "AB"}, {30, "AB"}, {8, "DE"}};
    vector<pair<int, string>> vec(Map.begin(), Map.end());

    sort(vec.begin(), vec.end(), fun);


    cout << "Sorted elements:" << endl;
    for (const auto& p : vec) {
        cout << "{" << p.first << ", \"" << p.second << "\"}" << endl;
    }

    return 0;
}
// ------------------------------------------------------------------------------------ //
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> mp;

    mp[5] = 25;
    mp[1] = 1;
    mp[3] = 9;

    for (auto p : mp) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
// ------------------------------------------------------------------------------------------//
#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int,int> m;
    int N;
    cin>>N;
    for (int i = 0; i < N; i++) {
        m[i] = i * i;
    }
    set<int> s;
    for (auto p : m) {
        s.insert(p.second);
    }
    for (auto i: s) {
        cout<<i<<" ";
    }
    
return 0;
}
// -------------------------------------------------------------------------------------//
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n];

    unordered_map<int, int> freq;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int uniqueCount = 0;
    int nonUniqueCount = 0;

    for(auto x : freq) {

        if(x.second == 1)
            uniqueCount++;

        else
            nonUniqueCount++;
    }

    cout << uniqueCount * nonUniqueCount;

    return 0;
}