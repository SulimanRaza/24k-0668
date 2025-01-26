#include <stdio.h>
#include <stdlib.h>
struct rectangle
{
    float length;
    float width;
};
void areaofrectangle(float l, float w)
{
    float area = l * w;
    printf("Area of Rectangle is %.2f\n", area);
}
void perimeterofrectangle(float l, float w)
{
    float peri = 2 * (l + w);
    printf("Perimeter of Rectangle is %.2f\n", peri);
}
void check(float l, float w)
{
    if (l <= 0 || l > 20 || w <= 0 || w > 20)
    {
        printf("Verification Failed...\nWidth and length must be in between 0 and 20\n");
        exit(1);
    }
    else
    {
        printf("Verified...\n");
    }
}
int main()
{
    float len, wid;
    printf("Enter length of rectangle: ");
    scanf("%f", &len);
    printf("Enter width of rectangle: ");
    scanf("%f", &wid);
    check(len, wid);
    areaofrectangle(len, wid);
    perimeterofrectangle(len, wid);
    return 0;
}