#include "sort.h"

/**
 * selection_sort - function to selction sort
 * @array : pointer to array integer
 * @size : size of array integer
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, min_location;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_location = i;  /* Start by assuming the minimum element is at index i */
		for (j = i + 1; j < size; j++)  /*unsorted portion of the array*/
		{
			if (array[j] < array[min_location])
			{
				min_location = j;  /* Update the minimum element's index */
			}
		}

		if (min_location != i)  /* Only swap if we found a smaller element */
		{
			/* Swap the elements */
			temp = array[i];
			array[i] = array[min_location];
			array[min_location] = temp;
			print_array(array, size);
		}
	}
}
