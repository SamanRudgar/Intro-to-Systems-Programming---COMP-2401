#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "menu.h"

int menu(){

	char choice[100];
	int choiceInt;
	int done;

	done = 0;

	while(done == 0){
		//print menu
		printf("\n");
		printf("1. Add a new Record\n");
		printf("2. print Student List\n");
		printf("3. print employee List\n");
		printf("4. Find a students using GPA\n");
		printf("5. Find student using Family Name\n");
		printf("6. Find employees using salary\n");
		printf("7. Find employees using Family Name\n");
		printf("8. Summary of Data\n");
		printf("9. Fix max GPA using pointers\n");
		printf("0. Quit\n");
		printf("\n");

		//wait for response
		printf("Choice: ");
		scanf("%s[^\n]\n", choice);


		//check response
		if(isInt(choice) == 0){
			//printf("The integer test passed. %s\n", choice);
			sscanf(choice,"%d",&choiceInt);
			if(choiceInt >= 0 && choiceInt <= 9){
				done = 1;
			}else{
				printf("The choice enter is out of range. Please choose again.\n");
			}
			
		}else{
			//respone out of bound so choose again
			printf("The option you selected is not valid. Please choice an option again.\n");
		}
	}

	return choiceInt;

}