#include <iostream>
using namespace std;

// ================= SINGLE VARIABLE =================
struct Node {
    int coeff, exp;
    Node* next;
};

void insert(Node* &head, int c, int e) {
    Node* n = new Node{c, e, NULL};
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

void display(Node* head) {
    while (head) {
        cout << head->coeff << "x^" << head->exp;
        head = head->next;
        if (head && head->coeff >= 0) cout << " + ";
    }
    cout << endl;
}

// ADD
Node* add(Node* a, Node* b) {
    Node* res = NULL;
    while (a && b) {
        if (a->exp > b->exp) {
            insert(res, a->coeff, a->exp);
            a = a->next;
        } else if (a->exp < b->exp) {
            insert(res, b->coeff, b->exp);
            b = b->next;
        } else {
            int c = a->coeff + b->coeff;
            if (c) insert(res, c, a->exp);
            a = a->next; b = b->next;
        }
    }
    while (a) { insert(res, a->coeff, a->exp); a = a->next; }
    while (b) { insert(res, b->coeff, b->exp); b = b->next; }
    return res;
}

// SUBTRACT
Node* subtract(Node* a, Node* b) {
    Node* res = NULL;
    while (a && b) {
        if (a->exp > b->exp) {
            insert(res, a->coeff, a->exp);
            a = a->next;
        } else if (a->exp < b->exp) {
            insert(res, -b->coeff, b->exp);
            b = b->next;
        } else {
            int c = a->coeff - b->coeff;
            if (c) insert(res, c, a->exp);
            a = a->next; b = b->next;
        }
    }
    while (a) { insert(res, a->coeff, a->exp); a = a->next; }
    while (b) { insert(res, -b->coeff, b->exp); b = b->next; }
    return res;
}

// MULTIPLY
Node* multiply(Node* a, Node* b) {
    Node* res = NULL;
    for (Node* p = a; p; p = p->next) {
        for (Node* q = b; q; q = q->next) {
            int c = p->coeff * q->coeff;
            int e = p->exp + q->exp;

            Node* t = res;
            bool found = false;
            while (t) {
                if (t->exp == e) {
                    t->coeff += c;
                    found = true;
                    break;
                }
                t = t->next;
            }
            if (!found) insert(res, c, e);
        }
    }
    return res;
}

// ================= DOUBLE VARIABLE =================
struct Node2 {
    int coeff, ex, ey;
    Node2* next;
};

void insert2(Node2* &head, int c, int ex, int ey) {
    Node2* n = new Node2{c, ex, ey, NULL};
    if (!head) head = n;
    else {
        Node2* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

void display2(Node2* head) {
    while (head) {
        cout << head->coeff << "x^" << head->ex << "y^" << head->ey;
        head = head->next;
        if (head && head->coeff >= 0) cout << " + ";
    }
    cout << endl;
}

// ADD
Node2* add2(Node2* a, Node2* b) {
    Node2* res = NULL;
    while (a && b) {
        if (a->ex == b->ex && a->ey == b->ey) {
            int c = a->coeff + b->coeff;
            if (c) insert2(res, c, a->ex, a->ey);
            a = a->next; b = b->next;
        } else {
            insert2(res, a->coeff, a->ex, a->ey);
            a = a->next;
        }
    }
    while (a) { insert2(res, a->coeff, a->ex, a->ey); a = a->next; }
    while (b) { insert2(res, b->coeff, b->ex, b->ey); b = b->next; }
    return res;
}

// SUBTRACT
Node2* subtract2(Node2* a, Node2* b) {
    Node2* res = NULL;
    while (a && b) {
        if (a->ex == b->ex && a->ey == b->ey) {
            int c = a->coeff - b->coeff;
            if (c) insert2(res, c, a->ex, a->ey);
            a = a->next; b = b->next;
        } else {
            insert2(res, a->coeff, a->ex, a->ey);
            a = a->next;
        }
    }
    while (a) { insert2(res, a->coeff, a->ex, a->ey); a = a->next; }
    while (b) { insert2(res, -b->coeff, b->ex, b->ey); b = b->next; }
    return res;
}

// MULTIPLY
Node2* multiply2(Node2* a, Node2* b) {
    Node2* res = NULL;
    for (Node2* p = a; p; p = p->next) {
        for (Node2* q = b; q; q = q->next) {
            int c = p->coeff * q->coeff;
            int ex = p->ex + q->ex;
            int ey = p->ey + q->ey;

            Node2* t = res;
            bool found = false;
            while (t) {
                if (t->ex == ex && t->ey == ey) {
                    t->coeff += c;
                    found = true;
                    break;
                }
                t = t->next;
            }
            if (!found) insert2(res, c, ex, ey);
        }
    }
    return res;
}

// ================= MAIN =================
int main() {

    // -------- SINGLE VARIABLE --------
    Node *p1 = NULL, *p2 = NULL;

    // p1 = 5x^2 + 4
    insert(p1, 5, 2);
    insert(p1, 4, 0);

    // p2 = 2x^2 + 3x + 1
    insert(p2, 2, 2);
    insert(p2, 3, 1);
    insert(p2, 1, 0);

    cout << "Single Variable:\n";
    cout << "P1: "; display(p1);
    cout << "P2: "; display(p2);

    cout << "Add: "; display(add(p1, p2));
    cout << "Subtract: "; display(subtract(p1, p2));
    cout << "Multiply: "; display(multiply(p1, p2));

    // -------- DOUBLE VARIABLE --------
    Node2 *q1 = NULL, *q2 = NULL;

    // q1 = 2x^1y^1 + 3
    insert2(q1, 2, 1, 1);
    insert2(q1, 3, 0, 0);

    // q2 = 1x^1y^1 + 4y^1
    insert2(q2, 1, 1, 1);
    insert2(q2, 4, 0, 1);

    cout << "\nDouble Variable:\n";
    cout << "Q1: "; display2(q1);
    cout << "Q2: "; display2(q2);

    cout << "Add: "; display2(add2(q1, q2));
    cout << "Subtract: "; display2(subtract2(q1, q2));
    cout << "Multiply: "; display2(multiply2(q1, q2));

    return 0;
}