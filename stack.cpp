
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(char value) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return;
        }

        arr[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }

        return arr[top--];
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }

        return arr[top];
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' ||
           ch == '/' || ch == '%' || ch == '^';
}

bool isOperand(char ch) {
    return isalnum(static_cast<unsigned char>(ch));
}

bool infixToPostfix(const string& infix, string& postfix) {
    Stack st;
    bool expectOperand = true;
    int parentheses = 0;

    for (char ch : infix) {
        if (isspace(static_cast<unsigned char>(ch))) {
            continue;
        }

        if (isOperand(ch)) {
            if (!expectOperand) {
                return false;
            }

            postfix += ch;
            expectOperand = false;
        }
        else if (ch == '(') {
            if (!expectOperand) {
                return false;
            }

            st.push(ch);
            parentheses++;
        }
        else if (ch == ')') {
            if (expectOperand || parentheses == 0) {
                return false;
            }

            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }

            if (st.isEmpty()) {
                return false;
            }

            st.pop();
            parentheses--;
            expectOperand = false;
        }
        else if (isOperator(ch)) {
            if (expectOperand) {
                return false;
            }

            while (!st.isEmpty() && st.peek() != '(' &&
                   (precedence(st.peek()) > precedence(ch) ||
                   (precedence(st.peek()) == precedence(ch) && ch != '^'))) {
                postfix += st.pop();
            }

            st.push(ch);
            expectOperand = true;
        }
        else {
            return false;
        }
    }

    if (expectOperand || parentheses != 0) {
        return false;
    }

    while (!st.isEmpty()) {
        if (st.peek() == '(') {
            return false;
        }

        postfix += st.pop();
    }

    return true;
}

int main() {
    cout << "NAME - Mayank Kalakoti\n";
    cout << "Roll No - 25bma022\n\n";

    string infix, postfix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    if (infixToPostfix(infix, postfix)) {
        cout << "Postfix expression: " << postfix << '\n';
    } else {
        cout << "Invalid infix expression\n";
    }

    return 0;
}
