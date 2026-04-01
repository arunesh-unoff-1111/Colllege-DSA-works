//---codechef wuestion link---https://www.codechef.com/practice/course/strings/STRINGS/problems/WCC----//
// #include <iostream>
// using namespace std;

// int main() {

//     int T;
//     cin >> T;

//     while (T--) {
//         int X;
//         cin >> X;

//         string S;
//         cin >> S;

//         int carlsen = 0, chef = 0;

//         for (int i = 0; i < 14; i++) {
//             if (S[i] == 'C') {
//                 carlsen += 2;
//             } else if (S[i] == 'N') {
//                 chef += 2;
//             } else { // D
//                 carlsen += 1;
//                 chef += 1;
//             }
//         }

//         if (carlsen > chef) {
//             cout << 60 * X << endl;
//         } else if (carlsen < chef) {
//             cout << 40 * X << endl;
//         } else {
//             cout << 55 * X << endl;
//         }
//     }

//     return 0;
// }
