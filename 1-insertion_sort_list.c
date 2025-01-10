#include "sort.h"

int sort(listint_t *list);

/**
 * sort - perform node sort
 * @list: pointer to head of node
 * Return: 1 if  sorted else 0
 */

int sort(listint_t *list)
{
	listint_t *key = list; /* search key node */
	/*listint_t *copy = list; */
	listint_t *previous, *tempPrev = NULL, *tempNext = NULL;
	int sorted = 0;

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


	}
	/*print_list(list); */
	return (sorted);

}

/**
 * insertion_sort_list - function for insertion sort
 * @list : pointer to head of the node
 * Return: void)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list, *temp;
	listint_t *current, *key, *nextKey; /**tempNext = NULL, *tempPrev = NULL*/

	/*int sorted = 0;*/

	if ((head == NULL) || (!head->next))
	/*if (*list) || (*list->next)*/
		return;

	current = head;  /*current currently point to head */
	/*current = *list; */
	key = current->next; /* 2nd node and also the key*/

	/*while (current != NULL)*/
	while (key)
	{
		/* key = current->next; key node start from second node */
		nextKey = key->next; /* kept key->next for while loop */

		/* while (key != NULL)*/
		while ((current) && (current->n > key->n))
		{
			/*sorted = sort(key);*/
			/*tempNext = key->next;  kept address of key->next */
			/*tempPrev = current->prev;   kept address of current->prev */

			if (current->prev) /* not first node */
			{
				/*tempPrev->next = key;  swap key position */
				current->prev->next = key;
			}
			else /* current is first node */
			{
				/*head = key; */
				*list = key;
			}
			/*if (tempNext)  key is not the last node */
			/*	tempNext->prev = current;  swap current positon */
			if (key->next)
				key->next->prev = current;

			/* swapped */
			temp = key->next; /* store key->next */
			key->next = current;
			key->prev = current->prev;

			current->next = temp;
			current->prev = key;

			print_list(*list);
			/* if (sorted) */
			/*	print_list(*list); */
			/*key = key->next;*/
			/*current = current->next;*/
			current = key->prev;
		}
		/*current = current->next;*/
		/*key = key->next;*/
		key = nextKey;
		if (key)
			current = key->prev;
	}
}
