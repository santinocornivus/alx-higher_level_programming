#include "lists.h"

/**
 * check_cycle - checks if a singly linked head has
 * a cycle in it
 * @head: pointer to the head
 * Return: 0 if there is no cycle,
 * 1 if there is a cycle
 */

int check_cycle(listint_t *head)
{
        listint_t *fast, *slow;

        fast = slow = head; /* Both points to the same node as head */

        while (head && fast && fast->next)
	{
                slow = slow->next; /* Walk one node along the linked list */
                fast = fast->next->next; /* walk two nodes along the linked list */

                if (slow == fast) /* When slow and fast are the same,  */
                {
                        slow = head; /* slow starts over */
                        head =  fast;
                        while (1)
                        {
			        fast = head;
                                while (fast->next != slow && fast->next != head)
				{
                                        fast = fast->next;
				}
				
                                if (fast->next == slow)
                                {
                                        break;
                                }

				slow = slow->next;
                        }
			
                        return (1);
                }
        }

	return (0);
}
