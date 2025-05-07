#include <stdio.h>
int main() {
    int numbers[5], i;
    printf("Enter 5 numbers:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }
    printf("Odd or Even results:\n");
    for(i = 0; i < 5; i++) {
        if(numbers[i] % 2 == 0)
            printf("%d is Even\n", numbers[i]);
        else
            printf("%d is Odd\n", numbers[i]);
    }
    return 0;
}

