#include <stdio.h>

void selection_sort(int arr[], int size)
{
    int i,j,temp,min,loc;

    for(i=0;i<size-1;i++)
    {
        min = arr[i];
        loc = i;
        for(j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                loc = j;
                min = arr[j];
            }
        }

        temp = arr[i];
        arr[i] = arr[loc];
        arr[loc] = temp;
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

    selection_sort(arr, size);

    printf("\n\nAfter Sort : \n");
    for(i=0;i<size;i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n\n");

}
