#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#include "student.h"
#include "employee.h"



void getTelephone(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Please enter the telephone number for the record:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if (charRead == 0){
			printf("Error in reading telephone. \n");
		} else{
			if(isTelephone(inputStr)==0){
				//printf("Inside loop\n");
				sscanf(inputStr,"%s",p->telephone);
				printf("Telephone Saved. \n\n");
				//free(inputStr);
				collected = 1;
			}else{
				printf("The telephone entered does not follow the correct fromat.\n");
				printf("The field only takes numbers 0-9 and the first digit is not allowed to be 0 or 1.\n");
				printf("Acceptable formats include:\n");
				printf("##########\n");
			}
		}
	}
}


void getFirstName(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Please enter First Name:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);
		if (charRead == 0){
			printf("Error in reading First Name. \n");
		} else{
			if(isString(inputStr)==0){
				strncpy(p->fn, inputStr, 10);
				printf("First Name Saved. \n\n");
				//free(inputStr);
				//flushall();
				collected = 1;
			}else{
				printf("The First Name entered does not follow the correct fromat.\n");
				printf("The field only takes alphabets as inputs. No numericals are allowed.\n");
				printf("Acceptable formats include:\n");
				printf("John\n");
				printf("Alex\n");
				printf("SueMun\n");
			}
		}
	}
}

void getLastName(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Please enter Family Name:  ");

		char inputStr[100];

		char charRead = scanf("%s[^\n]\n",inputStr);
		if(charRead == 0){
			printf("Error in Family Name. \n");
		}else{
			if(isString(inputStr)==0){
				strncpy(p->ln, inputStr, 20);
				printf("Family Name Saved. \n\n");
				collected = 1;
			}else{
				printf("The Family Name entered does not follow the correct fromat.\n");
				printf("The field only takes alphabets as inputs. No numericals are allowed.\n");
				printf("Acceptable formats include:\n");
				printf("Doe\n");
				printf("Brown\n");
				printf("Chi\n");
			}
		}
	}
}

void getDiscriminator(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Is this record a student record? Please enter \"y\" or \"n\":  ");

		char inputStr[100];\

		int charRead = scanf("%s[^\n]\n", inputStr);
		//getchar();
		if (charRead == 0){
			printf("Error in Family Name. \n");
		} else{
			if(isString(inputStr)==0){
				if (strncmp(inputStr,"y",1)==0){
					p->discriminator = 1;
				}else if(strncmp(inputStr,"n",1)==0){
					p->discriminator = 0;
				}
				printf("Record Status Saved. \n\n");
				//free(inputStr);
				collected = 1;
			}else{
				printf("Please enter only y or n. No other inputs need to be entered.\n");
			}
		}
	}
}

int isFloat(char *s){

}

int isString(char *s){
	int i = 0;

	for(i = 0; i < strlen(s); i++){
		char c = s[i];
		//printf("%c\n",c );
		if((c>='a'&& c<='z') || (c>='A' && c<='Z') || (c == '\n')){

		}else{
			return -1;
		}
	}

	return 0;
}

int isInt(char *s){
	int i;
	
	for(i = 0; i < strlen(s); i++){
		char c = s[i];
		//printf("%c\n",c );
		if(c>='0'&& c<='9'){

		}else{
			return -1;
		}
	}

	return 0;
}

int isTelephone(char *s){
	//printf("Is string: %d\n", isInt(s));
	//	printf("Size: %d\n", strlen(s));

	char first;
	first = s[0];
	//printf("First Char is: %c\n", first);
	if(first == '0' || first == '1'){
		//printf("Cause first number: %c\n", first);
		return -1;
	}else if(isInt(s)==0 && strlen(s)==10){
		return 0;
	}else{
		return -1;
	}
}


void summaryMaker(struct person p[], int size){
	int totalRecords = 0;

	int stuNum = 0;
	int totalGPA = 0;
	int totalCourses = 0;
	int totalTuition = 0;

	int empNum = 0;
	int minLevel = 15;
	int maxLevel = 0;
	int totalAge = 0;
	int totalSalary = 0;

	int i;
	for(i = 0; i < size; i++){
		totalRecords++;
		if(p[i].discriminator == 1){
			stuNum++;
			totalGPA += p[i].info.stu.gpa;
			totalCourses += p[i].info.stu.courses;
			totalTuition += p[i].info.stu.tuition;
		}else{
			empNum++;
			totalAge += p[i].info.emp.yos;
			totalSalary += p[i].info.emp.salary;
			if(p[i].info.emp.level > maxLevel){
				maxLevel = p[i].info.emp.level;
			}
			if(p[i].info.emp.level < minLevel){
				minLevel = p[i].info.emp.level;
			}
		}
	}

	float avergaeGPA = totalGPA/stuNum;
	float avgCourses = totalCourses/stuNum;
	float avgTuition = totalTuition/stuNum;

	printf("Total number of records: %d\n", totalRecords);
	printf("Student Stats:\n");
	printf("Number of Students: %d\n", stuNum);
	printf("Average GPA:  %.2f", avergaeGPA);
	printf(", Average Number of courses:  %.2f", avgCourses);
	printf(", Average Tutition Fees: %.2f\n", avgTuition);


	float avgAge = totalAge/empNum;
	float avgSal = totalSalary/empNum;

	printf("Employees' Stats:\n");
	printf("Number of Employees: %d\n", empNum);
	printf("Max Level: %d", maxLevel);
	printf("	Min Level: %d\n", minLevel);
	printf("Average Age:  %.2f", avgAge);
	printf(", Average Salary:  %.2f\n\n", avgSal);
}


int quitChecker(){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Do you really want to quit? Please enter \"y\" or \"n\":  ");

		char inputStr[100];

		int charRead = scanf("%s", &inputStr);
		if (charRead == 0){
			printf("Error in Quit read. \n");
		} else{
			if(isString(inputStr)==0){
				if (strncmp(inputStr,"y",1)==0){
					return 0;
				}else if(strncmp(inputStr,"n",1)==0){
					return -1;
				}
				free(inputStr);
				collected = 1;
			}else{
				printf("Please enter only y or n. No other inputs need to be entered.\n");
			}
		}
	}
}

struct person getNewRecord(){
	struct person thisPerson;

	getFirstName(&thisPerson);
	getLastName(&thisPerson);
	getTelephone(&thisPerson);
	getDiscriminator(&thisPerson);

	if (thisPerson.discriminator == 1){
		getStudent(&thisPerson);
	}else{
		getEmployee(&thisPerson);
	}

	return thisPerson;

}