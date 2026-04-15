#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* insertAtBeginning(Node* head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}
Node* insertAtLast(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
Node* insertAtMiddle(Node* head, int value, int x) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        cout << "Not found " << x << endl;
    } else {
        Node* temp = head;
        while (temp != NULL && temp->data != x) {
            temp = temp->next;
        }

        if (temp != NULL && temp->data == x) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Not found " << x << endl;
        }
    }
    return head;
}
int main() {
    int x;
    cout << "Enter the value after which to insert: ";
    cin >> x;

    Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtLast(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtMiddle(head, 50, x);

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}