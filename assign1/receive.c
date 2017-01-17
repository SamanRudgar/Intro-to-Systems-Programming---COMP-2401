
/* File is receive.c
 
 Purpose: simulate the receiveing end of a message over the network.  It converts
 a message given as an array of short integers into characters.
 The input message uses 1-bit error correction code.
 As part of the simulation, the program also corrects any 1-bit errors in the receiving message.
 
 
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


int readMessage(short *msg, int *numRead);
int char2Short(char c, short *encodedChar);
int setParityBits(short *num);
int short2Char(short encodedChar, char *c);
int correctCode(short *num);




/***********************************************************************************/


int main(int argc, char *argv[])

{
	int rc = 0;		// return code

	short encodedMsg[MAX_MSG_LENGTH];  // message
	int numRead = 0;  // number of characters in the message
	int i;


	// read the message
	printf("Please enter the transmissted : ");
    readMessage(encodedMsg, &numRead);
	
    
 	// print the uncorrected message
    
    // unpack the characgter that are encoded in the message into characters and print
    // the message one character at a time.
	printf("\n\n Received message  with errors:\n ");
	for (i = 0; i < numRead; i++) {
		char c;
		short2Char(encodedMsg[i], &c);
		printf("%c", c);
	}


    // correct the message
	for (i = 0; i < numRead; i++) {
		correctCode(&encodedMsg[i]);
	}



	// print the corrected message
	printf("\n\n Corrected Message after error correction:\n");
	for (i = 0; i < numRead; i++) {
		char c;
		short2Char(encodedMsg[i], &c);
		printf("%c", c);
	}
	getchar();

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

int readMessage(short *receivedMsg, int *numRead)
{
	int i;
	int rc = 1;
    char *s1=NULL;
    char *sep=" ";
    size_t lineLength;
    
    
    getline(&s1,&lineLength, stdin);
    s1 = strtok(s1, sep);
 	for (i=0; s1; s1= strtok(NULL, sep),i++) {
 		rc = sscanf(s1,"%hd", &receivedMsg[i]);
   }
    *numRead = i;
	return(0);
}



/*************************************************************************/
/* collect of a short bits 3,5,6,7,9,10,11,12  to bits 0-7 of a char

input
encodedChar - a short with the bits of c

output
character c

*/


int short2Char(short encodedChar, char *c)

{
	short mask = 0x0001;
	int i;
	int bitSet;

    // read the code in char2Short in the transmit.c program and reverse the setting of bits.

	*c = 0;
	for (i = 1; i < 12; i++) {
		// check if bit i is set
		bitSet = getCharBit(encodedChar, i);

		// set the correct bit in the char character
		if (!bitSet) continue;
		switch (i) {
		case 1:
		case 2:
		case 3:
			setCharBit(0, c);
			break;
		case 4:
		case 5:
			setCharBit(1, c);
			break;
		case 6:
			setCharBit(2, c);
			break;
		case 7:
			setCharBit(3, c);
			break;
		case 8:
		case 9:
			setCharBit(4, c);
			break;
		case 10:
			setCharBit(5, c);
			break;
		case 11:
			setCharBit(6, c);
			break;
		case 12:
			setCharBit(7, c);
			break;
		default:
			printf("This should not happen !!!!\n");
			assert(0);
		}
	}
	return(0);
    
    
    
    return(0);
}


/*************************************************************************************/


/* sets the parityh bits in the variable num to 1


input
num - the short numbe where parithy bits must be set
*/


int correctCode(short *num)

{
	int mask;
	int sum;
	int bitNumber = 0; //  bit number with the error bit
	int parity;		// a parity bit either 0 or 1
	int storedParity; // the parity bit in the encoded char

	
    // check parity bit p1
    int p1Received = getShortBit(*num,1); 
    // get the number of 1's in *num and the mask P1_MASK
    int p1Expected = checkingForParity(*num,P1_MASK);
    // compute the required even parity (namely, if the number of 1's is odd then
    // the parity bit is 1.
    p1Expected %= 2;
    // compare the computed parity bit to the stored parity bit.
    // If they are different then add the correct value to bitNumber
    if(p1Expected != p1Received){bitNumber += p1Received;}
    
    // Repeat for parity bits 2,4 and 8

    int p2Received = getShortBit(*num,2); 
    int p2Expected = checkingForParity(*num,P2_MASK);
    p2Expected %= 2;
    if(p2Expected != p2Received){bitNumber += p2Received;}

    int p4Received = getShortBit(*num,4); 
    int p4Expected = checkingForParity(*num,P4_MASK);
    p4Expected %= 2;
    if(p4Expected != p4Received){bitNumber += p4Received;}

    int p8Received = getShortBit(*num,8); 
    int p8Expected = checkingForParity(*num,P8_MASK);
    p8Expected %= 2;
    if(p8Expected != p8Received){bitNumber += p8Received;}


    // if bitNumber is not 0 then the bit in position bitNumber has changed.
    // in this case fip it back.
    if(bitNumber != 0){
    	flipBitShort(bitNumber,num);
    }
	
    return(0);
}

