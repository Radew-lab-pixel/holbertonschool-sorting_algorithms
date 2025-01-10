#include "sort.h"

int sort(listint_t *list);
int sort_backward(listint_t *list, listint_t *endKey);

int sort_backward(listint_t *list, listint_t *endKey)
{
	listint_t *current = list; /* starting from the end */
	listint_t *previous, *tempPrev = NULL, *tempNext = NULL;
	int sorted = 0;

	while (endKey != NULL) /* pointer to the node where swap occur */
	{	
		previous = endKey->prev;
		if (previous->n > endKey->n)
		{
			/* previous not 1st node and key not last node */
			if ((previous->prev != NULL) && (endKey->next != NULL))
			{	
				tempPrev = previous->prev; /* address of previous->prev */
				tempNext = endKey->next; /*address of endkey->next */

				endKey->prev = tempPrev; /* swap endkey */
				endKey->next = previous;
				tempPrev->next = endKey;
			
				previous->prev = endKey; /*swap previous */
				previous->next = tempNext;
				tempNext->prev = previous;
				sorted = 1;
			}
			/* previous not 1st node, endkey is last node */
			else if ((previous->prev) && (endKey->next == NULL))
			{
				tempPrev = previous->prev;

				endKey->prev = tempPrev; /* swap end key */
				endKey->next = previous;
				tempPrev->next = endKey;

				previous->prev = endKey; /*swap previous */
				previous->next = NULL;

				sorted = 1;
			}
			/* previous is 1st node and endKey is not last node */
			else if ((previous->prev == NULL) && (endKey->next))
			{
				tempNext = endKey->next;

				endKey->prev = NULL; /* swap endKey */
				endKey->next = previous;

				previous->prev = endKey; /* swap endKey */
				previous->next = tempNext;
				tempNext->prev = previous;
				sorted = 1;
			}
			else
				sorted = 0;
		
		}
		if (sorted)
		{
			print_list(current);
			endKey = endKey->prev;
		}
		else 
			break;
	}
	return (sorted);
}

int sort(listint_t *list)
{
	listint_t *key = list; /* search key node */
	/*listint_t *copy = list; */
	listint_t *previous, *tempPrev = NULL, *tempNext = NULL;
	int sorted = 0;

	previous = key->prev;
	
	if (previous->n > key->n)
	{	
		/* previous not first node and key not last node */
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

			sorted = 1;
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

			sorted = 1;
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
			
			sorted = 1;

		}
		else 
		{
			sorted = 0;
		}
		/* print_list(copy); */
		/*sorted = 1; */
		if (sorted)
			sort_backward(list, key);
		
	}
	/*print_list(list); */
	return (sorted);
		
}


void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *current, *key;
	int sorted = 0;

	if (head == NULL)
		return;
	
	current = head;  /*current currently point to head */
	/* current = *list; */
	
	/*key = current->next;*/

	while (current != NULL)
	{
 		key = current->next; /*key node start from second node */
		
		while (key != NULL) 
		{
			sorted = sort(key);

			if (sorted)
				print_list(head);
			key = key->next;
		}
		current = current->next;
	}
}
