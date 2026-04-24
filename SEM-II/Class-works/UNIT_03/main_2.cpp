#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Insert at end
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Delete at beginning
Node* deleteAtBeginning(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return nullptr;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete at end
Node* deleteAtEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

// Delete after a given value
Node* deleteAfter(Node* head, int x) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return head;
    }

    Node* temp = head;

    while (temp != nullptr && temp->data != x) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Deletion not possible\n";
        return head;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;

    return head;
}

// Display list
void traverse(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    cout << "Linked list: ";

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, value, x;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> value;
                head = insertAtEnd(head, value);
                break;

            case 2:
                head = deleteAtBeginning(head);
                break;

            case 3:
                head = deleteAtEnd(head);
                break;

            case 4:
                cin >> x;
                head = deleteAfter(head, x);
                break;

            case 5:
                traverse(head);
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}