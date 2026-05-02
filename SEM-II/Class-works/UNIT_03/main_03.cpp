// -------------------------------------------------------Doubly Linked List-------------------------------------------------- //
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// ---------------- INSERTION ----------------

// Insert at beginning
Node* insertAtBeginning(Node* head, int val) {
    Node* newNode = new Node{val, NULL, head};

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

// Insert at end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node{val, NULL, NULL};

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Insert after a value
Node* insertAfter(Node* head, int val, int x) {
    Node* temp = head;

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value not found\n";
        return head;
    }

    Node* newNode = new Node{val, temp, temp->next};

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

// ---------------- UPDATION ----------------

// Update at beginning
Node* updateAtBeginning(Node* head, int val) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    head->data = val;
    return head;
}

// Update at end
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

// Update by value
Node* updateByValue(Node* head, int oldVal, int newVal) {
    Node* temp = head;

    while (temp != NULL && temp->data != oldVal)
        temp = temp->next;

    if (temp == NULL)
        cout << "Value not found\n";
    else
        temp->data = newVal;

    return head;
}

// ---------------- DELETION ----------------

// Delete at beginning
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    return head;
}

// Delete at end
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;

    return head;
}

// Delete by value
Node* deleteByValue(Node* head, int x) {
    Node* temp = head;

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value not found\n";
        return head;
    }

    if (temp == head)
        return deleteAtBeginning(head);

    if (temp->next == NULL)
        return deleteAtEnd(head);

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    return head;
}

// ---------------- DISPLAY ----------------

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
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
    head = insertAtBeginning(head, 30);
    head = insertAfter(head, 25, 20);

    cout << "After Insertions: ";
    display(head);

    // UPDATIONS
    head = updateAtBeginning(head, 5);
    head = updateAtEnd(head, 50);
    head = updateByValue(head, 25, 99);

    cout << "After Updations: ";
    display(head);

    // DELETIONS
    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);
    head = deleteByValue(head, 20);

    cout << "After Deletions: ";
    display(head);

    return 0;
}