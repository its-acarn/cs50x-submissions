#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //all figures shown as number of pennies.
    int quarter = 25, dime = 10, nickel = 5, penny = 1;
    int change_int, coins;
    float change_float;

    do //prompts user for a positive float number of the change required.
    {
        change_float = get_float("Change owed: ");
    }
    while (change_float == 0 || change_float < 0);

    change_int = round(change_float * 100); //converts float to int

    int change_rem, num_q, num_d, num_n, num_p;

    if (change_int >= quarter) //code for quarters
    {
        num_q = change_int / quarter;
        change_rem = change_int % quarter;
    }
    else
    {
        change_rem = change_int;
        num_q = 0;
    }

    if (change_rem >= dime) //code for dimes
    {
        num_d = change_rem / dime;
        change_rem = change_rem % dime;
    }
    else
    {
        num_d = 0;
    }

    if (change_rem >= nickel) //code for nickels
    {
        num_n = change_rem / nickel;
        change_rem = change_rem % nickel;
    }
    else
    {
        num_n = 0;
    }
    if (change_rem >= penny) //code for pennies
    {
        num_p = change_rem / penny;
    }
    else
    {
        num_p = 0;
    }

    coins = num_q + num_d + num_n + num_p;
    printf("%i\n", coins);
}
