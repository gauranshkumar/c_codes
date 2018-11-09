/* Program for insertion, selection and bubble sort */
#include <stdio.h>
#include <math.h>

/* Function to sort an array using insertion sort*/
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

// Function for Bubble Sort

void bubble_sort(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function for Selection Sort

void selection_sort(int arr[], int size)
{
    int i, j, temp, min, loc;

    for (i = 0; i < size - 1; i++)
    {
        min = arr[i];
        loc = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
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

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
    int i, n;
    printf("\nEnter The Size Of Array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the values : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int arr2[n];
    int arr3[n];
    for (i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }
    printf("\n\n\nArray Before Insertion Sort : \n");
    printArray(arr, n);
    insertion_sort(arr, n);
    printf("\n\n\nArray After Insertion Sort : \n");
    printArray(arr, n);

    printf("\n\n\nArray Before Selection Sort : \n");
    printArray(arr2, n);
    selection_sort(arr2, n);
    printf("\n\n\nArray After Selection Sort : \n");
    printArray(arr2, n);

    printf("\n\n\nArray Before Bubble Sort : \n");
    printArray(arr3, n);
    bubble_sort(arr3, n);
    printf("\n\n\nArray After Bubble Sort : \n");
    printArray(arr3, n);

    return 0;
}
