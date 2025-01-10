#include "sort.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void insertion_sort_list(listint_t **list)
/*struct ListNode* insertionSortList(struct ListNode* head)*/
{
	listint_t *head = *list;
	listint_t *prev = NULL, *cur = NULL; 
	listint_t *temp = NULL, *p = NULL;

    if(head == NULL || head->next == NULL) 
	    return;
    
    prev = head;
    cur = head->next;
    while(cur) {
        if(prev->n > cur->n) {
            if(head->n > cur->n) {
                prev->next = cur->next;
                cur->next = head;
                head = cur;
                // prev = prev->next;
                cur = prev->next;
            } else {
                temp = head;
                p = temp;
                while(temp && temp->n < cur->n) {
                    p = temp;
                    temp = temp->next;
                }
                prev->next = cur->next;
                cur->next = p->next;
                p->next = cur;
                //prev = prev->next;
                cur = prev->next;
            }
        } else{
            prev = cur;
            cur = cur->next;
        }
    }
    return;
}

