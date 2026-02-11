#include <stdio.h>
#include <stdlib.h>

int applyOperator(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluatePostfix(char* exp) {
    int stack[1000];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9') {
            stack[++top] = ch - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = applyOperator(a, b, ch);
        }
    }

    return stack[top];
}

int main() {
    char exp[100];
    scanf("%s", exp);
    printf("%d\n", evaluatePostfix(exp));
    return 0;
}
