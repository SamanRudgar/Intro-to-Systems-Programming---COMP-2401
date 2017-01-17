#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "math.h"
#include "student.h"


//MAKE A STUDENT STUFF

void getGPA(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Please enter the Student GPA:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);
		printf("Entered Value: %s\n", inputStr);
		if (charRead == 0){
			printf("Error in reading gpa. \n");
		} else{
			if(isValidGPA(inputStr)==0){
				int ab;
				sscanf(inputStr,"%d",&ab);
				p->info.stu.gpa = ab;
				printf("GPA Saved. \n\n");
				collected = 1;
			}else{
				printf("The GPA you entered is incorrect. Please fix.\n");
				printf("The acceptable integer values of GPA are between 0 - 10.\n");
			}
		}
	}
}

int isValidGPA(char *input){
	if(isInt(input) == 0){
		//printf("%d\n", isInt(input,100) );
		int a;
		sscanf(input,"%d",&a);
		if(a >= 0 && a <= 10){
			return 0;
		}else{
			return -1;
		}
	}else{
		return -1;
	}
}

void getCourses(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Please enter the Student number of Courses:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if (charRead == 0){
			printf("Error in reading courses. \n");
		} else{
			if(isValidCourses(inputStr)==0){
				int ab;
				sscanf(inputStr,"%d",&ab);
				p->info.stu.courses = ab;
				printf("Courses Saved. \n\n");
				collected = 1;
			}else{
				printf("The course number you entered is incorrect. Please fix.\n");
				printf("The acceptable integer values of courses is between 0 - 40.\n");
			}
		}
	}
}

int isValidCourses(char *input){
	if(isInt(input) == 0){
		int a;
		sscanf(input,"%d",&a);
		if(a >= 0 && a <= 40){
			return 0;
		}else{
			return -1;
		}
	}else{
		return -1;
	}
}

void getTuition(struct person *p){
	int collected;
	collected = 0;

	while(collected != 1){
		printf("Please enter the Student Tuition fees:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if (charRead == 0){
			printf("Error in reading tuition. \n");
		} else{
			if(isValidTuition(inputStr)==0){
				float a;
				sscanf(inputStr,"%.2f",a);
				a = roundf(a * 100) / 100;
				p->info.stu.tuition = a;
				printf("Tuition Saved. \n\n");
				collected = 1;
			}else{
				printf("The tuition fees you entered is incorrect. Please fix.\n");
				printf("Tuition must contain only numbers and must be positive.\n");
				printf("It can have a decimal point in it.\n");
			}
		}
	}
}

int isValidTuition(char *s){
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


















// PRINT A STUDENT STUFF

void printStudent(struct person p){
	//printf("Print Student entered.\n");
	char *fir = p.fn;
	char *sec = p.ln;
	char *thi = p.telephone;
	
	int forth = p.info.stu.gpa;
	int fifth = p.info.stu.courses;
	float sixth = p.info.stu.tuition;


	printf("%s %s 		Tel: %s,	GPA: %d,		Courses: %d,		Tuition: %.2f \n", fir, sec, thi,forth,fifth,sixth );

}

void printAllStudents(struct person person[], int size){
	//printf("FirstName SecondName 		Tel: xxxxxxxxxx,	GPA: xx,		Courses: xx,		Tuition: xxxxx.xx \n");
	int i;
	for(i = 0; i < size; i++){
		//printf("The loop entered fine.\n");
		if(person[i].discriminator == 1){
			//printf("person %d print requested \n", i);
			printStudent(person[i]);
		}
	}
	printf("--End of Print--\n");
}

void printAllStudentsWithGPA(struct person person[], int size){

	int collected;
	collected = 0;

	while(collected != 1){

		printf("Please enter the GPA you want to search with:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if(isValidGPA(inputStr) == 0){
			int i;
			int ab;
			sscanf(inputStr,"%d",&ab);
			for(i = 0; i < size; i++){
				//printf("Entered the checking loop\n");
				if(person[i].discriminator == 1 && person[i].info.stu.gpa == ab){
					printStudent(person[i]);
				}
			}
			printf("--End of Search--\n");
			collected = 1;
		}else{
			printf("That was an invalid GPA. Please try again.\n");
			printf("The acceptable integer values of GPA are between 0 - 10.\n");
		}
	}



}

void printAllStudentsWithFamilyName(struct person person[], int size){
	int collected;
	collected = 0;

	while(collected != 1){

		printf("Please enter the Student Family Name you want to search with:  ");

		char inputStr[100];

		int charRead = scanf("%s[^\n]\n", inputStr);

		if(isString(inputStr) == 0){
			int i;
			for(i = 0; i < size; i++){
				if(person[i].discriminator == 1 && strcmp(person[i].ln,inputStr) == 0){
					printStudent(person[i]);
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

void getStudent(struct person *peep){

	getGPA(peep);
	getTuition(peep);
	getCourses(peep);

}