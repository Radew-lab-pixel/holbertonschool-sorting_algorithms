#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *key = NULL, *tempNext = NULL, *tempPrev = NULL;
	int swapped = 0;

	if (current == NULL)
		return;
	
	key = current->next; /* start from second node */
	/*previous = current;  store current address as previous */

	while (key != NULL)
	{
		if (current->n > key->n)
		{
			tempNext = key->next; /* stored key->next address bef0re swap */
			tempPrev = current->prev; /* stored current->prev address before swap*/
			
			key->prev = tempPrev; /* swapped key->prev point to tempPrev */
			key->next = current; /* key->next point to swapped current */
			tempPrev->next = key; /* tempPrev->next point to key */

			current->prev = key; /* swapped current->prev point to key */
			current->next = tempNext; /* swapped current->next point to tempNext */
			tempNext->prev = current; /* tempNext->prev point to swap current */

			swapped = 1;
			print_list(*list);
			printf("Swapped : %d\n", swapped); /* for debugging */
		}

		current = current->next; /* go to next node */
		key = current->next;
		if ((key == NULL) || (current == NULL))
			break;
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
