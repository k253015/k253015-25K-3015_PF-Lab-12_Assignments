#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr=(int *)malloc(n * sizeof(int));

    for(int i=0; i<n; i++) {
        printf("\nEnter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nArray before doubling:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nDoubling array size and filling new elements!");

    int *temp=(int *)realloc(arr, (2*n) * sizeof(int));
    if(temp==NULL) {
        printf("\nRe-allocation failed!");
        free(arr);
        return 1;
    }
    arr=temp;
    for(int i=n; i<2*n; i++) {
        arr[i]=arr[i-n]*2;
    }
    printf("\nArray after doubling:\n");
    for(int i=0; i<2*n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}