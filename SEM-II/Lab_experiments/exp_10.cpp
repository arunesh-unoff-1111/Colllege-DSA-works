#include <iostream>
#include <map>
using namespace std;

void insertElements(map<int, string> &m, int n)
{
    int key;
    string value;

    for (int i = 0; i < n; i++)
    {
        cin >> key >> value;
        m[key] = value;
    }
}

void searchKey(map<int, string> &m, int key)
{
    if (m.find(key) != m.end())
        cout << "Value = " << m[key] << endl;
    else
        cout << "Key not found" << endl;
}

void deleteKey(map<int, string> &m, int key)
{
    if (m.erase(key))
        cout << "Key deleted" << endl;
    else
        cout << "Key not found" << endl;
}

void displayMap(map<int, string> &m)
{
    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << it->second << endl;
}

int main()
{
    map<int, string> m;
    int n, searchKeyValue, deleteKeyValue;

    cout << "Enter number of key-value pairs: ";
    cin >> n;

    cout << "Enter key and value pairs:" << endl;
    insertElements(m, n);

    cout << "Sorted map:" << endl;
    displayMap(m);

    cout << "Enter key to search: ";
    cin >> searchKeyValue;
    searchKey(m, searchKeyValue);

    cout << "Enter key to delete: ";
    cin >> deleteKeyValue;
    deleteKey(m, deleteKeyValue);

    cout << "Map after deletion:" << endl;
    displayMap(m);

    return 0;
}