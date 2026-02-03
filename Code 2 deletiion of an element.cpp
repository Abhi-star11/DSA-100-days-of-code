#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number: \n");
	scanf("%d", &n);
	 int arr[1006];
	 printf("Enter the elements: \n");
	 for(int i =0;i<n;i++)
	 {
	 	scanf("%d", &arr[i]);
	 }
	 int pos;
	 printf("Enter the number: \n");
	 scanf("%d", &pos);
	 for(int i =pos-1; i<n-1;i++)
	 {
	 	arr[i]= arr[i+1];
	 	
	 }
	 for(int i =0;i<n-1;i++)
	 {
	 	printf("%d", arr[i]);
	 }
	 printf("\n");
	 
}
