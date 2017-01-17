
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
	int status;
	int solution;
	if(argv[1] != NULL){
		pid_t pid = fork();
		if (pid == 0) {
		// child process instructions
			morph(argv[1]);
		} else {
		// parent process instructions
			while (wait(&status) != pid){
				//Don nothing, waiting for child to fininsh	
			}
			solution = WEXITSTATUS(status);
			if(solution == 1) printf("The number %s is a prime number.\n",argv[1]);
			else if(solution == 0) printf("The number %s is not a prime number.\n",argv[1]);
			else printf("There was an error. The number evaluated to 2.\n");
		}
	}else{
		printf("To use the program please enter a POSITIVE integer number when running it.\nA sample shell command may look like:\n	./task2 11\n");
	}
}
