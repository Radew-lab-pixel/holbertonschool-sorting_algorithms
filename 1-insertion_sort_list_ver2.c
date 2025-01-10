#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list; /* a copy of the list */
	listint_t *previous, *key = NULL, *tempNext = NULL, *tempPrev = NULL;
	int swapped = 0;

	if (head == NULL)
		return;
	
	key = head->next; /* start from second node */
	/*previous = current;  store current address as previous */
	previous = head; 

	while (key != NULL)
	{	
		if (previous->n > key->n)
		{	
			if (key->next != NULL)
			{	
				tempNext = key->next; /* kept address of key->next */
				tempPrev = previous->prev; /* kept address of previous->prev */

				key->prev = tempPrev; /* swapped key->prev point to tempPrev */
				tempPrev->next = key; /* tempPrev point to key */
				key->next = previous; /* swap key->next point to swap previous */

				previous->next = tempNext; /* swap previous point to tempNext */
				tempNext->prev = previous; /* tempNext->prev point to swap previous */
				previous->prev = key; /* swap previous->next point to swap key */
			
				print_list(head);
				printf("Swapped : %d\n", swapped); /* for debugging */
		
			}
		}
		previous = key;
		key = key->next;

	}
}

/**
*for (int step = 1; step < size; step++) {
*    int key = array[step];
*    int j = step - 1;
*
*    // Compare key with each element on the left of it until an element smaller than
*    // it is found.
*    // For descending order, change key<array[j] to key>array[j].
*    while (j >=0 && key < array[j]) {
*      array[j + 1] = array[j];
*      --j;
*    }
*    array[j + 1] = key;
*  }
*/
