// Question: Given two strings S and R and an integer N, insert R into S at every index that is divisible by N, shifting the existing characters to the right after each insertion.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cout << "Input the string == ";
    cin >> S;

    string R;
    cout << "Input the string to insert == ";
    cin >> R;

    int N;
    cout << "Input only single digit number == ";
    cin >> N;

    if (N <= 0) {
        cout << "N must be greater than 0.";
        return 0;
    }

    string result;

    for (int i = 0; i < S.length(); i++) {
        if (i % N == 0) {
            result += R;      
        }
        result += S[i];       
    }

    cout << "Modified string = " << result << endl;

    return 0;
}
