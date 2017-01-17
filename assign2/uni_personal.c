#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "data.h"
#include "menu.h"
#include "student.h"
#include "employee.h"
#include "common.c"


int main(int argc, char* argv[]){

	struct person persons[20];

	/* SAMPLE DATA
	struct person aEmp;
	strcpy(aEmp.fn, "AtamEOne");
	strcpy(aEmp.ln, "SinghEOne");
	strcpy(aEmp.telephone, "9889889888");
	aEmp.discriminator = 0;
	aEmp.info.emp.level = 5;
	aEmp.info.emp.yos = 10;
	aEmp.info.emp.salary = 1000.10F;

	struct person aEmp2;
	strcpy(aEmp2.fn, "AtamETwo");
	strcpy(aEmp2.ln, "SinghETwo");
	strcpy(aEmp2.telephone, "9889889888");
	aEmp2.discriminator = 0;
	aEmp2.info.emp.level = 4;
	aEmp2.info.emp.yos = 7;
	aEmp2.info.emp.salary = 2300.10F;

	struct person aEmp3;
	strcpy(aEmp3.fn, "AtamEThree");
	strcpy(aEmp3.ln, "SinghEThree");
	strcpy(aEmp3.telephone, "9889889888");
	aEmp3.discriminator = 0;
	aEmp3.info.emp.level = 5;
	aEmp3.info.emp.yos = 10;
	aEmp3.info.emp.salary = 76560.10F;

	struct person aStu;
	strcpy(aStu.fn, "AtamSOne");
	strcpy(aStu.ln, "SinghSOne");
	strcpy(aStu.telephone, "8008008000");
	aStu.discriminator = 1;
	aStu.info.stu.gpa = 10;
	aStu.info.stu.courses = 20;
	aStu.info.stu.tuition = 2000.20F;

	struct person aStu2;
	strcpy(aStu2.fn, "AtamSTwo");
	strcpy(aStu2.ln, "SinghSTwo");
	strcpy(aStu2.telephone, "8008008000");
	aStu2.discriminator = 1;
	aStu2.info.stu.gpa = 5;
	aStu2.info.stu.courses = 36;
	aStu2.info.stu.tuition = 7890.20F;

	struct person aStu3;
	strcpy(aStu3.fn, "AtamSThree");
	strcpy(aStu3.ln, "SinghSThree");
	strcpy(aStu3.telephone, "8008008000");
	aStu3.discriminator = 1;
	aStu3.info.stu.gpa = 8;
	aStu3.info.stu.courses = 12;
	aStu3.info.stu.tuition = 9870.20F;

	persons[0] = aEmp;
	persons[1] = aStu;
	persons[2] = aEmp2;
	persons[3] = aStu2;
	persons[4] = aEmp3;
	persons[5] = aStu3;
	*/

	unsigned int running;

	running = 1;

	unsigned int choice;

	int records = 0;
	int check;

	while(running == 1){
		choice = menu();

		switch(choice){
			case 1:
				if(records <= 20){
					persons[records] = getNewRecord();
					records++;
				}else{
					printf("The space in database is full. Only 20 student records are allowed at one time.\n");
				}
				break;
			case 2:
				printAllStudents(persons,records);
				break;
			case 3:
				printAllEmployees(persons,records);
				break;
			case 4:
				printAllStudentsWithGPA(persons,records);
				break;
			case 5:
				printAllStudentsWithFamilyName(persons, records);
				break;
			case 6:
				printAllEmployeeWithSalary(persons,records);
				break;
			case 7:
				printAllEmployeeWithFamilyName(persons,records);
				break;
			case 8:
				summaryMaker(persons,records);
				break;
			case 9:

				break;
			case 0:
				check = quitChecker();
				if(check == 0){
					running  = 0;
				}
				break;
		}
	}




}