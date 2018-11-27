#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    char p;

    if (argc != 2)
    {
        printf("Please enter an argument\n");
        return 1;
    }

    string arg = argv[1];

    for (int i = 0, n = strlen(arg); i < n; i++)
    {
        if (!isalpha(arg[i]))
        {
            printf("Argument must be alphanumeric\n");
            return 1;
        }
    }

    //arg = toupper(arg);

    string plainText = get_string("plaintext: ");
    printf("ciphertext: ");

    for(int j = 0, k = 0, x = strlen(plainText); j < x; j++)
    {

        p = plainText[j];
        if (p >= 65 && p <= 122)
        {
            if (islower(p))
            {
                p -= 97;
                printf("%c", (p + toupper(arg[k]) - 65) % 26 + 97);
            }
            else if (isupper(p))
            {
                p -= 65;
                printf("%c", (p + toupper(arg[k]) - 65) % 26 + 65);
            }
            k = (k + 1) % strlen(arg);
        }
        else
        {
          printf("%c", p);
        }
    }
    printf("\n");
}

// wraparound using plainText[j] % strlen(arg)