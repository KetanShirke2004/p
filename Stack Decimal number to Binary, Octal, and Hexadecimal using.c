#include <stdio.h>

int stack[50];
int top = -1;

/* Push */
void push(int x) {
    stack[++top] = x;
}

/* Pop */
int pop() {
    return stack[top--];
}

/* Convert decimal to given base */
void convert(int num, int base) {
    int rem;

    while (num > 0) {
        rem = num % base;
        push(rem);
        num = num / base;
    }

    while (top != -1) {
        rem = pop();
        if (rem < 10)
            printf("%d", rem);
        else
            printf("%c", rem + 55);   // For A, B, C...
    }
}

int main() {
    int num;

    printf("Enter decimal number: ");
    scanf("%d", &num);

    printf("Binary: ");
    convert(num, 2);

    top = -1;
    printf("\nOctal: ");
    convert(num, 8);

    top = -1;
    printf("\nHexadecimal: ");
    convert(num, 16);

    return 0;
}
