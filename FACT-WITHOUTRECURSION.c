#include <stdio.h>

//factorial Using Recursion

int main() {
	int i,fact=1,num;
	printf("Enter Number:");
	scanf("%d",&num);
	for (i=1;i<num;i++){
		fact*=i;
	}
	printf("Factorial of %d is %d", num,fact);
	return 0;
}
    