#include<iostream>
using namespace std;

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

int decval(int *pattern, int startInd){
	int temp = 128;
	int val = 0;
	for(int i=0; i<8; ++i){
		if(pattern[startInd + i] == 1) val += temp;
		temp = temp / 2;
	}
	return val;
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
	// decode from base64
	char input64[] = "SGVsbG8gdGhlcmU";
	int inputLength64 = 0;
	for(int i=0; input64[i]!='\0'; ++i){
		cout << input64[i];
		++inputLength64;
	}
	cout << endl << "Length: " << inputLength64 << endl << endl;

	int paddingLen64 = 0;
	if(inputLength64 % 4 == 3) paddingLen64 = 6;
	if(inputLength64 % 4 == 2) paddingLen64 = 12;
	if(inputLength64 % 4 == 1) paddingLen64 = 18;

	int binaryPattern64[(6 * inputLength64) + paddingLen64];
	int count64 = 0;

	for(int i=0; input64[i]!='\0'; ++i){
		int charVal64 = base64tableVal(input64[i]);
		cout << input64[i] << " Val: "<< charVal64 << endl;

		int *p;
		p = b64ToBinary(charVal64);

		for(int i=0; i<6; ++i){
			cout << *(p+i);
			binaryPattern64[count64] = *(p+i);
			++count64;
		}
		cout << endl << endl;
	}

	for(int i=0; i<paddingLen64; ++i){
		binaryPattern64[count64] = 0;
		++count64;
	}

	for(int i=0; i<((6 * inputLength64) + paddingLen64); ++i){
		if(i%6 == 0 && i!=0) cout << " ";
		cout << binaryPattern64[i];
	}
	cout << endl << endl;

	for(int i=0; i<((6 * inputLength64) + paddingLen64); ++i){
		if(i%8 == 0 && i!=0) cout << " ";
		cout << binaryPattern64[i];
	}
	cout << endl << endl;

	int tempVal64 = 0;

	int decvals[((6 * inputLength64) + paddingLen64) / 8];
	for(int i=0; i<(((6 * inputLength64) + paddingLen64) / 8); ++i){
		tempVal64 = decval(binaryPattern64, i*8);
		decvals[i] = tempVal64;
	}

	for(int i=0; i<(((6 * inputLength64) + paddingLen64) / 8); ++i){
		cout << decvals[i] << " ";
	}
	cout << endl << endl;

	char decChars[((6 * inputLength64) + paddingLen64) / 8];

	for(int i=0; i<(((6 * inputLength64) + paddingLen64) / 8); ++i){
		if(decvals[i] == 0){decChars[i] = ' ';}
		else{decChars[i] = decvals[i];}
	}

	for(int i=0; i<(((6 * inputLength64) + paddingLen64) / 8); ++i){
		cout << decChars[i];
	}
	cout << endl << endl;
}