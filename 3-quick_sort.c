#include "sort.h"

void quick_sort_local(int *array, int start, int end, size_t size);
size_t partition(int *array, size_t start, size_t end, size_t size);

/**
 * quick_sort - function to quick sort ( Lomuto partition) on array
 * @array : array input
 * @size : size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int *current = array;

	/* if ((current == NULL) || (size < 2)) failed 2 elements checker ?*/
	if ((current == NULL) || (size <= 1))
		return;

	quick_sort_local(array, 0, size - 1, size);
}

/**
 * quick_sort_local - subfunction to allow recursive sorting
 * @array : array input
 * @start : position of start array
 * @size : original size of the array
 * @end : position of end array
 * Return: void
 */

void quick_sort_local(int *array, int start, int end, size_t size)
{
	/* size_t i = left, j = right, ;*/
	/* int pivot = array[(left + right) / 2];*/
	int pivot;

	/*if ((array == NULL) || (end < 2)) failed 2 elements checker */
	if ((current == NULL) || (size <= 1))

		return;
	if (start < end)
	{
		pivot = partition(array, start, end, size);

		/*recursively left and right partition */
		quick_sort_local(array, start, pivot - 1, size); /* left */
		quick_sort_local(array, pivot + 1, end, size); /* right */
	}
}

/**
 * partition - partitioning using Lomuto sorting
 * @array : array input
 * @start : position of start array
 * @end : position of end array
 * @size : original size of array
 * Return: position of updated pivot
 */

size_t partition(int *array, size_t start, size_t end, size_t size)
{
	int pivotVal = array[end]; /* pivot value of array[end] */
	size_t i = start, j;
	int temp;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivotVal)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)  /*added to comply with output in checker */
				print_array(array, size);

			i++;
		}
	}
	if (pivotVal < array[i]) /* added to comply with output checker */
	/* if (pivotVal < array[i] + 1)  result ok but fail checker*/
	{
		/* swap pivot */
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (i);
}
