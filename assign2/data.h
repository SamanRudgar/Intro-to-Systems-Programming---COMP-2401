//
//  data.h
//  
//
//  Created by atam
//
//

#ifndef _data_h
#define _data_h

struct student{
	unsigned int gpa:4;
	unsigned int courses:6;
	float tuition;
};

struct employee{
	unsigned int level:4;
	unsigned int yos:6;
	float salary;
};

union trait{
	struct student stu;
	struct employee emp;
};

struct person{
	char *fn[10];
	char *ln[20];
	char *telephone[10];
	unsigned int discriminator:1;
	union trait info;
};

#endif
