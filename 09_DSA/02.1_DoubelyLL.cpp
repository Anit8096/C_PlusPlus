#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void AddEnd(Node** headref, int d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (*headref == nullptr) {
        *headref = newNode;
    } else {
        Node* current = *headref;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void AddFront(Node** headref, int d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = *headref;
    newNode->prev = nullptr;
    if (*headref != nullptr) {
        (*headref)->prev = newNode;
    }
    *headref = newNode;
}

void AddAfter(Node** headref, int key, int d) {
    Node* current = *headref;
    while (current != nullptr && current->data != key) {
        current = current->next;
    }
    
    if (current == nullptr) return;

    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void DeleteHead(Node** headref) {
    if (*headref == nullptr) return;

    Node* temp = *headref;
    *headref = temp->next;

    if (*headref != nullptr) {
        (*headref)->prev = nullptr;
    }
    delete temp;
}

void DeleteTail(Node** headref) {
    if (*headref == nullptr) return;

    if ((*headref)->next == nullptr) {
        delete *headref;
        *headref = nullptr;
        return;
    }

    Node* current = *headref;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->prev->next = nullptr;
    delete current;
}

void DeleteNodeByKey(Node** headref, int key) {
    if (*headref == nullptr) return;

    Node* current = *headref;
    while (current != nullptr && current->data != key) {
        current = current->next;
    }

    if (current == nullptr) return;

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        *headref = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}

void DeleteNodeByPosition(Node** headref, int position) {
    if (*headref == nullptr) return;

    Node* current = *headref;

    if (position == 0) {
        *headref = current->next;
        if (*headref != nullptr) {
            (*headref)->prev = nullptr;
        }
        delete current;
        return;
    }

    for (int i = 0; current != nullptr && i < position; i++) {
        current = current->next;
    }

    if (current == nullptr) return;

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }

    delete current;
}

void Print(Node** headref) {
    Node* current = *headref;
    Node* tail = nullptr;

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
    Node* head = nullptr;

    AddEnd(&head, 10);
    AddEnd(&head, 20);
    AddEnd(&head, 30);

    AddFront(&head, 5);
    AddAfter(&head, 20, 15);

    Print(&head);

    DeleteHead(&head);
    Print(&head);

    DeleteTail(&head);
    Print(&head);

    DeleteNodeByKey(&head, 15);
    Print(&head);

    AddEnd(&head, 40);
    AddEnd(&head, 50);

    Print(&head);

    DeleteNodeByPosition(&head, 1);
    Print(&head);

    return 0;
}
