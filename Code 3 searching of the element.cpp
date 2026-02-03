#include <stdio.h>

int main() {
    int n, k;
    int arr[100];
    int comparisons = 0;
    int found = 0;
    printf("Enter the size: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	printf("Enter the elemnts: \n");
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
    	
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}

