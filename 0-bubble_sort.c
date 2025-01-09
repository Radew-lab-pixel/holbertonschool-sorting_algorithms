#include "sort.h"

/**
 * bubble_sort - sort arrays in ascending order using Bubble sort
 * @array : pointer to the array of integer
 * @size : size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int *current = array;
	size_t i, j; /* count = 0; */
	int temp;

	/* i <- 1 to size -1 */
	for (i = 0; i < size; i++)
	{
		/*swapped = 0; */
		for (j = 0; j < (size - i); j++)
		{
			if (current[j] > current[j + 1])
			{
				temp = current[j];
				current[j] = current[j + 1];
				current[j + 1] = temp;
				/*swapped = 1; */
				print_array(current, size);
			}
			/*
			*if (swapped ==  0)
			*	break;
			*if (swapped == 1)
			*{
				*print_array(current, size);
				* while (count < (size - 1))
				*{
				*	printf("%d, ", current[count]);
				*	count++;
				*}
			*}
			*/
		}

	}
}
