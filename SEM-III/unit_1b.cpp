// Stack Implemettions--using linked list.
#include <iostream>
using namespace std;

class Stack{
    private:
    struct Node{
        int data;
        Node* next;
    };
    Node* top;
    public:
    Stack(){
        top = NULL;
    }
    void push(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed into stack." << endl;
    }
    void pop(){
        if (top == NULL){
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack." << endl;
        top = top->next;
        delete temp;
    }
    void peek(){
        if (top == NULL){
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }
    void display(){
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();

    s.display();

    s.peek();

    return 0;
}