
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void insertFront(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Deleted element: " << temp->data << '\n';

        front = front->next;

        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr;
        }

        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = rear;
        cout << "Deleted element: " << temp->data << '\n';

        rear = rear->prev;

        if (rear != nullptr) {
            rear->next = nullptr;
        } else {
            front = nullptr;
        }

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;

        cout << "Deque: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << '\n';
    }

    ~Deque() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
    }
};

bool readInteger(int& value) {
    if (cin >> value) {
        return true;
    }

    cout << "Invalid input! Please enter an integer.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
}

int main() {
    cout << "NAME - Mayank Kalakoti\n";
    cout << "Roll No - 25bma022\n\n";

    Deque dq;
    int choice, value;

    do {
        cout << "\n1. Insert at front\n";
        cout << "2. Insert at rear\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from rear\n";
        cout << "5. Display\n";
        cout << "6. Check if empty\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!readInteger(choice)) {
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter integer: ";
                if (readInteger(value)) {
                    dq.insertFront(value);
                }
                break;

            case 2:
                cout << "Enter integer: ";
                if (readInteger(value)) {
                    dq.insertRear(value);
                }
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << (dq.isEmpty() ? "Deque is empty\n" :
                                         "Deque is not empty\n");
                break;

            case 0:
                cout << "Program terminated\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
