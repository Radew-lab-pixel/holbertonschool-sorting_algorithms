#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *key, *nextNode, *sorted;
	/* listint_t *copy = *list; */
	listint_t *current = *list; /* copy of list */

	key = NULL; /* node for second node of list */

	while (current != NULL)
	{
		nextNode = current->next;
		
		if (key == NULL || key->n >= current->n)
		{
			current->next = key;
		
			if (key != NULL) /* key not empty */
				key->prev = current;
			
			key = current; /* key equal to current */
			key->prev = NULL;
		}

		else 
		{
			sorted = key; /* pointer to the key - starting 2nd node */
			/*print_list(*list); */
			/* sorted->next->n less the current->n */
			while (sorted->next != NULL && sorted->next->n < current->n)	
			{
				sorted = sorted->next;
			}
			current->next = sorted->next;

			if (sorted->next != NULL)
				sorted->next->prev = current;

			sorted->next = current;
			current->prev = sorted;
			/*print_list(current);*/
		}
		print_list(*list);
		current = nextNode;
	}

	
}
