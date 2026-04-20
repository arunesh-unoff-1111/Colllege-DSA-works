#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at Beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node{data, NULL, head};

    if (head != NULL) {
        head->prev = newNode;
    }

    return newNode;
}

// Insert at Last
Node* insertAtLast(Node* head, int data) {
    Node* newNode = new Node{data, NULL, NULL};

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Delete from Beginning
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return head;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
    return head;
}

// Delete from Last
Node* deleteFromLast(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return head;
    }
    Node* temp = head;

    if (temp->next == NULL) {
        delete temp;
        return NULL;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;

    return head;
}

// Delete specific value
Node* deleteFromMiddle(Node* head, int x) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return head;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != x) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Not found " << x << endl;
        return head;
    }

    if (temp == head) {
        return deleteFromBeginning(head);
    }

    if (temp->next == NULL) {
        return deleteFromLast(head);
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    return head;
}
// Display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Build list
    head = insertAtBeginning(head, 10);
    head = insertAtLast(head, 20);
    head = insertAtBeginning(head, 30);

    cout << "Original list: ";
    display(head);

    int x;
    cout << "Enter value to delete: ";
    cin >> x;

    head = deleteFromMiddle(head, x);

    cout << "After deletion: ";
    display(head);

    return 0;
}
