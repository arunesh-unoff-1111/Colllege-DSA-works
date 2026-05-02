// -------------------------------------------------------Circular Linked List-------------------------------------------------- //
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
    Node* newNode = new Node{val, NULL};

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;

    return head;
}

// Insert at end
Node* insertAtEnd(Node* head, int val) {
    Node* newNode = new Node{val, NULL};

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Insert after a value
Node* insertAfter(Node* head, int val, int x) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    Node* temp = head;

    do {
        if (temp->data == x) {
            Node* newNode = new Node{val, temp->next};
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value not found\n";
    return head;
}

// ---------------- UPDATION ----------------

// Update by value
Node* updateValue(Node* head, int oldVal, int newVal) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    Node* temp = head;

    do {
        if (temp->data == oldVal) {
            temp->data = newVal;
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value not found\n";
    return head;
}

// ---------------- DELETION ----------------

// Delete at beginning
Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    if (head->next == head) {
        delete head;
        return NULL;
    }

    Node* last = head;
    while (last->next != head)
        last = last->next;

    Node* temp = head;
    head = head->next;
    last->next = head;

    delete temp;
    return head;
}

// Delete at end
Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    if (head->next == head) {
        delete head;
        return NULL;
    }

    Node* temp = head;

    while (temp->next->next != head)
        temp = temp->next;

    Node* last = temp->next;
    temp->next = head;

    delete last;
    return head;
}

// Delete after a value
Node* deleteAfter(Node* head, int x) {
    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    Node* temp = head;

    do {
        if (temp->data == x) {
            Node* delNode = temp->next;

            if (delNode == head && delNode->next == head) {
                delete delNode;
                return NULL;
            }

            temp->next = delNode->next;

            if (delNode == head)
                head = delNode->next;

            delete delNode;
            return head;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value not found\n";
    return head;
}

// ---------------- DISPLAY ----------------

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)\n";
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

    // UPDATION
    head = updateValue(head, 20, 99);

    cout << "After Updation: ";
    display(head);

    // DELETIONS
    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);
    head = deleteAfter(head, 25);

    cout << "After Deletions: ";
    display(head);

    return 0;
}