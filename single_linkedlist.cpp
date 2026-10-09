#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
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
    temp->next = newNode;
}

void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
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

    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

void deleteByValue(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    if (head->data == value) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Element not found\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
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
            cout << " -> ";
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
        cin >> choice;

        switch (choice) {
            case 1:
                freeList(head);
                cout << "Enter number of elements: ";
                cin >> n;

                if (n < 0) {
                    cout << "Invalid size\n";
                    break;
                }

                cout << "Enter elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> value;
                    insertAtEnd(head, value);
                }
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;

            case 4:
                cout << "Enter value and position: ";
                cin >> value >> position;
                insertAtPosition(head, value, position);
                break;

            case 5:
                deleteFromBeginning(head);
                break;

            case 6:
                deleteFromEnd(head);
                break;

            case 7:
                cout << "Enter position: ";
                cin >> position;
                deleteAtPosition(head, position);
                break;

            case 8:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByValue(head, value);
                break;

            case 9:
                display(head);
                break;

            case 0:
                freeList(head);
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}