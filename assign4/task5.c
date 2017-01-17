

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "signal.h"

#include "task1.h"

static int completedCalls = 0;
static int totalCalls = 0;


void my_handler(int signum)
{
    printf("\nTotal Processes Invoked: %d\n	Total Processes Remaining: %d\n\n",totalCalls,(totalCalls-completedCalls));
}

//signal(SIGUSR1, my_handler);


void morph(char *number){
	char * fileName = "./isPrime";
	char * paramList[3] = {"isPrime",number};
	int result = execvp(fileName,paramList);
	printf("morphFn: %d\n",result);
}

char * setupArray(int argcReg , char * argvReg[]){

	//int j;
	//for(j=0;j< argcReg; j++) printf("%d\n",*argvReg[j]);
	//printf("Setup array called.\n");
	char * fileName = argvReg[1];
	FILE * source = fopen(fileName, "rb");
	int size = argcReg-2;
	fseek(source, 0, SEEK_END); // seek to end of file
	int info = ftell(source); // get current file pointer
	fseek(source, 0, SEEK_SET); // seek back to beginning of file
	//printf("FILE SIZE: %d\n", info);
	int fileNums = 0;
	int count =0;
	long * nums[argcReg-1];
	long arr[info];
	char buffer[sizeof(long)];

	    
		//ISSUES IN FILE READING. MAYBE THE SAMPLE IS WRONG? wait for file from professor.
	    if (source) {
		long n = fread(buffer, 1, sizeof(long), source);
		while (!feof(source)) {
	//printf("Started reading file.\n");
		    
	//printf("Read: %d\n",n);
		    arr[fileNums] = n;
		    fileNums++;
		    n = fread(buffer, 1, sizeof(long), source);
		}
		//printf("Exits from the buffer read loop\n");
	    } else {
		printf("fail\n");
	    }
	if(source != NULL) {fclose(source); source =NULL;}
	//printf("Finished Reading file.\n");
	
	int counter = 1;
	//printf("Counter goes to %d.\n",argcReg-1);
	/*
	while(counter != argcReg)
	{
		printf("Starts tranferring of data.\n");
		int choice = (int)atoi(argvReg[counter+1]);
		///choice = 1;
		printf("Choice found: %d\n",choice);
		if(choice >=0){
			printf("Adding to nums @ %d from arr @ %d.\n",counter,choice-1);
			nums[counter] = arr[choice-1];
		}else{
			printf("Adding to nums @ %d from arr @ %d.\n",counter,fileNums+choice-1);
			nums[counter] = arr[fileNums+choice-1];
		}
		printf("--Saved to new array. Counter @ %d\n",counter);
		counter++;
	}*/
	char * toReturn[argcReg-1];
	toReturn[0] = &"NA";

	while(counter != argcReg-1){
		//printf("Counter: %d\n",counter);
		//printf("Starts tranferring of data.\n");
		int choice = (int)atoi(argvReg[counter+1]);
		///choice = 1;
		//printf("Choice found: %d\n",choice);
		if(choice >0){
			//printf("Adding to nums @ %d from arr @ %d.\n",counter,choice-1);
			nums[counter] = arr[choice-1];
			char numString[1000];
			sprintf(numString, "%d", nums[counter]);
//printf("The string is %s\n",numString);
			toReturn[counter] = numString;
			//snprintf(*toReturn[counter],sizeof(*toReturn[counter]), "%ld", nums[counter]);
			//toReturn[counter] = ltoa(nums[counter]);
			///ltoa(nums[counter],toReturn[counter],10);
		}else{
			//printf("Adding to nums @ %d from arr @ %d.\n",counter,fileNums+choice);
			nums[counter] = arr[fileNums+choice];
			char numString[1000];
			sprintf(numString, "%d", nums[counter]);
			//printf("The string is %s\n",numString);
			toReturn[counter] = numString;
			///snprintf(*toReturn[counter],sizeof(*toReturn[counter]), "%ld", nums[counter]);
			//toReturn[counter] = ltoa(nums[counter]);
			//ltoa(nums[counter],toReturn[counter],10);
		}
		//printf("--Saved to new array. Counter @ %d\n",counter);
		if(counter == argcReg-1){
			break;
		}else{counter++;}
	}
	/*
	printf("Does not enter loop and kicks out\n");

	char * toReturn[argcReg-1];
printf("charArray Made.\n");
	toReturn[0] = "NA";
int i = 1;
int oldSize = sizeof(nums)/sizeof(nums[0]);
printf("size is: %d\n",oldSize);
printf("counter is: %d\n",counter);
	
	for(i = 1; i < oldSize; i++){
		printf("The num being replaced is %s and the num is %lu.\n",i,nums[i]);
		
		sprintf(toReturn[i], "%lu", nums[i]);
	}
	while(i != oldSize){
		printf("The num being replaced is %s and the num is %lu.\n",i,nums[i]);
		//sprintf(toReturn[i], "%lu", nums[i]);
		if(i == oldSize){
			break;
		}else{i++;}
	}	*/

	return toReturn;
}


int main(int argc, char* argv[]) {
	//int j;
	//for(j=2;j< argc; j++) printf("%d\n",(int)atoi(argv[j]));
	pid_t status[argc];
	int sols[argc];
	signal(SIGUSR1, my_handler);

	argv = setupArray(argc, argv);
printf("Program came back\n");
	int j;
	argc--;
	////for(j=0;j< argc; j++) printf("%d: %s\n",j,argv[j]);
	if(argv[1] != NULL){
		int sols[argc];
		int i;
		for(i = 1; i < argc; i++){
			pid_t cpid = fork();
			totalCalls++;
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
			completedCalls++;
			//kill(getpid(),SIGUSR1);
			int i;
			for(i = 0; i<argc; i++){
				if(responded == status[i] && WIFSIGNALED(responded) != 0){
					sols[i] = resp;
				}
			}
			done++;
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
