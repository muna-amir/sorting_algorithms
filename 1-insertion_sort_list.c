#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list to be sorted.
 *
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *prev, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    curr = (*list)->next;

    while (curr != NULL)
    {
        prev = curr->prev;
        tmp = curr->next;

        while (prev != NULL && prev->n > curr->n)
        {
            prev->next = curr->next;

            if (curr->next != NULL)
                curr->next->prev = prev;

            curr->next = prev;
            curr->prev = prev->prev;

            if (prev->prev != NULL)
                prev->prev->next = curr;

            prev->prev = curr;
            prev = curr->prev;
        }

        curr = tmp;
    }

    while ((*list)->prev != NULL)
        *list = (*list)->prev;
}
