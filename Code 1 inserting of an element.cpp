#include<stdio.h>
int main()
{
	int n;
	printf("Enter a number: \n");
	scanf("%d", &n);
	int arr[1005];
	printf("Enter the elements: \n");
	for(int i =0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	int pos;
	printf("Enter the position you want: \n");
	scanf("%d", &pos);
	int x;
	printf("Enter the number: \n");
	scanf("%d", &x);
	for(int i=n; i>=pos; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[pos-1] = x;
	for(int i=0;i<=n;i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}
