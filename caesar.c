#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string str;
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        printf("\n");
        return 0;
    }

    int k = atoi(argv[1]);
    if (k < 0)
    {
        printf("Wrong key entered.");
        return 0;
    }
    
    str = get_string("Enter text:");
    
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
    {
        if (islower(str[i]))
            printf("%c", (str[i] - 'a' + k) % 26 + 'a');
        else if (isupper(str[i]))
            printf("%c", (str[i] - 'A' + k) % 26 + 'A');
        else 
            printf("%c", str[i]);
    }
        
    printf("\n");
    
    return 0;
}
