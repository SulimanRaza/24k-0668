#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num_points;
    float *fees, total_profit = 0;
    printf("Enter the total number of points in the facility: ");
    scanf("%d", &num_points);
    if (num_points <= 0)
    {
        printf("Invalid number of points. Please enter a positive number.\n");
        return 1;
    }
    fees = (float *)malloc(num_points * sizeof(float));
    if (fees == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < num_points; i++)
    {
        do
        {
            printf("Enter fee for point %d: $", i + 1);
            scanf("%f", &fees[i]);

            if (fees[i] < 0)
            {
                printf("Fee cannot be negative. Please enter a valid fee.\n");
            }
        } while (fees[i] < 0);

        total_profit += fees[i];
    }
    printf("Total Profit for the facility: $%.2f\n", total_profit);
    free(fees);
    return 0;
}
