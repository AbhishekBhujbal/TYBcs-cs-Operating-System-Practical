#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void bubblesort(int arr[30],int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
void fork1(){
	int arr[30],arr1[30],n,i,status;
	printf("\nEnter the no of values in array :");
	scanf("%d",&n);
	printf("\nEnter the array elements :");
	for(i=0;i<n;i++){
 		scanf("%d",&arr[i]);
	}
	int pid=fork();
	if(pid==0){
		sleep(5);
	       		printf("\nchild process\n");
                        printf("\nchild process id=%d\n",getppid());
                        bubblesort(arr,n);
                        printf("Elements Sorted Using insertionsort:\n");
                        for(i=0;i<n;i++){
                                printf("%d,",arr[i]);
			}
                        printf("\n\n");

 		}
 		else{
 			printf("\nparent process\n");
 			printf("\nparent process id=%d\n",getppid());
			bubblesort(arr,n);
			printf("Elements Sorted Using bubblesort:\n");
 			for(i=0;i<n;i++){
 				printf("%d,",arr[i]);
			}
 			printf("\n\n");
 		}
}
void main(){
	fork1();
}
