#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int h, space, hash;
    do
    {
        printf("Enter a number between 1 and 8 : ");
        scanf("%d", &h);
    }
    while(h < 0 || h > 8);
        
    space = h - 1;
    hash = 1;
    
    for (int i = 0; i < h; ++i)
    {
        for(int i = 0; i < space; ++i)
        {
            printf(" ");
        }
        
        for(int i = 0; i < hash; ++i)
        {    
            printf("#");
        }
        printf("  ");
        
        for(int i = 0; i < hash; ++i)
        {    
            printf("#");
        }
        printf("\n");
        
        --space;
        ++hash;
    }  
}
