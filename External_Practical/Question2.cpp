// Q2. Implement Queue using LinkedList

#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();

    return 0;
}

