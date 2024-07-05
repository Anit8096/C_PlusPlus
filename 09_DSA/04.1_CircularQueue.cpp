#include<iostream>

class C_Queue {
    int front = -1;
    int rear = -1;
    int size;
    int *c_queue;

public:
    C_Queue (int s) {
        size = s;
        c_queue = new int[size];
    }
    
    void enqueue (int data) {
        if (front == -1) {
            front++;
        }
        if (rear == size) {
            rear = 0;
        }
        c_queue[++rear] = data;
    }

    int dequeue () {
        if (front == -1) {
            std::cout<<"queue is empty"<<std::endl;
            return 1;
        }
        int x = c_queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        if (front == size) {
            front = 0;
        }
        return x;
    }

    void peek(void) {
        std::cout<<"Top value is -> "<<c_queue[front]<<std::endl;
    }

    void print(void) {
        int i;
        if (front == rear) {
            std::cout<<"Queue is Empty\n";
            return;
        }
        for (i = front; i < rear; i++) {
            std::cout<<c_queue[i]<<" <-- ";
            if ( i == rear -1) {
                std::cout<<"\n";
            }
        }
        return;
    }
};

int main() {
    C_Queue a(5);

    a.enqueue(10);
    a.enqueue(20);
    a.enqueue(30);
    a.enqueue(40);
    a.enqueue(50);

    a.print();
    
    int y = a.dequeue();
    std::cout<< y <<" is deleated."<<std::endl;

    a.peek();

    int z = a.dequeue();
    std::cout<< z <<" is deleated."<<std::endl;

    a.peek();

    a.print();
}