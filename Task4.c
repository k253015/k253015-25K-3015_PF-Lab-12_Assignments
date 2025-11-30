#include <stdio.h>
#include <stdlib.h>

void calculate_total(int *arr, int size)
{
    int total_sales = 0;
    for (int i = 0; i < size; i++)
    {
        total_sales += arr[i];
    }
    printf("Total Sales for %d days: %d\n", size, total_sales);
}

int main()
{
    int initial_days, additional_days;
    int current_size;

    printf("Enter initial number of days for sales data (N): ");
    scanf("%d", &initial_days);
    current_size = initial_days;

    int *sales_data = (int *)malloc(current_size * sizeof(int));

    printf("--- Entering Initial Sales Data ---\n");
    for (int i = 0; i < current_size; i++)
    {
        printf("Day %d sales: ", i + 1);
        scanf("%d", &sales_data[i]);
    }

    calculate_total(sales_data, current_size);

    printf("\n--- Extending Array Size ---\n");
    printf("Enter additional days needed: ");
    scanf("%d", &additional_days);

    int new_size = current_size + additional_days;

    int *temp_ptr = (int *)realloc(sales_data, new_size * sizeof(int));

    sales_data = temp_ptr;
    printf("Memory successfully extended from %d days to %d days.\n", current_size, new_size);

    printf("--- Entering New Sales Data ---\n");
    for (int i = current_size; i < new_size; i++)
    {
        printf("Day %d sales: ", i + 1);
        scanf("%d", &sales_data[i]);
    }
    current_size = new_size;

    printf("\n--- Final Recomputed Total ---\n");
    calculate_total(sales_data, current_size);

    free(sales_data);

    return 0;
}