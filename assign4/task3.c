

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
	pid_t status[argc];
	int sols[argc];
	if(argv[1] != NULL){
		int sols[argc];
		int i;
		for(i = 1; i < argc; i++){
			pid_t cpid = fork();
			if(cpid == 0){
			// child process instructions	
				morph(argv[i]);
			}else{
				status[i] = cpid;
				//printf("%s : %d\n",argv[i],status[i]);
			}
		}
		int done = 1;
		while(done != argc){
			int resp = 100;
			pid_t responded = waitpid(-1, &resp, 0);
			int i;
			for(i = 0; i<argc; i++){
				if(responded == status[i] && WIFSIGNALED(responded) != 0){
					sols[i] = resp;
					//printf("saved ==> %s : %d\n",argv[i],sols[i]);
					done++;
				}
			}
		}
		for(i = 1; i<argc; i++){
			if(sols[i] == 256){
				printf("%s\n", argv[i]);
			}
		}

	}else{
		printf("To use the program please enter a POSITIVE integer number when running it.\nA sample shell command may look like:\n	./task2 11\n");
	}
}
