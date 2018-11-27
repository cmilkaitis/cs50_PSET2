#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please enter an argument\n");
        return 1;
    }

    int num = atoi(argv[1]);

    string plainText = get_string("plaintext: ");
    printf("ciphertext: ");

    char c;
    for(int i = 0, n = strlen(plainText); i < n; i++)
    {
        c = plainText[i];
        if(c >= 65 && c <= 122)
        {
            if(isupper(c))
            {
              c -= 65;
              printf("%c", ((c + num) % 26) + 65);
            }
            else
            {
              c -= 97;
              printf("%c", ((c + num) % 26) + 97);
            }
        }
        else
        {
          printf("%c", c);
        }
    }
    printf("\n");
}