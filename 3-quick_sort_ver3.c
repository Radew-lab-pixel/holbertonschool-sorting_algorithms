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
	size_t i, j; /* left, right; */

	/*size_t origin_size; */
	/* int *origin_array , origin_flag; */

	/*if ((!array) || (size < 1) */
	if ((array == NULL) || (size < 2))  
		return;



	pivot = current[size - 1]; /* end of array as pivot */
	j = 0; /* if not segmentation error */ 

	for (i = 0; i < size - 1; i++)
	{
		if (current[i] <= pivot)
		{
			temp = current[i]; /* swap */
			current[i] = current[j];
			current[j] = temp;

			j++;

			/*print_array(array, size);*/
			/*print_array(current, origim */
		}
	}
	/** swap pivot with array[j] as array[j] > pivot */
	/*temp = current[size - 1]; */
	temp = current[j];
	current[j] = current[size - 1];
	current[size - 1] = temp;
	/* current[size - 1] = current[j]; */
	/* current[j] = temp; */

	print_array(array, size);
	
	/* sort the partitions */
	
	quick_sort(current, j); /* Sort left partition */
    	quick_sort(current + j + 1, size - j - 1);  /* Sort right partition */
	
	/*left = j; */
	/*right = size - 1 - left; */
	/* quick_sort(current, left); */
	/*quick_sort(current + j, size - j - 1);*/
	/*quick_sort(current + left, right); */
}
