#include<iostream>
using namespace std;
int main(){
    int size;
    cout << "ENTER THE SIZE OF HASH TABLE :";
    cin >> size;

    int hashtable[size];
    for(int i=0; i<size; i++){
        hashtable[i]=-1;
    }
    int key;
    cout << "ENTER THE KEY TO BE INSERTED: ";
    cin >> key;

    int index =key % size;

    while(hashtable[index] !=-1){
        index =(index +1) % size;
    }

    hashtable[index]=key;

    cout << "\n HASH TABLE: \n";
    for(int i=0; i <size; i++){
        cout << "INDEX " << i << " : " << hashtable[i] << endl;

    }

    return 0;
}
