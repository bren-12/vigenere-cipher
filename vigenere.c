#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    //Takes in string passed in command line
    string key = argv[1];

    //limits parameter to one arguement from command line
    if(argc != 2)
    {
        printf("ERROR: Please enter 1 arguement\n");
        return(1);
    }
    else
    {
        //runs through string pulling in char
        for(int x = 0; x < strlen(key); x++ )
        {
            //take char out
            //look at this if there is an error
            char ch = toupper(key[x]);

            //checks to make sure char is a valid letter
            if(((int)ch >= 65 && (int)ch <= 90) || ((int)ch >= 97 && (int)ch <= 122)  )
            {
                //DELETE TESTING ONLYprintf("No bad char included!");

            }
            else
            {
                printf("Error: bad character entered");
                return(1);
            }
        }

    }

    //TEST PRINT BELOW
    //printf("key: %s\n", key);

    //stores length of key[] for use to convert later
    int keylen =  strlen(key);
    int keynum[keylen];
    //runs through key array and converts char to int and stores in keynum array
    for(int x = 0; x < keylen; x++)
    {
        char bgchar = toupper(key[x]);
        int num = bgchar;
        keynum[x] = num;

        //prints letter with number in the keynum array
        //printf("1L: %c 1N: %i\n",bgchar, keynum[x]);
    }




    //printf("1n: %i\n",keynum[0]);
    //Takes word in from parameter
    //string word = argv[1];

    printf("plaintext: ");
    string word = get_string();
    //printf("Word entered: %s\n", word);
    int wrdlen= strlen(word);
    //Print word length for testing
    //printf("Word length: %i\n", wrdlen);
    char letter;


    int cshift;
    int i;
    int count = 0;
    int t = keylen;
    //Loops through each letter in plaintext
    for (i = 0; i < wrdlen; i++)
    {
        //take letter and changes to ascii int
        int c = word[i];
        if(i >= keylen)
        {
            //breakpoint print
            //printf("Oveflow\n");
            count = 0;
            keylen=(keylen + t);
            cshift = keynum[count] - 65;
        }
        if(i < keylen)
        {
            //printf("Count: %i\n",count);
            //printf("i: %i\n", i);
            cshift = keynum[count] - 65;
            //test print
            //printf("%i\n",cshift);
        }
        //checks if c is a capital letter
        if(c >= 65 && c <= 90 )
        {
            //checks to see if adding shift overflows outside cap letter range
            if( c + cshift > 90 )
            {
                int cshift2 = c + cshift;
                cshift2 = cshift2 - 26;
                word[i] = cshift2;
            }
            else
            {
                word[i] = c + cshift;
            }
        }

        //checks if c is a lowercase letter
        if(c >= 97 && c <= 122 )
        {
            //checks to see if adding shift overflows outside cap letter range
            if( c + cshift > 122 )
            {
                int cshift2 = c + cshift;
                cshift2 = cshift2 - 26;
                word[i] = cshift2;
            }
            else
            {
                word[i] = c + cshift;
            }
        }
        count=count+1;
        //printf("count: %i\n",count);
    }
    printf("Ciphertext: %s\n", word);
    return(0);

}
