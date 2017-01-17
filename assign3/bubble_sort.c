

/* 
File name is bubble_sort.c

*/

/********************************************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"





/*****************************************************************************************************/
/*

Purpose: sorts the list by first name using bubble sort. 

input
head - the head of the  list

*/




void bubbleSort(PersonalInfo **head)
{
	PersonalInfo *p1 = NULL, *p2 = NULL, *p = NULL;
	PersonalInfo temp;	// temporary node that assist in sorting.
	int size; 
	int listSorted = 0;	// determines when to stop (list is sorted)	

	// check if pointer to list head is valid
	if (head == NULL) return;

	// check if list contains more than one element.
	// determine the list size
	size = listSize(*head);
	if (size <= 1) return;

	temp.next = *head;	// temporary node so that we always have a previous.
	while (!listSorted) {
		p = &temp;
		listSorted = 1;
		while(p->next->next != NULL) {
			// get handles of the two nodes to be swapped.  
			p1 = p->next;
			p2 = p1->next;
			if (strncmp(p1->firstName, p2->firstName, NAME_LENGTH) > 0) {
				// p1 is larger and therefore we need to swap the nodes
				// note that one one can simplify the swapping by simply exhcnaging the content. 
				// However, this is an example of how simple the book keeping is.  
				// It is best to draw a small picture of the changes to ensure that no node is lost.
				p1->next = p2->next;
				p2->next = p1;
				p->next = p2;
				listSorted = 0;		// at least one more number bubbled up. 
			}
			p = p->next;
		}
	}
	
	*head = temp.next;
}


