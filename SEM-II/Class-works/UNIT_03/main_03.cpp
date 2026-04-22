#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// --------------------------------Insertion at begining--------------------------------------//
Node* insertAtBeginning(Node* head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;

    return head;
}

// --------------------------------Insertion at last--------------------------------------//

Node* insertAtLast(Node* head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}
// --------------------------------Insertion at middle--------------------------------------//
Node* insertAtMiddle(Node* head, int val, int x) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        cout << "Not found " << x << endl;
        return head;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }

    if (temp != NULL) {
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    } else {
        cout << "Not found " << x << endl;
    }

    return head;
}

// --------------------------------Displaying the list--------------------------------------//

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int x;
    cout << "Enter value after which to insert: ";
    cin >> x;

    Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtLast(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtMiddle(head, 50, x);

    display(head);

    return 0;
}