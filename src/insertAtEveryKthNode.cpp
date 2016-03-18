/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {

	if (head == NULL || K < 1) return NULL;

	int i = 1;
	struct node *temp = head;



	while (temp != NULL)
	{
		if (i == K)
		{
			struct node *newnode = (struct node *)calloc(1, sizeof(struct node));// creating new node for every entry.
			newnode->num = K;
			newnode->next = NULL;
			newnode->next = temp->next;
			temp->next = newnode;
			temp = temp->next->next;
			i = 1;  // after every insertion , making 'i' value to default for next Kth node counting.
		}
		else
		{

			temp = temp->next; i++;
		}


	}
	
	return head;
}
