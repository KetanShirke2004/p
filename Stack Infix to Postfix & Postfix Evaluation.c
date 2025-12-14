#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

/* Stack operations */
void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

/* Operator priority */
int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

/* Infix to Postfix conversion */
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char x;

    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((x = pop()) != '(')
                postfix[j++] = x;
        }
        else {
            while (priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

/* Evaluate Postfix */
int evaluatePostfix(char postfix[]) {
    int i = 0, a, b;
    top = -1;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            b = pop();
            a = pop();
            if (postfix[i] == '+') push(a + b);
            else if (postfix[i] == '-') push(a - b);
            else if (postfix[i] == '*') push(a * b);
            else if (postfix[i] == '/') push(a / b);
        }
        i++;
    }
    return pop();
}

/* Main */
int main() {
    char infix[50], postfix[50];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}
