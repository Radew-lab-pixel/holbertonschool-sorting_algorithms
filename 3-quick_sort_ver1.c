#include "sort.h"

/**
 * quick_sort - function to quick sort ( Lomuto partition) on array
 * @array : array input
 * @size : size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int *current = array; /* copy of array */
	int pivot, temp;
	size_t i, j;

	if ((!array) || (size < 1))
		return;
	pivot = current[size - 1]; /* end of array as pivot */

	for (i = 0; i < size - 1; i++)
	{
		if (current[i] <= pivot)
		{
			temp = current[i]; /* swap */
			current[i] = current[j];
			current[j] = temp;

			j++;

			print_array(current, size);
		}
	}
	/** swap pivot with array[j] as array[j] > pivot */
	temp = current[size - 1];
	current[size - 1] = current[j];
	current[j] = temp;

	print_array(current, size);

	/* sort the partitions */
	quick_sort(current, j);
	/*quick_sort(current + j, size - j - 1);*/
}
