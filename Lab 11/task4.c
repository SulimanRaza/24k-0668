#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[50];
    char dob[50];
    int employeeID;
    char department[50];
    float salary;
} Employee;

Employee employee[50];
int count = 0;

void add()
{
    printf("Enter Employee Name: ");
    fgets(employee[count].name, 50, stdin);

    printf("Enter Date of Birth (DD/MM/YYYY): ");
    fgets(employee[count].dob, 50, stdin);

    printf("Enter Employee ID: ");
    scanf("%d", &employee[count].employeeID);
    getchar();

    printf("Enter Employee Department: ");
    fgets(employee[count].department, 50, stdin);

    printf("Enter Employee Salary: ");
    scanf("%f", &employee[count].salary);
    getchar();

    count++;
    printf("Employee Added Successfully\n");
}

void del()
{
    if (count == 0)
    {
        printf("No Employees to delete...");
        return;
    }

    int ID, flag = 0;
    printf("Enter EmplyeeID to Delete: ");
    scanf("%d", &ID);

    for (int i = 0; i < count; i++)
    {
        if (employee[i].employeeID == ID)
        {
            flag = 1;
            for (int j = i; j < count - 1; j++)
            {
                employee[j] = employee[j + 1];
            }
            count--;
            printf("Employee with ID %d deleted successfully.\n", ID);
            break;
        }
    }

    if (!flag)
    {
        printf("Error: Employee with ID %d not found.\n", ID);
    }
}

void display()
{
    if (count == 0)
    {
        printf("No employees to display.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("\nEmployeeID: %d\nName: %sDate of Birth: %sDepartment: %sSalary: $%.2f\n",
        employee[i].employeeID, employee[i].name, employee[i].dob, employee[i].department, employee[i].salary);
    }
}

int main()
{
    int choice;
    do
    {
        printf("\nEmployee Management System\n");
        printf("1. Add an Employee\n");
        printf("2. Delete an Employee\n");
        printf("3. Display All Employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}