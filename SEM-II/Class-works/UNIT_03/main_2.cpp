#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

// ------------------ Singly Linked List (Updation) ------------------

Node* updation_at_beginning(Node* head, int val)
{
    if (head == NULL)
        cout << "list is Empty";
    else
        head->data = val;
    return head;
}

Node* Updation_at_last(Node* head, int val)
{
    if (head == NULL)
        cout << "list is Empty";
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->data = val;
    }
    return head;
}

Node* Updation_at_Middle(Node* head, int val, int x)
{
    if (head == NULL)
        cout << "list is Empty";
    else
    {
        Node* temp = head;
        while (temp->data != x && temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->data == x)
        {
            temp->data = val;
        }
        else
        {
            cout << "not";
        }
    }
    return head;
}

// ------------------ Circular Linked List (Insertion) ------------------

Node* Inserted_beginning(Node* head, int val)
{
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    return head;
}

Node* Insert_at_last(Node* head, int val)
{
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
    return head;
}

Node* Inserted_last(Node* head, int val, int x)
{
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL)
    {
        cout << "list is Empty";
    }
    else
    {
        Node* temp = head;
        while (temp->data != x && temp->next != head)
        {
            temp = temp->next;
        }
        if (temp->data == x)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            cout << "not found";
        }
    }
    return head;
}

Node* Insert_by_position(Node* head, int val)
{
    Node* newnode = new Node();
    // (Note: The handwritten logic for position-based insertion ends here in the image)
}

// ------------------ Main Function ------------------

int main()
{
    Node* head = NULL;

    // You can test functions here if needed

    return 0;
}