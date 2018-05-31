#include<iostream>
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

int base64val(int *pattern, int startInd){
	int temp = 32;
	int val = 0;
	for(int i=0; i<6; ++i){
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

int main(){
	// encode to base64 
	char input[] = "Hello there";
	int inputLength = 0;
	for(int i=0; input[i]!='\0'; ++i){
		cout << input[i];
		++inputLength;
	}
	cout << endl << "Length: " << inputLength << endl << endl;

	int paddingLen = 0;
	if(inputLength % 3 == 2) paddingLen = 8;
	if(inputLength % 3 == 1) paddingLen = 16;

	int binaryPattern[(8 * inputLength) + paddingLen];
	int count = 0;

	for(int i=0; input[i]!='\0'; ++i){
		int charVal = input[i];
		cout << input[i] << " Val: "<< charVal << endl;

		int *p;
		p = decToBinary(charVal);

		for(int i=0; i<8; ++i){
			cout << *(p+i);
			binaryPattern[count] = *(p+i);
			++count;
		}
		cout << endl << endl;
	}

	for(int i=0; i<paddingLen; ++i){
		binaryPattern[count] = 0;
		++count;
	}

	for(int i=0; i<((8 * inputLength) + paddingLen); ++i){
		if(i%8 == 0 && i!=0) cout << " ";
		cout << binaryPattern[i];
	}
	cout << endl << endl;

	for(int i=0; i<((8 * inputLength) + paddingLen); ++i){
		if(i%6 == 0 && i!=0) cout << " ";
		cout << binaryPattern[i];
	}
	cout << endl << endl;
	
	int tempVal = 0;

	int base64vals[((8 * inputLength) + paddingLen) / 6];
	for(int i=0; i<(((8 * inputLength) + paddingLen) / 6); ++i){
		tempVal = base64val(binaryPattern, i*6);
		base64vals[i] = tempVal;
	}

	for(int i=0; i<(((8 * inputLength) + paddingLen) / 6); ++i){
		cout << base64vals[i] << " ";
	}
	cout << endl << endl;

	char base64chars[((8 * inputLength) + paddingLen) / 6];

	for(int i=0; i<(((8 * inputLength) + paddingLen) / 6); ++i){
		base64chars[i] = base64tableChar(base64vals[i]);
	}

	if(paddingLen / 8 == 2){
		base64chars[(((8 * inputLength) + paddingLen) / 6) - 1] = '=';
		base64chars[(((8 * inputLength) + paddingLen) / 6) - 2] = '=';
	}
	if(paddingLen / 8 == 1){
		base64chars[(((8 * inputLength) + paddingLen) / 6) - 1] = '=';
	}

	for(int i=0; i<(((8 * inputLength) + paddingLen) / 6); ++i){
		cout << base64chars[i];
	}
	cout << endl << endl;
}