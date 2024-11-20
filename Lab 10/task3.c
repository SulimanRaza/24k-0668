#include <stdio.h>
#include <string.h>
#define max_cars 50
struct dealership
{
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
};
struct dealership car[max_cars];
int count = 0;
void add()
{
    if (count >= max_cars)
    {
        printf("\nDealership is full");
        return;
    }
    else
    {
        printf("Enter make of the car: ");
        scanf("%s", car[count].make);

        printf("Enter model of the car: ");
        scanf("%s", car[count].model);

        printf("Enter year of the car: ");
        scanf("%d", &car[count].year);

        printf("Enter price of the car: ");
        scanf("%f", &car[count].price);

        printf("Enter mileage of the car: ");
        scanf("%f", &car[count].mileage);

        count++;
        printf("Car add to dealership successfully!\n");
    }
}
void display()
{
    if (count == 0)
    {
        printf("Dealership is empty\n");
        return;
    }
    else
    {
        printf("Displaying available cars\n");
        for (int i = 0; i < count; i++)
        {
            printf("%d. Make: %s, Model: %s, Year: %d, Price: $%.2f, Mileage: %.2f miles\n", i + 1, car[i].make, car[i].model, car[i].year, car[i].price, car[i].mileage);
        }
        printf("\n");
    }
}
void search()
{
    char search1[50];
    int flag = 0;
    printf("Enter make or model of car: ");
    scanf("%s", &search1);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(car[i].make, search1) == 0 || strcmp(car[i].model, search1) == 0)
        {
            printf("Car found!!\n");
            printf("Make: %s, Model: %s, Year: %d, Price: %.2f, Mileage: %.2f miles\n", car[i].make, car[i].model, car[i].year, car[i].price, car[i].mileage);
            flag = 1;
        }
    }
    if (!flag)
    {
        printf("\nCar not found!!");
        return;
    }
    printf("\n");
}

int main(void)
{
    int choice;
    do
    {
        printf("---Car Dealership Management System---\n");
        printf("1. Add a new Car\n");
        printf("2. Display available Cars\n");
        printf("3. Search for a car by make or model\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
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
            printf("\nExiting the system\n\nGoodbye!!");
        }
        else
        {
            printf("Invlaid choice, Please try again.\n");
        }

    } while (choice != 4);
}