#include<stdio.h>

int main()
{
    int i,j,k;

    for( i = 0; i < 1500; i++ )
    {
        if( i % 3 == 2 && i % 5 == 3 && i % 7 == 2 )
        {
            printf("%d\n",i);            
        }
    }
    
    return 0;
}