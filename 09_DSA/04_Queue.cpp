#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int front,rear,size;
    int *queue;
    Queue (int c) {
        front = rear = 0;
        size = c;
        queue = new int[c];
    }
    ~Queue() {
        delete[] queue;
    }

    void enqueue (int d);
    int dequeue ();
    void display();
    void peek();
};

void Queue:: enqueue (int d) {
    if (size == rear) {
        cout<<"Queue is Full. Can't add : "<< d <<"\n";
        return;
    }
    queue[rear++] = d;
    return;
}

int Queue:: dequeue () {
    if (front == rear) {
        cout << "Queue is Empty\n";
        return -1;
    } else {
        int removedData = queue[front];
        for (int i = 0; i < rear - 1; i++) {
            queue[i] = queue[i + 1]; 
        }
        rear--;
        return removedData; 
    }
}

void Queue::display() {
    if (front == rear) {
        cout<<"Queue is Empty\n";
        return;
    }
    int i;
    cout <<"Queue = ";
    for (i = front; i < rear; i++) {
        cout<<queue[i]<<" <--\t";
        if ( i == rear -1) {
            cout<<"\n";
        }
    }
    return;
}

void Queue::peek(){
    if (front == rear) {
        cout<<"Queue is Empty\n";
        return;
    }
    cout<<"Front element is : "<<queue[front]<<"\n";
    return;
}

int main(){
    Queue q(5);

    // print Queue elements
    q.display();

    // inserting elements in the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // print Queue elements
    q.display();

    // insert element in the queue
    q.enqueue(60);

    // print Queue elements
    q.display();

    int x = q.dequeue();
    cout<<"Deleated : "<<x<<endl;
    int y = q.dequeue();
    cout<<"Deleated : "<<y<<endl;
    
    printf("\nafter two node deletion\n\n");

    // print Queue elements
    q.display();

    // print front of the queue
    q.peek();

    return 0;
}