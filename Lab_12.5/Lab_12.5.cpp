#include <iostream>
#include <fstream>

using namespace std;

const int MAX_LEN = 100;

struct Stack {
    char data[MAX_LEN];
    int top;
};


bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}



void initStack(Stack& s)
{
    s.top = -1;
}

bool isEmpty(Stack s) {
    return (s.top == -1);
}

bool isFull(Stack s) {
    return (s.top == MAX_LEN - 1);
}

void push(Stack& s, char val) {
    if (!isFull(s))
    {
        s.top++;
        s.data[s.top] = val;
    }
}

char pop(Stack& s) {
    if (!isEmpty(s)) {
        return s.data[s.top--];
    }
    return '\0';
}

char peek(Stack s) {
    if (!isEmpty(s)) {
        return s.data[s.top];
    }
    return '\0';
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initStack(stack);
    int i = 0, j = 0;

    while (infix[i]) {
        char ch = infix[i];

        if (!isOperator(ch)) {
            postfix[j++] = ch;
        }
        else if (isOperator(ch)) {
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(ch)) {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        }
        else if (ch == '(') {
            push(stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            pop(stack);
        }

        i++;
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_LEN];
    char postfix[MAX_LEN];

    // зчитування виразу з файлу
    ifstream fin("input.txt");
    fin.getline(infix, MAX_LEN);
    fin.close();

    infixToPostfix(infix, postfix);

    // запис постфіксної форми в файл
    ofstream fout("output.txt"); 
    fout << postfix;
    fout.close();

    return 0;
}
