#include <stdio.h>
#include <string.h>
int main()
{
    char user[] = "admin", username[255];
    char pass[] = "1234", password[255];
    printf("Enter Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';
    printf("Enter Passwaord: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';
    if (strcmp(pass, password) == 0 && strcmp(user, username) == 0)
    {
        printf("Access Granted\n");
    }
    else
    {
        printf("Access Denied");
    }
    return 0;
}