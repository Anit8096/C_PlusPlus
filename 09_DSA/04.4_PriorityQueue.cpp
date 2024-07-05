#include <iostream>
using namespace std;

#define MAX 100

class InputRestrictedQueue {
private:
    int arr[MAX];
    int front, rear, size;

public:
    InputRestrictedQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == MAX;
    }

    bool isEmpty() {
        return size == 0;
    }

    void insertRear(int item) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = item;
        size++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Deleted element: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }

        size--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Deleted element: " << arr[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + MAX) % MAX;
        }

        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    InputRestrictedQueue irq;

    irq.insertRear(10);
    irq.insertRear(20);
    irq.insertRear(30);
    irq.display();

    irq.deleteFront();
    irq.display();

    irq.deleteRear();
    irq.display();

    return 0;
}
