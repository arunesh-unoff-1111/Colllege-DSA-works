// -------------------------------------------------------Singly Linked List-------------------------------------------------- //
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// ---------------- INSERTION ----------------

// Insert at beginning
Node* insertAtBeginning(Node* head, int val) {
    Node* newNode = new Node{val, head};
    return newNode;
}

// Insert at end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node{val, NULL};

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Insert after a given value
Node* insertAfter(Node* head, int val, int x) {
    Node* temp = head;

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value " << x << " not found\n";
        return head;
    }

    Node* newNode = new Node{val, temp->next};
    temp->next = newNode;

    return head;
}

// ---------------- UPDATION ----------------

// Update first node
Node* updateAtBeginning(Node* head, int val) {
    if (head == NULL)
        cout << "List is empty\n";
    else
        head->data = val;

    return head;
}

// Update last node
Node* updateAtEnd(Node* head, int val) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->data = val;
    return head;
}

// Update node by value
Node* updateByValue(Node* head, int newVal, int oldVal) {
    Node* temp = head;

    while (temp != NULL && temp->data != oldVal)
        temp = temp->next;

    if (temp != NULL)
        temp->data = newVal;
    else
        cout << "Value not found\n";

    return head;
}

// ---------------- DELETION ----------------

// Delete at beginning
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

// Delete at end
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return NULL;
    }

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;

    return head;
}

// Delete after a given value
Node* deleteAfter(Node* head, int x) {
    Node* temp = head;

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Deletion not possible\n";
        return head;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;

    return head;
}

// ---------------- DISPLAY ----------------

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// ---------------- MAIN ----------------

int main() {
    Node* head = NULL;

    // INSERTIONS
    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAfter(head, 25, 20);

    cout << "After Insertions: ";
    display(head);

    // UPDATIONS
    head = updateAtBeginning(head, 5);
    head = updateAtEnd(head, 50);
    head = updateByValue(head, 35, 30);

    cout << "After Updations: ";
    display(head);

    // DELETIONS
    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);
    head = deleteAfter(head, 20);

    cout << "After Deletions: ";
    display(head);

    return 0;
}