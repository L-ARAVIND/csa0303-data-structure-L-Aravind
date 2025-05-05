#include <stdio.h>

//factorial Using Recursion

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int num;
    printf("Enter Number:");
	scanf("%d",&num);
    printf("Factorial of %d is %d", num, factorial(num));
    return 0;
}
