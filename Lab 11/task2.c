#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char line[50];
    int n = 1;
    f = fopen("Suliman.txt", "r");
    if (f == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    while (fgets(line, sizeof(line), f) != NULL)
    {
        printf("%d: %s", n++, line);
    }
    fclose(f);

    return 0;
}