#include<stdio.h>
#include<conio.h>

//Linear Search

void main() {
	int arr[]={12,45,21,7,18,93,26},i,n,k,flag=0;
	n=sizeof(arr)/sizeof(arr[0]);
	printf("Enter To Find The Element:");
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(arr[i]==k){
			flag=1;
			break;
		}
    }
	if(flag){
		printf("%d value is present at %d",k,i+1);
	}else{
		printf("Value Not Found");
	}
}
