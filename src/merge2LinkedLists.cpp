/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {

	if (head1 == NULL && head2 == NULL)  return NULL;
	struct node *temp1,  *list;


	// if any one of the head node is NULL then returning the other node which is not NULL.
	if (head1 == NULL && head2 != NULL) return head2;
	if (head1 != NULL && head2 == NULL) return head1;



	// to retrieve the first node inorder to return  as  initial element after merging.
	if (head1->num < head2->num)
	{
		list = head1; head1 = head1->next;
	}
	else
	{
		list = head2;
		head2 = head2->next;
	}

	temp1 = list;// to hold the initial node .

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->num < head2->num)
		{
			list->next = head1;
			list = list->next;
			head1 = head1->next;

		}

		else
		{
			list->next = head2;
			list = list->next;
			head2 = head2->next;
		}

	}

	if (head1) // if all head2 nodes are inserted in the list , then head1 nodes are attached if any.
	{
		list->next = head1;

	}
	else       // if all head1 nodes are inserted in the list , then head2 nodes are attached if any.
	{
		list->next = head2;
	}



	return temp1; //returning the initial node.




}
