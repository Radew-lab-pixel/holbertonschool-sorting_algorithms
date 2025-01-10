#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *lead, *follow, *new, *temp;

    if (!(*list) || !((*list)->next))
        return;

    /* Dance begins with 1st from house left following */
    follow = *list;
    /* and next dancer to house right leading */
    lead = follow->next;
    
    while (lead) {
        new = lead->next;  /* Remember the next node for the next iteration */
        
        /* Compare lead with the sorted part of the list */
        while (follow && lead->n < follow->n) {
            /* Lead and follow swap positions */
            if (follow->prev)
                follow->prev->next = lead;
            else
                *list = lead;  // If lead moves to the head of the list

            if (lead->next)
                lead->next->prev = follow;
            
            temp = lead->next;
            lead->next = follow;
            lead->prev = follow->prev;
            follow->next = temp;
            follow->prev = lead;

            print_list(*list);  // Print after each swap (if necessary)
            
            // Move the follow pointer back to the left
            follow = lead->prev;
        }

        /* Lead sorted to left, new cycle starts @ right leading edge */
        lead = new;
        if (lead)
            follow = lead->prev;
    }
}
