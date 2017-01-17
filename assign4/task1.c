
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

#include "task1.h"

void morph(char *number){
	char * fileName = "./isPrime";
	char * paramList[3] = {"isPrime",number};
	int result = execvp(fileName,paramList);
	printf("%d\n",result);
}


int main(int argc, char* argv[]) {
	if(argv[1] != NULL){
		morph(argv[1]);
	}
  return 2;
}
