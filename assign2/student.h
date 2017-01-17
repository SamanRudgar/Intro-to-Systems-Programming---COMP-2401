//
//  student.h
//  
//
//  Created by atam
//
//

#ifndef _stu_h
#define _stu_h

#include "student.c"

void getGPA(struct person *p);
int isValidGPA(char *input);
void getCourses(struct person *p);
int isValidCourses(char *input);
void getTuition(struct person *p);
int isValidTuition(char *s);
void getStudent(struct person *peep);

void printStudent(struct person p);
void printAllStudents(struct person person[], int size);
void printAllStudentsWithGPA(struct person person[], int size);
void printAllStudentsWithFamilyName(struct person person[], int size);



#endif


