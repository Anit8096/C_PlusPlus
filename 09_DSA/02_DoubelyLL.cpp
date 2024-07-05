#include <iostream>
using namespace std;

struct Node {
public:
    int data;
    Node *next;
    Node *prev;
};

void Print(Node* head) {
    Node* current = head;
    Node* tail = nullptr;

    // Forward traversal
    cout << "Forward: ";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " <-> ";
        }
        if (current->next == nullptr) {
            tail = current;
        }
        current = current->next;
    }
    cout << endl;

    // Backward traversal
    cout << "Backward: ";
    current = tail;
    while (current != nullptr) {
        cout << current->data;
        if (current->prev != nullptr) {
            cout << " <-> ";
        }
        current = current->prev;
    }
    cout << endl;
}

int main() {
    Node* one = new Node;
    Node* two = new Node;
    Node* three = new Node;

    one->data = 10;
    one->next = two;
    one->prev = nullptr;

    two->data = 20;
    two->next = three;
    two->prev = one;

    three->data = 30;
    three->next = nullptr;
    three->prev = two;

    Print(one);

    delete one;
    delete two;
    delete three;

    return 0;
}
