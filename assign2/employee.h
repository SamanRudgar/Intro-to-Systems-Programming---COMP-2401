//
//  employees.h
//  
//
//  Created by atam
//
//

#ifndef _emp_h
#define _emp_h

#include "employee.c"

void getLevel(struct person *p);
int isValidLevel(char *input);
void getYOS(struct person *p);
int isValidYOS(char *input);
void getSalary(struct person *p);
int isValidSalary(char *s);
void getEmployee(struct person *peep);

void printEmployee(struct person p);
void printAllEmployees(struct person person[], int size);
void printAllEmployeeWithSalary(struct person person[], int size);
void printAllEmployeeWithFamilyName(struct person person[], int size);




#endif