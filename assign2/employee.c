#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "math.h"
#include "employee.h"



//MAKE A EMPLOYEE STUFF


void getLevel(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Please enter the employee level:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if (charRead == 0){
			printf("Error in reading level. \n");
		} else{
			if(isValidLevel(inputStr)==0){
				int a;
				sscanf(inputStr,"%d",&a);
				p->info.emp.level = a;
				printf("Level Saved. \n\n");
				//free(inputStr);
				collected = 1;
			}else{
				printf("The level you entered is incorrect. Please fix.\n");
				printf("The acceptable integer values of level are between 1 - 15.\n");
			}
		}
	}
}

int isValidLevel(char *input){
	if(isInt(input) == 0){
		int a;
		sscanf(input,"%d",&a);
		if(a >= 1 && a <= 15){
			return 0;
		}else{
			return -1;
		}
	}else{
		return -1;
	}
}

void getYOS(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Please enter the employee's years of service:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if (charRead == 0){
			printf("Error in reading Years of Service. \n");
		} else{
			if(isValidYOS(inputStr)==0){
				int a;
				sscanf(inputStr,"%d",&a);
				p->info.emp.yos = a;
				printf("Years of Service Saved. \n\n");
				//free(inputStr);
				collected = 1;
			}else{
				printf("The Years of Service you entered is incorrect. Please fix.\n");
				printf("The acceptable integer values of Years of service is between 0 - 63.\n");
			}
		}
	}
}

int isValidYOS(char *input){
	if(isInt(input) == 0){
		int a;
		sscanf(input,"%d",&a);
		if(a >= 0 && a <= 63){
			return 0;
		}else{
			return -1;
		}
	}else{
		return -1;
	}
}

void getSalary(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Please enter the employee salary:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if (charRead == 0){
			printf("Error in reading employee salary. \n");
		} else{
			if(isValidSalary(inputStr)==0){
				float a;
				sscanf(inputStr,"%.2f",&a);
				a = roundf(a * 100) / 100;
				p->info.emp.salary = a;
				printf("Salary Saved. \n\n");
				//free(inputStr);
				collected = 1;
			}else{
				printf("The salary you entered is incorrect. Please fix.\n");
				printf("Salary must contain only numbers and must be positive.\n");
				printf("It can have a decimal point in it.\n");
			}
		}
	}
}

int isValidSalary(char *s){

	int numOfDecimals = 0;
	int i;

	for (i = 0; i < strlen(s); i++){
		char c;
		c = s[i];
		//printf("%c\n", c);
		if (c == '.'){
			numOfDecimals++;
			if(numOfDecimals > 1){
				return -1;
			}
		}else{
			if((c>='a'&& c<='z') || (c>='A' && c<='Z')){
				return -1;
			}
		}
	}

	return 0;
}







//PRINT AN EMPLOYEE STUFF

void printEmployee(struct person p){
	char *fir = p.fn;
	char *sec = p.ln;
	char *thi = p.telephone;
	
	int forth = p.info.emp.yos;
	int fifth = p.info.emp.level;
	float sixth = p.info.emp.salary;
	sixth = roundf(sixth * 100) / 100;


	printf("%s %s 		Tel: %s,	Age: %d,		Level: %d,		Salary: %.2f \n", fir, sec, thi,forth,fifth,sixth );

}

void printAllEmployees(struct person person[], int size){

	//printf("FirstName SecondName 		Tel: xxxxxxxxxx,	Age: xx,		Level: xx,		Salary: xxxxx.xx \n");
	int i;
	for(i = 0; i < size; i++){
		if(person[i].discriminator == 0){
			printEmployee(person[i]);
		}
	}
	printf("--End of Print--\n");
}


void printAllEmployeeWithSalary(struct person person[], int size){

	int collected;
	collected = 0;

	while(collected != 1){

		printf("Please enter the Salary you want to search with:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if(isValidSalary(inputStr) == 0){
			int i;
			float ab;
			sscanf(inputStr,"%f",&ab);
			for(i = 0; i < size; i++){
				//printf("Entered the checking loop\n");
				if(person[i].discriminator == 0 && person[i].info.emp.salary == ab){
					printEmployee(person[i]);
				}
			}
			printf("--End of Search--\n");
			collected = 1;
		}else{
			printf("That was an invalid Salary Amount. Please try again.\n");
			printf("Salary must contain only numbers and must be positive.\n");
			printf("It can have a decimal point in it.\n");
		}
	}
}


void printAllEmployeeWithFamilyName(struct person person[], int size){
	int collected;
	collected = 0;

	while(collected != 1){

		printf("Please enter the Employee Family Name you want to search with:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if(isString(inputStr) == 0){
			int i;
			for(i = 0; i < size; i++){
				if(person[i].discriminator == 0 && strcmp(person[i].ln,inputStr) == 0){
					printEmployee(person[i]);
				}
			}
			printf("--End of Search--\n");
			collected = 1;
		}else{
			printf("The family name entered is incorrect. Please try again. \n");
			printf("The field only takes alphabets as inputs. No numericals are allowed.\n");
			printf("Acceptable formats include:\n");
			printf("Doe\n");
			printf("Brown\n");
			printf("Chi\n");
		}

	}

	
}

void getEmployee(struct person *peep){

	getLevel(peep);
	getYOS(peep);
	getSalary(peep);

}