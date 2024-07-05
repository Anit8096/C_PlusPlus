#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void Print(Node* head){
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        current = current->next;
        if (current != nullptr) {
            cout<<"->";
        }
    }
    cout<<endl;
};

int main(){
    Node* one = new Node;
    Node* two = new Node;
    Node* three = new Node;

    one->data = 10;
    two->data = 20;
    three->data = 30;

    one->next = two;
    two->next = three;

    Print(one);

    delete one;
    delete two;
    delete three;
}