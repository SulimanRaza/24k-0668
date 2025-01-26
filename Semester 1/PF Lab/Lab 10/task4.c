#include <stdio.h>
#include <string.h>
#define max 100

struct travel
{
    char name[50];
    char destination[50];
    int duration;
    float price;
    int seats;
};

struct travel travels[max];
int count = 0;

void add()
{
    if (count >= max)
    {
        printf("\nPackages are full, no more packages can be added.\n");
        return;
    }

    printf("Enter the name of the package: ");
    scanf("%s", travels[count].name);

    printf("Enter the destination of the package: ");
    scanf("%s", travels[count].destination);

    printf("Enter the duration of the package in days: ");
    scanf("%d", &travels[count].duration);

    printf("Enter the price of the package: ");
    scanf("%f", &travels[count].price);

    printf("Enter the number of seats available for the package: ");
    scanf("%d", &travels[count].seats);

    count++;
    printf("Package added successfully!\n\n");
}

void display()
{
    if (count == 0)
    {
        printf("\nNo package to display.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d. Name: %s, Destination: %s, Duration: %d days, Price: $%.2f, Available Seats: %d\n", i + 1, travels[i].name, travels[i].destination, travels[i].duration, travels[i].price, travels[i].seats);
    }
    printf("\n");
}

void search()
{
    int ser;
    if (count == 0)
    {
        printf("\nNo packages available.\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d. Name: %s, Destination: %s, Duration: %d days, Price: $%.2f, Available Seats: %d\n", i + 1, travels[i].name, travels[i].destination, travels[i].duration, travels[i].price, travels[i].seats);
    }
    printf("\nEnter the package number to book (1 to %d): ", count);
    scanf("%d", &ser);

    if (ser < 1 || ser > count)
    {
        printf("\nInvalid package number. Please enter a valid input.\n");
    }
    else
    {
        int index = ser - 1;
        printf("Package booked: Name: %s, Destination: %s, Duration: %d days, Price: $%.2f, Available Seats: %d\n", travels[index].name, travels[index].destination, travels[index].duration, travels[index].price, travels[index].seats);
    }
    printf("\n");
}

int main(void)
{
    int choice;
    do
    {
        printf("Travel Management System\n");
        printf("1. Add a new package\n");
        printf("2. Display all packages\n");
        printf("3. Book a package\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            add();
        }
        else if (choice == 2)
        {
            display();
        }
        else if (choice == 3)
        {
            search();
        }
        else if (choice == 4)
        {
            printf("\nGoodbye!\n");
        }
        else
        {
            printf("\nPlease enter a valid input.\n");
        }
    } while (choice != 4);

    return 0;
}
