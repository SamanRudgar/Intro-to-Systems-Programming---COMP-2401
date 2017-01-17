
/* 
File name is linked_list.h

*/


#ifndef LINKED_LIST_2401
#define LINKED_LIST_2401 1

#define NAME_LENGTH 32


typedef struct personalInfo {
	struct PersonalInfo *next;
	unsigned int id;		
	char firstName[NAME_LENGTH];
	char familyName[NAME_LENGTH];
} PersonalInfo;

#include "linked_list.c"

// Part I
PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, char *firstName, char *familyName);
PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName);
PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName);
PersonalInfo *searchByName(PersonalInfo *head, char *firstName);
PersonalInfo *searchById(PersonalInfo *head, unsigned int id);
int deleteNodeByName(PersonalInfo **head, char *firstName, char *lastName, int *id);
void printList(PersonalInfo *head);
void printNode(PersonalInfo *node);
int listSize(PersonalInfo *head);
int countElements(PersonalInfo *head, char *firstName);
/*
void deleteList(PersonalInfo **head);


// Part II

void mergeLists(PersonalInfo **headList1, PersonalInfo **headList2, PersonalInfo **outHead);
void removeDuplicates(PersonalInfo *head);
void mergeSort(PersonalInfo **head);
*/

#endif
