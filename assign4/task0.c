
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "task0.h"

int isPrime(int number)
{
    int i;
    for(i = 2; i*i <= number; i++) {
	    usleep(101);
	    if (number % i == 0) {
	 		return(0);
		} 
    }
	return(1);
}


int main(int argc, char* argv[]) {

	if(argv[1] != NULL){
		char *ptr;
  		int num = strtol(argv[1], &ptr, 10);
  		if(num > 0){
			int ans = isPrime(num);
			//printf("The number %d is: %d\n", num, ans);
  			return isPrime(num);
  		}else{
			//printf("The number is: 2\n");
  			return 2;
  		}
	}
  //printf("The number is: 2\n");
  return 2;
}
