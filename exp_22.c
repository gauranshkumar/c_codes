#include<stdio.h>

int fact(int num)
{
    if (num <= 1)
    {
        return 1;
    }

    return num*fact(num-1);
    num--;
    

}

void main()
{
    printf("%d\n\n", fact(10));

}
