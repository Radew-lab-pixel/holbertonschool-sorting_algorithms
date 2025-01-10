#include "sort.h"

int sort(listint_t *list)
{
    listint_t *key = list;  /* search key node */
    listint_t *previous, *tempPrev = NULL, *tempNext = NULL;
    int sorted = 0;

    if (!key || !key->prev)  // Avoid working with NULL or empty nodes
        return 0;

    previous = key->prev;

    // Check if the nodes need to be swapped
    if (previous->n > key->n) {
        tempPrev = previous->prev;
        tempNext = key->next;

        // Re-link the nodes correctly
        if (tempPrev) {
            tempPrev->next = key;
            key->prev = tempPrev;
        } else {
            key->prev = NULL;  // key is now the first node
        }

        key->next = previous;
        previous->prev = key;

        if (tempNext) {
            previous->next = tempNext;
            tempNext->prev = previous;
        } else {
            previous->next = NULL;  // key was the last node
        }

        sorted = 1;
    }

    return sorted;
}

void insertion_sort_list(listint_t **list)
{
    listint_t *head = *list;
    listint_t *current, *key;
    int sorted;

    if (head == NULL)
        return;

    current = head;

    // Keep sorting until no changes are made
    do {
        sorted = 0;
        key = current->next;

        while (key != NULL) {
            if (sort(key)) {
                sorted = 1;  // A change occurred
                print_list(head);
            }
            key = key->next;
        }
        
        current = current->next;
    } while (sorted);  // Continue sorting as long as changes are made
}
