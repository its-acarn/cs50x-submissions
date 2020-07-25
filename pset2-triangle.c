#include <stdio.h>
#include <cs50.h>

bool valid_triangle(double a, double b, double c);

int main(void)
{
    double a = get_int("First length of triangle: ");
    double b = get_int("Second length of triangle: ");
    double c = get_int("Third length of triangle: ");

    bool tf = valid_triangle(a, b, c);
    string ret = (tf ? "true" : "false");

    printf("It is %s that the triangle is valid.\n", ret);

}

bool valid_triangle(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    else if ((a + b < c) || (a + c < b) || (b + c < a))
    {
        return false;
    }
    else
    {
        return true;
    }
}
