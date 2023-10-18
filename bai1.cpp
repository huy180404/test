#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    private:
        Node* top;
    public:
        Stack() {
            top = NULL;
        }

        void push(int x) {
            Node* temp = new Node;
            temp->data = x;
            temp->next = top;
            top = temp;
        }

        void pop() {
            Node* temp;
            if (top == NULL) return;
            temp = top;
            top = top->next;
            delete temp;
        }

        int Top() {
            return top->data;
        }

        bool isEmpty() {
            return top == NULL;
        }

        void display() {
            Node* p = top;
            while (p != NULL) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }
};

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;
    for (int i = 0; i < infix.length(); i++) {
        if (isalnum(infix[i])) postfix += infix[i];
        else if (infix[i] == '(') s.push(infix[i]);
        else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(infix[i])) {
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) s.push(postfix[i] - '0');
        else {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();
            switch (postfix[i]) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    string infix = "3+4*2/(1-5)^2";
    string postfix = infixToPostfix(infix);
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}
