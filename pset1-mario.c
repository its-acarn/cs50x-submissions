#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    int width;
    int spaces;

    do //asks for height of pyramid and will repeat question until receives a satisfactory integer between 1 & 8.
    {
        height = get_int("Height: ");
        width = height - 1;
        spaces = height - width;
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++) //creates new line when space and hash loops are complete.
    {
        for (int j = spaces; j < height; j++) //creates appropriate number of spaces based on height.
        {
            printf(" ");
        }
        for (int k = width; k < height; k++) //creates appropriate number of (right-aligned) hashes based on height.
        {
            printf("#");
        }

        printf("  ");

        for (int k = width; k < height; k++) //creates appropriate number of (left-aligned) hashes based on height.
        {
            printf("#");
        }

        printf("\n");

        width--;
        spaces++;
    }
}

