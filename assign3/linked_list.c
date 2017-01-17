
/* 
File name is linked_list.c

*/

/********************************************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/********************************************************************************************/
// Define 



/*****************************************************************************************************/
/*
Purpose: create a new node and insert it into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
a pointer to the node that was allocated.  If the operation was not successful then the function returns NULL

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{
	  PersonalInfo *newStruct = (PersonalInfo *)malloc(sizeof(PersonalInfo));
	  newStruct->id = id;
	  strcpy(newStruct->firstName,firstName);
	  strcpy(newStruct->familyName,familyName);
	  newStruct->next = *head;
	  //printf(*head);
	  //printNode(newStruct);
	  *head = newStruct; //NOT SURE ABOUT THIS CHECK!!!!!!!!!!

	  return &newStruct;
}


/*****************************************************************************************************/
/*
Purpose: create a new node and insert it into the list after the given record
Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
a pointer to the node that was allocated.  If the operation was not successful then the function returns NULL

*/


PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName)
{
	// add code 
	if(node == NULL){
		return NULL;
	}else{
		//create the new personalInfo
		PersonalInfo *newStruct = (PersonalInfo *)malloc(sizeof(PersonalInfo));
		newStruct->id = id;
		//newStruct.firstName = firstName;
		//newStruct.familyName = familyName;
		strcpy(newStruct->firstName,firstName);
		strcpy(newStruct->familyName,familyName);
		newStruct->next = node->next;
		printf("Adding: ");
		printNode(newStruct);

		node->next = newStruct; //NOT SURE ABOUT THIS CHECK!!!!!!!!!!

		return newStruct;
	}

	return NULL;

}

/*****************************************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
a pointer to the node that was allocated.  If the operation was not successful then the function returns NULL

*/


PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{
	// check if head has atleast one element
	if (head == NULL){
		return insertToList(head,id,firstName,familyName);
	}else{
		if((*head)->firstName == NULL) return NULL;

		PersonalInfo *p = NULL;
		int foundLast = 0;	// determines when to stop (last is found)
		p = *head;
		while (foundLast == 0) {
			if(p->next == NULL){
				//found last so after after the current p
				foundLast = 1;
				return insertAfter(p,id,firstName,familyName);
			}else{
				p = p->next;
			}
		}
	}

	return NULL;
}


/*****************************************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was allocated.  If the operation was not successful then the function returns NULL

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName)
{	

	// check if head has atleast one element
	if (head == NULL){
		return NULL;
	}else{
		PersonalInfo *p = NULL;
		int foundNode = 0;	// determines when to stop (nothing found)
		p = head;
		if(p->id == NULL) return NULL;
		//printf("Upto while loop good!\n");
		while (foundNode == 0) {
			///printf("checking %s, next %d\n",p->firstName, p->next);
			if(strcmp(p->firstName,firstName) == 0){
				//found similar firstname
				foundNode = 1;
				return p;
			}else if(p->next == NULL){
				//got to end of list but firstName not found
				foundNode = 10;
			}else{
				//move to next node
				p = p->next;
			}
			//printf("val of foundNode %d\n",foundNode);
		}
		//printf("out of loop!\n");
		return NULL;
	}

}

/*****************************************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  If the operation was not successful then the function returns NULL

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id)
{
	// check if head has atleast one element
	if (head == NULL){
		return NULL;
	}else{
		PersonalInfo *p = NULL;
		int foundNode = 0;	// determines when to stop (nothing found)
		p = head;
		if(p->id == NULL) return NULL;
		//printf("Upto while loop good!\n");
		while (foundNode == 0) {
			///printf("checking %s, next %d\n",p->firstName, p->next);
			if(p->id == id){
				//found similar firstname
				foundNode = 1;
				return p;
			}else if(p->next == NULL){
				//got to end of list but firstName not found
				foundNode = 10;
			}else{
				//move to next node
				p = p->next;
			}
			//printf("val of foundNode %d\n",foundNode);
		}
		//printf("out of loop!\n");
		return NULL;
	}


}

/*****************************************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if no node was deleted
1 if a node was deleted

*/


int deleteNodeById(PersonalInfo **head, int id, char *firstName, char *familyName)
{
	// check if head has atleast one element
	if (head == NULL){
		return 0;
	}else{
		if((*head)->firstName == NULL) return NULL;
		PersonalInfo *p = NULL;
		PersonalInfo *last = NULL;
		int foundLast = 0;	// determines when to stop (nothing found)
		p = *head;

		while (foundLast == 0) {
			if(p->id == id){
				//found node with same details
				foundLast = 1;
				//the node is not the front of the list
				if(last != NULL){
					//so skip the p node
					last->next = p->next;
					free(p);
					//free stack memory?? !!!!!!!!!!!!!!!!!!!!!!
					
				}else{
					//the node is the front
					if(p->next == NULL){
						//if the only thing in the list
						*head = NULL;
						free(p);
					}else{
						//not the only node
						*head = p->next;
						free(p);
					}
				}

				return 1;
			}else if(p->next == NULL){
				//got to end of list but firstName not found
				foundLast = 1;
			}else{
				//move to next node
				last = p;
				p = p->next;
			}
		}
		
		return 0;
	}


}




/*****************************************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/


void printNode(PersonalInfo *node)
{
	printf("%-20s %-20s %7d\n",node->firstName, node->familyName, node->id);

}


/*****************************************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head)
{
	//printNode(head);
	
	if(head == NULL){
		//printf("Empty List not printed.\n");
		return;
	}else{
		PersonalInfo *p = NULL;
		int foundNode = 0;	// determines when to stop (nothing found)	
		p = head;
		while (foundNode == 0) {
			
			printNode(p);
			if(p->next == NULL){
				//got to end of list but firstName not found
				foundNode = 1;
			}else{
				//move to next node
				p = p->next;
			}
		}
	}
	
	//printf("List Printing Done.\n");
	
}

/*****************************************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head)
{
	int num = 0;
	
	// add code 
	if(head == NULL || head->firstName == NULL){
		return 0;
	}else{
		PersonalInfo *p = NULL;
		int foundNode = 0;	// determines when to stop (nothing found)	
		
		p = head;
		while (foundNode == 0) {
			num++;
			if(p->next == NULL){
				//got to end of list but firstName not found
				foundNode = 1;
			}else{
				//move to next node
				p = p->next;
			}
		}

		return num;
	}
}

/*****************************************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/


int countElements(PersonalInfo *head, char *firstName)
{
	int num = 0;
	
	// add code 
	if(head == NULL || head->firstName == NULL){
		return 0;
	}else{
		PersonalInfo *p = NULL;
		int foundNode = 0;	// determines when to stop (nothing found)	
		
		p = head;
		while (foundNode == 0) {
			if(strcmp(p->firstName,firstName) == 0) num++;
			if(p->next == NULL){
				//got to end of list but firstName not found
				foundNode = 1;
			}else{
				//move to next node
				p = p->next;
			}
		}

		return num;
	}

}

/*****************************************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head)
{
	// add code 

	// check if head has atleast one element
	if (head == NULL){
		return;
	}else{
		if((*head)->firstName == NULL){
			*head = NULL;
			return;
		}

		PersonalInfo *p = NULL;
		PersonalInfo *next = NULL;
		int foundLast = 0;	// determines when to stop (last is found)
		p = *head;
		while (foundLast == 0) {
			if(p->next == NULL){
				//found last so after after the current p
				foundLast = 1;
				free(p);
			}else{
				next = p->next;
				free(p);
				p = next;
			}
		}
	}

	*head = NULL;
}

/*****************************************************************************************************/
/*
Purpose: merges two lists into a single list in a sorted order

input
headList1 - the head of the first list.  All nodes in the list are arranged in increasing order of firstName
headList2 - the head of the second list.  All nodes in the list are arranged in increasing order of firstName

output
outList - the output list which contains all the elements in headList1 and headList2 in increasing orer of firstName 
headList1 - should be set to NULL
headList2 - should be set to NULL
*/






void mergeLists(PersonalInfo **headList1, PersonalInfo **headList2, PersonalInfo **outHead)
{
	// add code 

	int firstNull = 0;
	int secondNull = 0;

	PersonalInfo *head = NULL;
	PersonalInfo *tail = NULL;
	PersonalInfo *first = *headList1;
	PersonalInfo *second = *headList2;

	if((first) == NULL) firstNull = 1;
	if((second) == NULL) secondNull = 1;

	int endLoop = 0;

	while((firstNull == 0 || secondNull == 0) && endLoop == 0){
		if(tail == NULL){
			if(firstNull == 0 && secondNull == 0){
				if(strcmp(first->firstName,second->firstName) <= 0){
					head = first; //add smaller element to list
					tail = first;	//move the tail over by one
					first = first->next; //move the head of the lower element list
				}else{
					head = second;
					tail = second;
					second = second->next;
				}
			}else if(firstNull == 0 && secondNull == 1){
				head = first;
				tail = first;
				endLoop = 1;
			}else if(firstNull == 1 && secondNull == 0){
				head = second;
				tail = second;
				endLoop = 1;
			}

			if((first) == NULL) firstNull = 1;
			if((second) == NULL) secondNull = 1;

		}else{
			if(firstNull == 0 && secondNull == 0){
				if(strcmp(first->firstName,second->firstName) <= 0){
					tail->next = first; //add smaller element to list
					tail = tail->next;	//move the tail over by one
					first = first->next; //move the head of the lower element list
				}else{
					tail->next = second;
					tail = tail->next;
					second = second->next;
				}
			}else if(firstNull == 0 && secondNull == 1){
				tail->next = first;
				endLoop = 1;
			}else if(firstNull == 1 && secondNull == 0){
				tail->next = second;
				endLoop = 1;
			}

			if((first) == NULL) firstNull = 1;
			if((second) == NULL) secondNull = 1;
		}

	}

	*outHead = head;


}

/*****************************************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list



*/




void removeDuplicates(PersonalInfo *head)
{
	// add code 
	char currentName[NAME_LENGTH];
	char lastName[NAME_LENGTH];

	PersonalInfo *currentNode = head;
	PersoanlInfo *newHead = NULL;
	PersoanlInfo *helper = NULL;

	while(currentNode != NULL){
		if(currentNode->next != NULL){
			if(currentNode->firstName == currentNode->next->firstName){
			if(newHead == NULL){
				newHead = currentNode->next;
			}

			helper = currentNode->next;
			free(currentNode);
			current = helper;
			}else{
				if(newHead == NULL) newHead = head;
				currentNode = currentNode->next;
			}
		}else{

		}
		
	}

	head = newHead;


	PersonalInfo *previous = NULL, *current = NULL, *next = NULL, *helper = NULL, *newHead = NULL;

	if(current != NULL){
		int size = listSize(head);
		if(size > 1){
			current = head;
			next = current->next;
			while(current != NULL){
				if(current->firstName == next->firstName){
					if(last == NULL){
						newHead = next;
						current = next;
						next = current->next;
					}else{
						current = next;
						next = current->next;
					}
				}else{
					last = current;
					current = next;
					next = current->next;
				}
			}
			
		}
	}




}


/*****************************************************************************************************/
/*

Purpose: sorts the list by first name using merge sort. 

input
head - the head of the  list

*/




void mergeSort(PersonalInfo **head)
{
	// add code 



}


