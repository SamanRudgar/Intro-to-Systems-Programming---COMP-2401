// FILE is bit_manipulation.c

/* purpose: help functions for manipulating bits.  Although these are functions here in reality they should be 
   macros defined using the #define statement.

Revisions:
file created: Doron Nussbaum

*/
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "bit_manipulation.h"

/***************************************************/
#if 0

// code used for testing  

int main(int argc, char *argv[])

{
	int rc = 0;		// return code


	short test = 0;
	short modified;
	int bitNum;		// bit number to be used
	
	
	test = 0;
	bitNum = 2;
	modified = test;
	flipBitShort(bitNum, &modified);
	printf("test_int=%d, flipping bit #=%d, answer should be=%d, test_modified=%d\n ", test, bitNum, 4, modified);

	test = 2;
	bitNum = 1;
	modified = test;
	printf("test_int=%d,modified bit #=%d, answer should be=%d, test_modified=%d, count=%d\n ", test, bitNum, 1, getShortBit(modified,bitNum),countBits(modified));

	test = 0;
	bitNum = 2;
	modified = test;
	setShortBit(bitNum,&modified);
	printf("test_int=%d, flipping bit #=%d, answer should be=%d, test_modified=%d\n ", test, bitNum, 4, modified);

   getchar();
   
	return(0);
}


#endif





/********************************************************************************/
/* input:
 char c
 bitNum - the bit number (bit range 0-15)
 
 Return:
 the ith bit of c (e.g., c=0x14 and biNum =2 then the function returns 0x04
 
*/
 
int getCharBit(char c, int bitNum){
  // add code here
	
	int answer = ((c >> bitNum) & 1);
	return answer;
}



/*********************************************************************************/

/* input:
 short integer num
 bitNum - the bit number (bit range 0-15)
 
 Return:
 the ith bit of num (e.g., num=0x14 and biNum =2 then the function returns 0x04
 
 */
int getShortBit(short num, int bitNum){
   // add code here
	int bit = 0;
	bit |= 1 << num;
	return bit;
}



/********************************************************************************/


// sets bit i in num to 1
int setShortBit(int bitNum, short *num)

{  
   // add code here
	*num = *num|(1 << bitNum);
	return(0);
}

/********************************************************************************/


// sets bit i in num to 1
int setCharBit(int bitNum, char *num)

{  
   // add code here
	*num |= (1 << bitNum);
	return(0);
}

/********************************************************************************/


//  count the number of bits in the short and returns the number of bits

/* input:
   num - an integer

Output:
the number of bits in num

*/

int countBits(short num){
   	int sum=0;
   	int i;
   	for (i = 0; i < 16; i++) {
		// check if bit i is set
		short bitSet = getCharBit(num, i);

		if (bitSet){
			sum++;
		}
	}

   return sum;
}

/********************************************************************************/


int checkingForParity(short num, short mask){
	

	short ones = (num & mask);
	printf("%d\n",(int) ones );
	int count = 0;

   	for (int i = 0; i < 16; i++) {
		// check if bit i is set
		int bitSet = getCharBit(ones, i);

		if (bitSet==1){
			count++;
		}
	}

	return count;
}



/********************************************************************************/


// flips the ith bit in num (either from 0 to 1 or from 1 to 
/* input:
   bitNum - the bit number to be flipped.  Note that bits number in num are from 0-15
   input/output
   num - an integer
*/

int flipBitShort(int bitNum, short *num)

{

   // add code here.  Use the ^ (xor) operation 

	*num ^= 1 << bitNum;

	return(0);
}

