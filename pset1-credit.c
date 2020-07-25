#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //prompt to get credit card number from user.
    long number;

    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);

    //declaration of variable needed for following script.
    long num = number, start = number, digit;
    int i, k, length, mult, total = 0, total2 = 0;

    //for loop through the credit card number to split it into each digit.
    for (i = 0; num > 0; i++)
    {
        digit = num % 10;
        int mod = i % 2;

        //switch statement takes each split digit to perform Luhn's algorithm
        switch (mod)
        {
            case 0:
                total = total + digit;
                break;
            case 1:
                mult = digit * 2;
                if (mult > 9)
                {
                    for (int j = 0; mult > 0; j++)
                    {
                        int add_digit = mult % 10;
                        mult = mult / 10;
                        total2 = total2 + add_digit;
                    }
                }
                else
                {
                    total2 = total2 + mult;
                }
                break;
        }
        num = num / 10;
    }

    //length of credit card number is given by value of i.
    length = i;

    //check that Luhn's algrothm gives valid answer.
    int check = total + total2;

    if (check % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        //determines the starting two digits of the input number
        while (start >= 100)
        {
            start = start / 10;
        }

        //determines what card the starting two digits relate to & checks length of number submitted
        switch (start)
        {
            case 34:
            case 37:
                (length == 15) ? printf("AMEX\n") : printf("INVALID\n");
                break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                (length == 16) ? printf("MASTERCARD\n") : printf("INVALID\n");
                break;
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
                (length == 13 || length == 16) ? printf("VISA\n") : printf("INVALID\n");
                break;
            default:
                printf("INVALID\n");
                break;
        }
    }
}
