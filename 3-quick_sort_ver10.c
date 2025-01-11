#include "sort.h"

void quick_sort_local(int *array, int start, int end);
size_t partition(int *array, size_t start, size_t end);

/**
 * quick_sort - function to quick sort ( Lomuto partition) on array
 * @array : array input
 * @size : size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	int *current = array;

	if ((current == NULL) || (size < 2))
		return;

	quick_sort_local(array, 0, size - 1);
	return;
}	

void quick_sort_local(int *array, int start, int end)
{
	/* size_t i = left, j = right, ;*/
	/* int pivot = array[(left + right) / 2];*/
	int pivot;
	
	if ((array == NULL) || (end < 2))
		return;
	if (start < end)
	{	
		pivot = partition(array, start, end);
		
		/*recursively left and right partition */

		quick_sort_local(array, start, pivot - 1); /*left */
		quick_sort_local(array, pivot + 1, end);
	}
}

size_t partition(int *array, size_t start, size_t end)
{
	int pivotVal = array[end]; /* pivot value of array[end] */
	size_t i = start, j;
	int temp;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivotVal)
		{
			/*if (i != j)  added due segmentation error */
			/*{ */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			/*} */
			i++;	
		}
	}
	

	

	/* swap pivot */
	temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	
	
	return (i);
}
