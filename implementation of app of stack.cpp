#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 10
int stack[SIZE];
int top = -1;
void push(int value) {
    if (top == SIZE - 1) {printf("Stack Overflow\n");} else {stack[++top] = value;}}
int pop() {if (top == -1) {
        printf("Stack Underflow\n");exit(1);
    }return stack[top--];
}
int evaluatePostfix(char* expr) {int i = 0;
    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');  
        } else {int operand2 = pop();int operand1 = pop();
            switch (expr[i]) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
                default: printf("Invalid operator\n"); exit(1);
            }}i++;}return pop();  }
int main() {
    char expr[SIZE];
    printf("Enter postfix expression (e.g., 23+5*): ");
    scanf("%s", expr);
    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);return 0;
}

