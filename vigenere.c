#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int klen = strlen(argv[1]);
        
        for (int i = 0; i < klen; ++i)
        {
            if (isalpha(argv[1][i]) == 0)
            {
                printf("Usage ./vigenere key \n");
                return 1;
            }
        }
        
        string str = get_string("Enter string:");
        
        int strl = strlen(str);
        
        string ciph = str;
        
        for (int i = 0, j = 0; i < strl; ++i)
        {
            char k;
            
            if (isupper(argv[1][j]))
                k = argv[1][j] - 65;
            else if (islower(argv[1][j]))
                k = argv[1][j] - 97;
            
            if (isupper(ciph[i]))
            {
                ciph[i] = (ciph[i] - 65 + k) % 26 + 65;
                j = (j + 1) % klen;
            }
        }
        
        printf("ciphertext: %s\n", str);
    }
    
    else 
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
}
