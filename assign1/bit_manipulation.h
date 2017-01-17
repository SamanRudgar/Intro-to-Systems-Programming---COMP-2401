//
//  bit_manipulation.h
//  
//
//  Created by nuss on 2015-01-18.
//
//

#ifndef _bit_manipulation_h
#define _bit_manipulation_h

int getCharBit(char c, int bitNum);
int getShortBit(short num, int bitNum);
int setShortBit(int bitNum, short *num);
int setCharBit(int bitNum, char *num);
int countBits(short num);
int flipBitShort(int bitNum, short *num);
int checkingForParity(short num, short mask);

#endif
