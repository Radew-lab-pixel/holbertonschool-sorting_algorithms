#include "sort.h"

void quick_sort_local(int *array, size_t low, size_t high);
int partition(int *array, size_t low, size_t high);

/**
 * quick_sort - function to quick sort (Lomuto partition) on array
 * @array : array input
 * @size : size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_local(array, 0, size - 1);
}

void quick_sort_local(int *array, size_t low, size_t high)
{
    if (low < high)
    {
        size_t pivot = partition(array, low, high);
        quick_sort_local(array, low, pivot - 1);
        quick_sort_local(array, pivot + 1, high);
    }
}

int partition(int *array, size_t low, size_t high)
{
    size_t i, j;
    int pivot_val, temp;

    pivot_val = array[high];  /* Pivot is the last element */
    i = low;  /* Counter for elements less than the pivot */

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot_val)
        {
            /* Swap array[i] and array[j] */
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;  /* Increment i for the next element less than pivot */
        }
    }

    /* Swap the pivot element into its correct position */
    temp = array[i];
    array[i] = array[high];
    array[high] = temp;

    return i;  /* Return the pivot index */
}

