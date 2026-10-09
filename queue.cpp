
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

class Deque {
    int arr[MAX];
    int front, rear, count;

public:
    Deque() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX;
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        front = (front - 1 + MAX) % MAX;
        arr[front] = value;

        if (count == 0) {
            rear = front;
        }

        count++;
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        rear = (rear + 1) % MAX;
        arr[rear] = value;

        if (count == 0) {
            front = rear;
        }

        count++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deleted element: " << arr[front] << '\n';
        front = (front + 1) % MAX;
        count--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deleted element: " << arr[rear] << '\n';
        rear = (rear - 1 + MAX) % MAX;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        int index = front;

        cout << "Deque: ";

        for (int i = 0; i < count; i++) {
            cout << arr[index] << " ";
            index = (index + 1) % MAX;
        }

        cout << '\n';
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
        cout << "7. Check if full\n";
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

            case 7:
                cout << (dq.isFull() ? "Deque is full\n" :
                                        "Deque is not full\n");
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
