//libraries
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//formula declarations
int key_check(int a, string b);
string encipher(int key, string plaintext);

//main
int main(int argc, string argv[])
{
    //GET KEY
    int check = key_check(argc, argv[1]); //formula that checks that only 2 arguments in command line and key input by user is a number.

    if (check == 0)
    {
        //GET PLAINTEXT
        string plaintext = get_string("plaintext: ");

        //ENCIPHER & PRINT CIPHERTEXT
        int k = atoi(argv[1]); //converts k to int type.

        printf("ciphertext: %s\n", encipher(k, plaintext)); //carries out encipher function and prints ciphertext.
    }

    else
    {
        return 1; //returns 1 if wrong type of or no key given in command line argument.
    }
}

//formulas
int key_check(int a, string b)
{
    bool check1 = false;
    bool check2 = false;

    //CHECK 1: checks that only 2 arguments are in the command line.
    if (a == 2)
    {
        check1 = true; //if right number of command line arguments given.

        //CHECK 2: checks that string or 'key' characters are all numbers/digits.
        int i = 0;
        while (b[i] != '\0' && b[i] >= '0'
               && b[i] <= '9') //while loop to go through all chars of key and checks each one individually to make sure it is all numbers.
        {
            i++; //if a number then loop continues, if not it exits loop.
        }

        int key_length = strlen(b);
        int check2_len = i;

        if (check2_len == key_length) //check if while loop has looped through entire key by checking i against key length.
        {
            check2 = true; //if i equals key length then check2 is okay. This will not be true if while loop exited early.
        }
    }

    //Final check to ensure both above checks are true.
    if (check1 == true && check2 == true)
    {
        //printf("Success\n");
        //printf("%s\n", b);
        return 0;
    }

    //If both checks not true then user is prompted for a new key.
    else
    {
        printf("Usage: ./caesar key\n"); //prints this if too many or too few command line arguments given.
        return 1;
    }
}

string encipher(string key, string plaintext) //formula to encipher a string of plaintext by an integer 'key'.
{
    string ciphertext = plaintext; //ciphertext begins as copy of plaintext.
    int i = 0;
    while (plaintext[i] != '\0') //while loop to go through all chars of plaintext
    {
        char c = plaintext[i];
        int alpha = isalpha(c); //checks if char is an alphabetical letter.
        int upper = isupper(c); //checks if char is an uppercase letter.

        if (alpha == 0) //if not an alphabetical letter then no change is made. i.e. punctuation and numbers stay as they are.
        {
            ciphertext[i] = c; //changes ciphertext array accordingly.
        }
        else //if alphabetical letter then following is undertaken.
        {
            if (upper != 0) //if uppercase letter
            {
                char l = c - 64; //64 used based an ASCII decimal chart
                char ciph = 64 + ((l + key) % 26); //formula used to ensure that if 1 is added to Z then it changes to A in a wrap around.
                ciphertext[i] = (ciph == 64) ? 'Z' : ciph; //had a few problems with the modulus == 0, so added this to output 'Z'.
            }
            else
            {
                char l = c - 96; //64 used based an ASCII decimal chart
                char ciph = 96 + ((l + key) % 26); //formula used to ensure that if 1 is added to 'z' then it changes to 'a' in a wrap around.
                ciphertext[i] = (ciph == 96) ? 'z' : ciph; //had a few problems with the modulus == 0, so added this to output 'z'.
            }
        }

        i++;
    }
    return ciphertext; //returns string ciphertext which is dictated by key given.
}
