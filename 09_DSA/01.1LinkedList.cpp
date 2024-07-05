#include<iostream>
using namespace std;

struct Node {
public:
    int data;
    Node *next;
};

void Print(Node* head){
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        current = current->next;
        if (current != nullptr) {
            cout<<"-> ";
        }
    }
    cout<<endl;
};

void push(Node** headref, int num){
    Node* NewNode = new Node;
    NewNode->data = num;

    if (*headref == nullptr) {
        NewNode->next = nullptr;
    } else {
        NewNode->next = *headref;
    }

    *headref = NewNode;
}

void AddAfter(Node** headref, int d, int n){
    Node* current = *headref;
    int count = 0;
    while (count != n && current != nullptr){
        current = current->next;
        count++;
    }
    if (current != nullptr) {
        Node* NewNode = new Node;
        NewNode->data = d;
        NewNode->next = current->next;
        current->next = NewNode;
    } else {
        cout << "Cannot add after position " << n << " as the list is too short." << endl;
    }
}

void AddBefore(Node** headref, int d, int n){
    Node* current = *headref;
    Node* prev = nullptr; 
    int count = 0;

    while (count != n && current != nullptr){
        prev = current;
        current = current->next;
        count++;
    }

    if (current != nullptr) {
        Node* NewNode = new Node;
        NewNode->data = d;
        if (prev == nullptr) {
            NewNode->next = *headref;
            *headref = NewNode; 
        } else {
            NewNode->next = current;
            prev->next = NewNode;   
        }
    } else {
        cout << "Cannot add before position " << n << " as the list is too short." << endl;
    }
}

void Addend(Node** headref, int d) {
    Node* NewNode = new Node;
    NewNode->data = d;
    NewNode->next = nullptr;
    if (*headref == nullptr) {
        *headref = NewNode;
    } else {
        Node* current = *headref;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = NewNode;
    }
}

void Addend(Node** headref, int d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->next = nullptr;

    if (*headref == nullptr) {
        *headref = newNode;
    } else {
        Node* current = *headref;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void DeleteHead(Node** headref) {
    if (*headref == nullptr) return; 
    Node* temp = *headref;           
    *headref = (*headref)->next;     
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
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;    
    current->next = nullptr; 
}

void DeleteNodeByKey(Node** headref, int key) {
    if (*headref == nullptr) return; 

    Node* current = *headref;
    Node* prev = nullptr;

    if (current != nullptr && current->data == key) {
        *headref = current->next; 
        delete current;           
        return;
    }
    while (current != nullptr && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        return;
    }
    prev->next = current->next;

    delete current;
}

void DeleteNodeByPosition(Node** headref, int position) {
    if (*headref == nullptr) return; 

    Node* current = *headref;
    if (position == 0) {
        *headref = current->next; 
        delete current;           
        return;
    }
    for (int i = 0; current != nullptr && i < position - 1; i++) {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr) {
        return;
    }
    Node* next = current->next->next;
    delete current->next; 
    current->next = next; 
}

int main() {
    Node* one = new Node;
    one = nullptr;

    push(&one,10);
    AddAfter(&one, 20, 0);
    AddAfter(&one, 30, 1);
    AddAfter(&one, 40, 2);
    AddAfter(&one, 50, 3);
    AddAfter(&one, 60, 4);
    AddBefore(&one, 70, 4);
    Addend(&one, 80);

    Print(one);
}