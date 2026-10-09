
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

bool readInteger(int& value) {
    if (cin >> value) {
        return true;
    }

    cout << "Invalid input! Please enter an integer.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
}

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node*& head, int value, int position) {
    if (position < 1) {
        cout << "Invalid position\n";
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    if (temp->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

void deleteAtPosition(Node*& head, int position) {
    if (position < 1 || head == nullptr) {
        cout << "Invalid position or empty list\n";
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Element not found\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Element deleted successfully\n";
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data;

        if (temp->next != nullptr) {
            cout << " <-> ";
        }

        temp = temp->next;
    }

    cout << '\n';
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    cout << "NAME - Mayank Kalakoti\n";
    cout << "Roll No - 25bma022\n\n";

    Node* head = nullptr;
    int choice, value, position, n;

    do {
        cout << "\n1. Create list\n";
        cout << "2. Insert at beginning\n";
        cout << "3. Insert at end\n";
        cout << "4. Insert at position\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete at position\n";
        cout << "8. Delete by value\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!readInteger(choice)) {
            continue;
        }

        switch (choice) {
            case 1:
                freeList(head);

                cout << "Enter number of elements: ";
                if (!readInteger(n)) {
                    break;
                }

                if (n < 0) {
                    cout << "Invalid size\n";
                    break;
                }

                cout << "Enter elements:\n";

                for (int i = 0; i < n; i++) {
                    if (!readInteger(value)) {
                        i--;
                        continue;
                    }

                    insertAtEnd(head, value);
                }
                break;

            case 2:
                cout << "Enter integer value: ";
                if (readInteger(value)) {
                    insertAtBeginning(head, value);
                }
                break;

            case 3:
                cout << "Enter integer value: ";
                if (readInteger(value)) {
                    insertAtEnd(head, value);
                }
                break;

            case 4:
                cout << "Enter integer value and position: ";

                if (readInteger(value) && readInteger(position)) {
                    insertAtPosition(head, value, position);
                }
                break;

            case 5:
                deleteFromBeginning(head);
                break;

            case 6:
                deleteFromEnd(head);
                break;

            case 7:
                cout << "Enter position: ";

                if (readInteger(position)) {
                    deleteAtPosition(head, position);
                }
                break;

            case 8:
                cout << "Enter integer value to delete: ";

                if (readInteger(value)) {
                    deleteByValue(head, value);
                }
                break;

            case 9:
                display(head);
                break;

            case 0:
                freeList(head);
                cout << "Program terminated\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
