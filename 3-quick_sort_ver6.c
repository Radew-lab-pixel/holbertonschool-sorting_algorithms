#include "sort.h"

void quick_sort_local(int *array, size_t low, size_t high);
int partition(int *array, size_t low, size_t high);

/**
 * quick_sort - function to quick sort ( Lomuto partition) on array
 * @array : array input
 * @size : size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
        /*int *origin_array = array;*/
        /*size_t origin_size = size;*/
	int *current = array;
	size_t low, high;

        if ((current == NULL) || (size < 2))
                return;

	low = 0; /* lowest array */
	high = size -1; /* highest array */

        quick_sort_local(current, low, high);
	
}

void quick_sort_local(int *array, size_t low, size_t high)
{
	size_t pivot;

	if (array == NULL)
		return;
	if (low < high)
		{
			pivot = partition(array, low, high);

			quick_sort_local(array, low, pivot - 1);
			quick_sort_local(array, pivot + 1, high);
		}
}

int partition(int *array, size_t low, size_t high)
{
	size_t pivot, i, j;
	int pivot_val, temp;

	if (array == NULL)
		return 0;

	pivot = high; /* pivot is last array */
	pivot_val = array[pivot];
	i = low; /* counter of low array */

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_val)
		{
			temp = array[j];
			array[j] = array[i];
			array[j] = temp;
			i++;	
		}
	}
	temp = array[i]; /* swapped pivot */
	array[i] = array[pivot];
	array[pivot] = temp;
	
	return i;

}
