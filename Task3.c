#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_memory(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int n;
    printf("Enter the number of strings (n): ");
    scanf("%d", &n);
    getchar();

    if (n <= 0) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    char **arr_of_strings = (char **)malloc(n * sizeof(char *)); 
    
    char buffer[100];

    printf("Enter %d strings:", n);
    for (int i = 0; i < n; i++) {
        printf("\nString %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        int len = strlen(buffer);

        arr_of_strings[i] = (char *)malloc((len + 1) * sizeof(char));

        strcpy(arr_of_strings[i], buffer);
    }
    
    printf("\nSorting strings alphabetically...\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr_of_strings[j], arr_of_strings[j + 1]) > 0) {
                char *temp = arr_of_strings[j];
                arr_of_strings[j] = arr_of_strings[j + 1];
                arr_of_strings[j + 1] = temp;
            }
        }
    }

    printf("\n--- Sorted Strings ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", i + 1, arr_of_strings[i]);
    }

    free_memory(arr_of_strings, n);
    printf("\nMemory successfully freed.\n");

    return 0;
}