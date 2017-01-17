/* File is transmit.c
 
 Purpose: simulate a transmission of characters over the network.  It converts
 a message given as an array of characters to an array of short integers that are sent over the network.  
 The converted message uses 1-bit error correction code.  
 As part of the simulation, the program also injects errors to the encoded message by flipping one bit.

 
  Revision:
 a. Initial code - Doron Nussbaum

 
*/

/***********************************************************************************/
// INCLUDES

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "bit_manipulation.h"


/***********************************************************************************/
// DEFINES


#define MAX_MSG_LENGTH 256
#define P1_MASK 0xaa8   // 0b0101010101000
#define P2_MASK 0xcc8	// 0b0110011001000
#define P4_MASK 0x10e0	// 0b1000011100000
#define P8_MASK 0x1e00  // 0b1111000000000



/***********************************************************************************/
// FUNCTION PROTOTYPE

int readMessage(char *s, int len, int *numRead);
int char2Short(char c, short *encodedChar);
int setParityBits(short *num);



/***********************************************************************************/



int main(int argc, char *argv[])

{
	int rc = 0;		// return code

	char s[MAX_MSG_LENGTH];  // message
	short encodedMsg[MAX_MSG_LENGTH];
	int numRead = 0;  // number of characters in the message
	int i;


	// read the message
	printf("Please enter a message to transmit: ");
    readMessage(s, MAX_MSG_LENGTH, &numRead);
	//printf("\n\n-------%d-----------\n\n",(int)encodedMsg);

    
    /* encode the message by:
     a. spread the bits of each char onto an integer
     b. set the even parity bit for encoded character
     */

	for (i = 0; i < numRead; i++) {
		char2Short(s[i], &encodedMsg[i]);
		printf("\n\n-------%d-----------\n\n",(int)encodedMsg);
		printf("\n\n-------%d-----------\n\n",(int)P1_MASK);
		setParityBits(&encodedMsg[i]);
	}



	// add errors to mesage 
	for (i = 0; i < numRead; i++) {
		if (rand() < (RAND_MAX / 2 )) {
			int bit = rand() % 13;
			setShortBit(bit, &encodedMsg[i]);
		}
	}


	// print the message
	printf("\n\n Transmitted coded message:\n");
	for (i = 0; i < numRead; i++) {
		printf("%d ", encodedMsg[i]);

	}
	printf("\n\n--------------------------------------\n\n");

	return(0);
}


/***********************************************************************************/
/* reads a message from the user

input
len - maximum length of mesage that should be read

output
s - contains the message
numRead - the number of characters in the message
*/

int readMessage(char *s, int len, int *numRead)
{
	int i;
	int rc = 1;
	*numRead = 0;
	for (i = 0; i < len && rc != 0; i++) {
		rc = scanf("%c", &s[i]);
		if (s[i] == '\n') break;
		(*numRead)++;
	}
	return(0);
}


/*************************************************************************/
/* spreads bits 0-7 of the character c into bits 3,5,6,7,9,10,11,12 of the short encodedChar

input
character c

output
encodedChar - a short with the bits of c

*/


int char2Short(char c, short *encodedChar){
	short mask = 0x0001;
	int i;
	int bitSet;

	*encodedChar = 0;
	for (i = 0; i < 8; i++) {
		// check if bit i is set
		bitSet = getShortBit(c, i);

		// set the correct bit in the encoded character
		if (!bitSet) continue;
		switch (i) {
		case 0:
			setShortBit(3, encodedChar);
			break;
		case 1:
		case 2:
		case 3:
			setShortBit(4 + i, encodedChar);
			break;
		case 4:
		case 5:
		case 6:
		case 7:
			setShortBit(5 + i, encodedChar);
			break;
		default:
			printf("This should not happen !!!!\n");
			assert(0);
		}
	}
	return(0);
}


/*************************************************************************************/









/*************************************************************************************/


/* sets the parityh bits in the variable num to 1


input
num - the short numbe where parithy bits must be set
*/




int setParityBits(short *num)

{
	int mask;
	int sum;

	// set parity bit p1 using mask P1_MASK by

    // get the number of bits in *num and the mask P1_MASK
	int p1 = checkingForParity(*num,P1_MASK); 
	printf("The number in parity 1 is %d \n", p1);
	//short p1 = 1;
    // if the number of bits is odd then set the corresponding parity bit to 1  (even parity)
    if(p1%2 == 1){
    	setShortBit(1,num);
    }
    
    // do the same for parity bits in positions 2,4,8
	int p2 = checkingForParity(*num,P2_MASK); 
    if(p2%2 == 1){
    	setShortBit(2,num);
    }
    printf("The number in parity 2 is %d \n", p2);

	int p4 = checkingForParity(*num,P4_MASK); 
    if(p4%2 == 1){
    	setShortBit(4,num);
    }
    printf("The number in parity 4 is %d \n", p4);


	int p8 = checkingForParity(*num,P8_MASK); 
    if(p8%2 == 1){
    	setShortBit(8,num);
    }
    printf("The number in parity 8 is %d \n", p8);

    
    
    
    
    
	return(0);
}

