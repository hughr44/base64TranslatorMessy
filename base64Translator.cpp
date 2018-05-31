#include<iostream>
#include<math.h>
using namespace std;

int *decToBinary(int num){
	int temp = num;
	static int bin[8];
	int val = 128;
	for(int i=0; i<8; ++i){
		if(temp < val){
			bin[i] = 0;
		}
		else{
			bin[i] = 1;
			temp -= val;
		}
		val = val / 2;
	}
	return bin;
}

int *b64ToBinary(int num){
	int temp = num;
	static int bin[6];
	int val = 32;
	for(int i=0; i<6; ++i){
		if(temp < val){
			bin[i] = 0;
		}
		else{
			bin[i] = 1;
			temp -= val;
		}
		val = val / 2;
	}
	return bin;
}

int binaryToVal(int *pattern, int startInd, int numBits){
	int temp = pow(2, (numBits - 1));
	int val = 0;
	for(int i=0; i<numBits; ++i){
		if(pattern[startInd + i] == 1) val += temp;
		temp = temp / 2;
	}
	return val;
}

char base64tableChar(int index){
	char char64;
	switch(index){
		case 0: char64 = 'A'; break;
		case 1: char64 = 'B'; break;
		case 2: char64 = 'C'; break;
		case 3: char64 = 'D'; break;
		case 4: char64 = 'E'; break;
		case 5: char64 = 'F'; break;
		case 6: char64 = 'G'; break;
		case 7: char64 = 'H'; break;
		case 8: char64 = 'I'; break;
		case 9: char64 = 'J'; break;
		case 10: char64 = 'K'; break;
		case 11: char64 = 'L'; break;
		case 12: char64 = 'M'; break;
		case 13: char64 = 'N'; break;
		case 14: char64 = 'O'; break;
		case 15: char64 = 'P'; break;
		case 16: char64 = 'Q'; break;
		case 17: char64 = 'R'; break;
		case 18: char64 = 'S'; break;
		case 19: char64 = 'T'; break;
		case 20: char64 = 'U'; break;
		case 21: char64 = 'V'; break;
		case 22: char64 = 'W'; break;
		case 23: char64 = 'X'; break;
		case 24: char64 = 'Y'; break;
		case 25: char64 = 'Z'; break;
		case 26: char64 = 'a'; break;
		case 27: char64 = 'b'; break;
		case 28: char64 = 'c'; break;
		case 29: char64 = 'd'; break;
		case 30: char64 = 'e'; break;
		case 31: char64 = 'f'; break;
		case 32: char64 = 'g'; break;
		case 33: char64 = 'h'; break;
		case 34: char64 = 'i'; break;
		case 35: char64 = 'j'; break;
		case 36: char64 = 'k'; break;
		case 37: char64 = 'l'; break;
		case 38: char64 = 'm'; break;
		case 39: char64 = 'n'; break;
		case 40: char64 = 'o'; break;
		case 41: char64 = 'p'; break;
		case 42: char64 = 'q'; break;
		case 43: char64 = 'r'; break;
		case 44: char64 = 's'; break;
		case 45: char64 = 't'; break;
		case 46: char64 = 'u'; break;
		case 47: char64 = 'v'; break;
		case 48: char64 = 'w'; break;
		case 49: char64 = 'x'; break;
		case 50: char64 = 'y'; break;
		case 51: char64 = 'z'; break;
		case 52: char64 = '0'; break;
		case 53: char64 = '1'; break;
		case 54: char64 = '2'; break;
		case 55: char64 = '3'; break;
		case 56: char64 = '4'; break;
		case 57: char64 = '5'; break;
		case 58: char64 = '6'; break;
		case 59: char64 = '7'; break;
		case 60: char64 = '8'; break;
		case 61: char64 = '9'; break;
		case 62: char64 = '+'; break;
		case 63: char64 = '/'; break;
	}
	return char64;
}

int base64tableVal(char char64){
	int val;
	switch(char64){
		case '=': val = 0; break; // incase input took padding into account 
		case 'A': val = 0; break;
		case 'B': val = 1; break;
		case 'C': val = 2; break;
		case 'D': val = 3; break;
		case 'E': val = 4; break;
		case 'F': val = 5; break;
		case 'G': val = 6; break;
		case 'H': val = 7; break;
		case 'I': val = 8; break;
		case 'J': val = 9; break;
		case 'K': val = 10; break;
		case 'L': val = 11; break;
		case 'M': val = 12; break;
		case 'N': val = 13; break;
		case 'O': val = 14; break;
		case 'P': val = 15; break;
		case 'Q': val = 16; break;
		case 'R': val = 17; break;
		case 'S': val = 18; break;
		case 'T': val = 19; break;
		case 'U': val = 20; break;
		case 'V': val = 21; break;
		case 'W': val = 22; break;
		case 'X': val = 23; break;
		case 'Y': val = 24; break;
		case 'Z': val = 25; break;
		case 'a': val = 26; break;
		case 'b': val = 27; break;
		case 'c': val = 28; break;
		case 'd': val = 29; break;
		case 'e': val = 30; break;
		case 'f': val = 31; break;
		case 'g': val = 32; break;
		case 'h': val = 33; break;
		case 'i': val = 34; break;
		case 'j': val = 35; break;
		case 'k': val = 36; break;
		case 'l': val = 37; break;
		case 'm': val = 38; break;
		case 'n': val = 39; break;
		case 'o': val = 40; break;
		case 'p': val = 41; break;
		case 'q': val = 42; break;
		case 'r': val = 43; break;
		case 's': val = 44; break;
		case 't': val = 45; break;
		case 'u': val = 46; break;
		case 'v': val = 47; break;
		case 'w': val = 48; break;
		case 'x': val = 49; break;
		case 'y': val = 50; break;
		case 'z': val = 51; break;
		case '0': val = 52; break;
		case '1': val = 53; break;
		case '2': val = 54; break;
		case '3': val = 55; break;
		case '4': val = 56; break;
		case '5': val = 57; break;
		case '6': val = 58; break;
		case '7': val = 59; break;
		case '8': val = 60; break;
		case '9': val = 61; break;
		case '+': val = 62; break;
		case '/': val = 63; break;
	}
	return val;
}

int main(){
	// ask user if encode or decode
	bool encode = true; // set to false if decode
	char input[] = "ShipStation is COOL"; // ask user to input text
	if(encode){cout << "Encode to base 64" << endl;}
	else{cout << "Decode from base 64" << endl;}

	// find length of input
	int inputLength = 0;
	cout << "Input:" << endl;
	for(int i=0; input[i]!='\0'; ++i){
		cout << input[i];
		++inputLength;
	}
	// padding length
	int paddingLen = 0;
	int totalNumBits = 0;
	int numCharsOut = 0;
	int bitsPerCharOut = 0;
	int bitsPerCharIn = 0;
	if(encode){
		if(inputLength % 3 == 2) paddingLen = 8;
		if(inputLength % 3 == 1) paddingLen = 16;
		totalNumBits = (8 * inputLength) + paddingLen;
		numCharsOut = totalNumBits / 6;
		bitsPerCharOut = 6;
		bitsPerCharIn = 8;
	}
	else{
		if(inputLength % 4 == 3) paddingLen = 6;
		if(inputLength % 4 == 2) paddingLen = 12;
		if(inputLength % 4 == 1) paddingLen = 18;
		totalNumBits = (6 * inputLength) + paddingLen;
		numCharsOut = totalNumBits / 8;
		bitsPerCharOut = 8;
		bitsPerCharIn = 6;
	}
	// create binary pattern
	int binaryPattern[totalNumBits];
	int count = 0;
	int charVal = 0;
	for(int i=0; input[i]!='\0'; ++i){
		if(encode){charVal = input[i];}
		else{charVal = base64tableVal(input[i]);}
		int *p;
		if(encode){p = decToBinary(charVal);}
		else{p = b64ToBinary(charVal);}

		for(int i=0; i<bitsPerCharIn; ++i){
			binaryPattern[count] = *(p+i);
			++count;
		}
	}
	// adding 0's for padding
	for(int i=0; i<paddingLen; ++i){
		binaryPattern[count] = 0;
		++count;
	}
	// creating new values from binary pattern
	int tempVal = 0;
	int newVals[numCharsOut];
	for(int i=0; i<numCharsOut; ++i){
		tempVal = binaryToVal(binaryPattern, i*bitsPerCharOut, bitsPerCharOut);
		newVals[i] = tempVal;
	}

	char newChars[numCharsOut];
	for(int i=0; i<numCharsOut; ++i){
		if(encode){newChars[i] = base64tableChar(newVals[i]);}
		else{
			if(newVals[i] == 0){newChars[i] = ' ';}
			else{newChars[i] = newVals[i];}
		}
	}
	if(encode){
		if(paddingLen / 8 == 2){
			newChars[numCharsOut - 1] = '=';
			newChars[numCharsOut - 2] = '=';
		}
		if(paddingLen / 8 == 1){
			newChars[numCharsOut - 1] = '=';
		}
	}

	cout << endl << "Output:" << endl;
	for(int i=0; i<numCharsOut; ++i){
		cout << newChars[i];
	}
}