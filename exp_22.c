/*A Program for Bubble Sort*/
#include <stdio.h>

void bubble_sort(int arr[], int size)
{
    int i,j,temp;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void main()
{
    int   i, size;
    printf("\nEnter The Size Of Array : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the values : \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    bubble_sort(arr, size);

    printf("\n\nAfter Sort : \n");
    for(i=0;i<size;i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n\n");

}
