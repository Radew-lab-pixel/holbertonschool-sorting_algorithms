#include "sort.h"

void selection_sort(int *array, size_t size)
{	
	int *dest = array;
	int temp;
	size_t i, j, min_location;
	/*int *temp = (int *)malloc(size * sizeof(int));*/
	int cur_min;

	for (i = 0; i < size - 1; i++)
	{	
		cur_min = dest[i];
		for (j = 1; j < size - 1; j++)
		{
			if (dest[j] < cur_min)
			{
				cur_min = dest[j];
				min_location = j;		
			}
		}
		if (dest[min_location] <  dest[i]) 
		{
			temp = dest[i];
			dest[i] = dest[min_location];
			dest[min_location] = temp;
			print_array(dest, size);
		}
	}
	return;

}
