#include "sort.h"

void sort(listint_t *list);

void sort(listint_t *list)
{
	listint_t *key = list; /* search key node */
	listint_t *previous, *tempPrev = NULL, *tempNext = NULL;

	previous = key->prev;
	
	if (previous->n > key->n)
	{	
		/* previous not first node and key last node */
		if ((previous->prev != NULL) && (key->next != NULL))
		{
			tempPrev = previous->prev; /* store address of previous->prev */
			tempNext = key->next; /* store address of key->next */

			key->prev = tempPrev; /* swap key */
			key->next = previous;
			tempPrev->next = key;

			previous->prev = key; /* swap previous */
			previous->next = tempNext;
			tempNext->prev = previous;
		}
		/* previous not first node and  key is last node */
		else if ((previous->prev) && (key->next == NULL))
		{
			tempPrev = previous->prev;

			key->prev = tempPrev; /*swap key */
			key->next = previous;
			tempPrev->next = key; 

			previous->prev = key; /* swap previous */
			previous->next = NULL;
		}
		/* previous is first node and key not last node */
		else if ((previous->prev == NULL) && (key->next)) 
		{
			tempNext = key->next;

			key->prev = NULL; /* swap key */
			key->next = previous;

			previous->prev = key; /*swap previous */
			previous->next = tempNext;
			tempNext->prev = previous;

		}

	}
	print_list(list);
		
}


void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;

	listint_t *current, *key;

	if (head == NULL)
		return;
	
	current = head; /* current currently point to head */
	
	while (current != NULL)
	{
		key = current->next; /* key node start from second node */

		while (key != NULL)
		{
			sort(key);
			key = key->next;
		}
		current = current->next;
	}

}
