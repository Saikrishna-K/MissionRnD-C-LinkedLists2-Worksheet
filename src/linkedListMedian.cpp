/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	if (head == NULL) return -1;

	int count = 1, median1, i;


	if (head->next == NULL) return head->num;


	struct node *current = head;
	while (current->next != NULL)
	{
		current = current->next;
		count++;

	}

	if (count % 2 == 0) // if the linked list is an even length one
	{
		median1 = count / 2;


		current = head;

		for (i = 1; i < median1; i++)
		{
			current = current->next;

		}

		return (current->num + current->next->num) / 2;


	}
	else            // if the linked list is an odd length one
	{
		median1 = (count / 2) + 1;
		current = head;

		for (i = 1; i < median1; i++)
		{
			current = current->next;

		}

		return current->num;
	}



}
