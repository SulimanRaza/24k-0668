#include <stdio.h>
#include <string.h>
void reverse(const char name[], int n)
{
    if (n >= 0)
    {
        printf("%c", name[n]);
        reverse(name, n - 1);
    }
}
int main()
{
    char name[255];
    printf("Enter a sentence: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';
    int n = strlen(name) - 1;
    printf("\n");
    reverse(name, n);
    return 0;
}