
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "linked_list.h"


void populatePerson(char *firstName, char *familyName, int *id);


int main(int argc, char* argv[])
{
	char firstName[NAME_LENGTH];
	char familyName[NAME_LENGTH];
	int id;
	struct personalInfo *empHead = NULL;
	struct personalInfo *p = NULL;
	int i;

	
	for (i = 0; i < 20; i++) {
	// add code for testing
		populatePerson(firstName, familyName, &id);
		insertToList(&empHead, id, firstName, familyName);
	}

	printf("The adding is done!\n\n");
	
	printList(empHead);
	
	p = searchById(empHead,125);
	printf("Id 125: ");
	printNode(p);
	for (i = 0; i < 4; i++) {
		populatePerson(firstName, familyName, &id);
		p = insertAfter(p, id, firstName, familyName);
	}

	printf("The adding is done!\n\n");
	
	printList(empHead);
	
	p = searchByName(empHead, "Don");
	printf("First Name Don: ");
	printNode(p);
	if (p != NULL) {
		for (i = 0; i < 4; i++) {
			populatePerson(firstName, familyName, &id);
			insertAfter(p, id, firstName, familyName);
		}
	}

	printf("The adding is done!\n\n");
	
	printList(empHead);

	//testing adding at end
	p = searchByName(empHead, "John");
	printf("First Name John: ");
	printNode(p);
	if (p != NULL) {
		for (i = 0; i < 5; i++) {
			populatePerson(firstName, familyName, &id);
			insertLast(p, id, firstName, familyName);
		}
	}

	printf("The adding is done!\n\n");
	
	printList(empHead);

	
	p = searchById(empHead, 125);
	id = 125;
	printf("Id 125: ");
	printNode(p);
	if (p != NULL) {
		p->firstName[0] = 'Z';
		printf("\n found name to delete \n");
		printNode(p);
		strncpy(firstName, p->firstName, NAME_LENGTH);
		deleteNodeById(&empHead, id, firstName, familyName);
	}
	
	printf("The deletion is done!\n\n");
	
	printList(empHead);
	

	printf("Num of elements in list: %d \n",listSize(empHead));
	printf("Num of John's in list: %d \n",countElements(empHead,"John"));


	deleteList(&empHead);
	printList(empHead);

	/*
	mergeSort(&empHead);

	printf("\n\n sorted list \n\n");
	printList(empHead);

//	getchar();

	printf("\n\n remove duplicates \n\n");
	removeDuplicates(empHead);
	printList(empHead);
	getchar();
	*/

	return 0;
}


	

/***************************************************************************/
/* purpose: the function populate the personal info

input/output
struct personalInfo *p - allocated memory to the struct pointer which the function assigns values.




*/

void populatePerson(char *firstName, char *familyName, int *id)
{
	static int initRand = 0;
	int j;
	char *first[5] = { "John", "Don", "Edna", "Bev", "Miya" };
	char *family[5] = { "Broker", "Smith", "Tower", "Little", "Bronson" };

	if (!initRand) {
		srand(1557);
		initRand ++;
	}
	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 5;
	// copy the first name to the structure pointed by p using strcpy
	strncpy(firstName, first[j], NAME_LENGTH);

	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 5;
	// copy the family name to the structure pointed by p using strcpy
	strncpy(familyName, family[j], NAME_LENGTH);

	// populate the student id using the random numnber in the range of 0-4096  
	*id = rand() % 150;

}






