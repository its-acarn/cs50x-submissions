#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Function declarations
double count_letters(string a);
double count_words(string a);
double count_sentences(string a);

int main(void)
{
    //User inputs string to be graded.
    string text = get_string("Text: ");

    //Using declared functions the properties (L & S) to be used in the Coleman-Liau index are deduced.
    double c = count_letters(text); //number of letters in text.
    double w = count_words(text); //number of spaces in text.
    printf("Words = %f\n", w);
    double s = count_sentences(text); //number of sentences in text.

    double L = 100 * (c / w); //equation gives the average number of letters per 100 words.
    double S = 100 * (s / w); //equation gives the average number of sentences per 100 words.

    //Coleman-Liau index formula
    int index = round(0.0588 * L - 0.296 * S - 15.8); //round() used to ensure numbers are 'rounded up'.

    //If function decides what to print with regards the Grade output from Coleman-Liau index.
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//This function counts the letters in a given string. It does not count any digits or punctuation only a-z and A-Z characters.
double count_letters(string a)
{
    double no_letters = 0;

    for (int i = 0; a[i] != '\0'; i++) //looks for characters in string as a string is simply an array of chars.
    {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A'
                                             && a[i] <= 'Z')) //lesser than and greater than symbols used because the characters refer to ASCII numbers.
        {
            no_letters++; //if a character a-z or A-Z is present then no_letters value increases by 1.
        }
    }

    return no_letters;
}

//This function counts the words in a given string.
double count_words(string a)
{
    double no_words = 1;

    if (a[0] == ' ') //checks if space at start of string and assigns no_words value of 0 if true.
    {
        no_words = 0;
    }

    for (int i = 0; a[i] != '\0'; i++)
    {


        if (a[i] == ' '
            && a[i + 1] != ' ') //looks for the occasions where a space is followed by a character and assumes one word to start.
        {
            no_words++; //if function satisfied then no_sentences value increases by 1.
        }
    }

    return no_words;
}

//This function counts the number of sentences in a given string End of sentences are '.' '?' and '!'.
double count_sentences(string a)
{
    double no_sentences = 0;

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '.' || a[i] == '!' || a[i] == '?') //end of sentences are only given by ? ! and .
        {
            no_sentences++; //if ? ! or . present then no_sentences value increases by 1.
        }
    }

    return no_sentences;
}
