#include <stdio.h>
#include <string.h>
typedef struct
{
    char partnum[50];
    char description[50];
    int quantity;
    float price;
} invoice;
invoice i;
void display()
{
    strcpy(i.partnum, "xyz321");
    strcpy(i.description, "FIFA Worldcup 2014 FootBall");
    i.price = 250.60;
    i.quantity = 8;
    float invoice_amount = i.price * i.quantity;
    if (invoice_amount < 0)
    {
        invoice_amount = 0;
    }
    if (i.quantity < 0)
    {
        i.quantity = 0;
    }
    printf("Invoice includes the following:\n");
    printf("part number: %s \ndescription: %s \nquantity: %i \nprice: %.2f \ninvoice amount: %.2f\n", i.partnum, i.description, i.quantity, i.price, invoice_amount);
}
int main()
{
    display();

    return 0;
}