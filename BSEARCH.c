#include<stdio.h>
#include<conio.h>

//Binary Search

void main(){
	int arr[]={21,22,23,24,25,26,27,28,29},i,n,mid,low,high,k,flag=0;
	n=sizeof(arr)/sizeof(arr[0]);
	printf("Enter To Find The Element:");
	scanf("%d",&k);
	low=0;
	high=n-1;
	while (low<=high){
		mid=(low+high)/2;
		if(arr[mid]==k){
			flag=1;
			break;
		}else if (arr[mid]>k){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	if(flag){
		printf("value is present at %d",mid+1);
	}else{
		printf("Value Not Found");
	}
}