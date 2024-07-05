#include <iostream>

class Queue
{
private:
    int *queue;
    int size, front, rear;
public:
    Queue(int n);

    void enqueue(int data);
    int dequeue();
    int dequeueRear();
    void peek();
    bool isEmpty();
    bool isFull();
    void display();

    ~Queue();
};

Queue::Queue(int n) {
    front = rear = -1;
    size = n;
    queue = new int[size];
}

Queue::~Queue() {
    delete[] queue;
}

void Queue::enqueue(int data) {
    if (isFull()) {
        std::cout<<"queue Overflow !"<<std::endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    queue[rear++] = data;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout<<"Queue Underflow !"<<std::endl;
        return -1;
    }
    int temp = queue[front++];
    return temp;
}

void Queue::peek() {
    if (isEmpty()) {
        std::cout<<"Queue is empty."<<std::endl;
        return;
    }
    std::cout<<"Front -> "<<queue[front]<<std::endl;
}

bool Queue::isEmpty() {
    return (front == rear || front == -1);
}

bool Queue::isFull() {
    return (rear == (size-1));
}

int Queue::dequeueRear() {
    if (isEmpty()) {
        std::cout<<"Queue Underflow !"<<std::endl;
        return -1;
    }
    int temp = queue[rear--];
    return temp;
}

void Queue::display() {
    if (front == rear) {
        std::cout<<"Queue is Empty\n";
        return;
    }
    int i;
    std::cout <<"Queue = ";
    for (i = front; i < rear; i++) {
        std::cout<<queue[i]<<" <--\t";
        if ( i == rear -1) {
            std::cout<<"\n";
        }
    }
    return;
}

int main() {
    Queue q(9);
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(14);
    q.enqueue(16);//overflow

    q.peek();
    q.display();

    q.dequeue();
    q.dequeue();

    q.peek();
    q.display();

    q.enqueue(18);
    q.display();
    q.dequeueRear();
    q.display();

    // q.~Queue;
}