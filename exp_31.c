#include <stdio.h>

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int linear_search(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (val == arr[i])
        {
            return i;
            break;
        }
    }
    return -1;
}

void printArray(int arr[], int n) 
{ 
int i; 
for (i=0; i < n; i++) 
	printf("%d\t", arr[i]); 
printf("\n"); 
} 

int binary_search(int arr[], int val, int size)
{
    int left = 0, right = size-1, mid;    
    while (left <= right)
    {
        mid = (left + right)/2;
        if (arr[mid] == val)
        {
            return mid;
            break;
        }
        else if (arr[mid] > val)
        {
            right = mid - 1;
        }
        else if (arr[mid] < val)
        {
            left = mid + 1;
        }
    }
    return -1;
}

void main()
{
    int size, i, num, select;
    printf("Enter The Size Of Array : ");
    scanf("%d", &size);

    int array[size];

    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\n\nEnter The Number to Search : ");
    scanf("%d", &num);
    printf("\n\n1.) Linear Search\n2.) Binary Search \n\nEnter Method To Use : ");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        if (linear_search(array, size, num) == -1)
        {
            printf("\n\nElement not found in the array.\n\n");
        }
        else
        {
            printf("\n\nElement found at index : %d \nUsing Linear Search.\n\n", linear_search(array, size, num));
        }
        break;

    case 2:
        insertion_sort(array, size);
        printArray(array, size);
        if (binary_search(array, size, num) == -1)
        {
            printf("\n\nElement not found in the array.\n\n");
        }
        else
        {
            printf("\n\nElement found at index : %d \nUsing Binary Search.\n\n", binary_search(array, size, num));
        }
        break;

    default:
    break;
    }
}