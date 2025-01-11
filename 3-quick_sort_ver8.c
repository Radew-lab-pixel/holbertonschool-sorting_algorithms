#include "sort.h"

void quick_sort_local(int *array, int left, int right);

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

	quick_sort_local(current, 0, size - 1);
	return;
}	

void quick_sort_local(int *array, int left, int right)
{
	int i = left, j = right;
	int pivot = array[(left + right) / 2];
	int temp;
	
	/**
	* if (left > right)
	* {
	*	temp = array[left];
	*	array[left] = array[right];
	*	array[right] = temp;
	*}
	*/
	
	/* partition the array */
	while (i <= j)
	{
		while (array[j] < pivot) /* start left < pivot */
			i++;
		while (array[j] > pivot) /* end right > pivot */
			j--;
		if (i <= j)
		{
			temp = array[i]; /* swap array[i] and array[j] */
			array[i] = array[j];
			array[j] = temp;

			i++;
			j--;
		}
	}

	/* recursively sort sub array */
	if (left < j)
		quick_sort_local(array, left, j);
	if (i < right)
		quick_sort_local(array, i, right);

}
