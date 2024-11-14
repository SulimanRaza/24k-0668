#include <stdio.h>
#include <string.h>
int main()
{
    char user[5][255] = {"suliman", "ayaan", "arshan", "sufyan", "fatima"}, name[255];
    int flag = 0;
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(name, user[i]) == 0)
        {
            flag = 1;
        }
    }
    if (flag)
    {
        printf("\n Name found");
    }
    else
    {
        printf("\n Name not found");
    }
    return 0;
}