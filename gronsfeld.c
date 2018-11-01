#include <stdio.h>
#include <string.h>
#include <math.h>


int calculate_shift_for_letter(int letter_shift_index, long int cipher_key);
int calculate_cipher_key_length(long int number);
int shift_letter(int shift, char letter, int cipher);


// important tips to get 100 points:
//http://discuss.spoj.com/t/4840-szyfr-gronsfelda-wi-szyfr/9104/3

int main(void) {
	char flag[10];
	char letter;
	int cipher;

	long int cipher_key;

	scanf("%s", flag);
	scanf("%ld", &cipher_key);

	int letter_shift_index = 0;
	
	while((letter=getchar())!=EOF) {

		if (strcmp("SZYFRUJ", flag) == 0) {
			cipher = 1;
		} else {
			cipher = 0;
		}

		// check if small letter
		if (letter <65 || letter >90) {
			putchar(letter);
			continue;
		}
			
		int shift = calculate_shift_for_letter(letter_shift_index, cipher_key);
		letter_shift_index++;

		int shifted_letter = shift_letter(shift, letter, cipher);
		putchar(shifted_letter);
	}
	return 0;
}

int calculate_shift_for_letter(int letter_shift_index, long int cipher_key) {
	// calculate how many digits int number consist
	int key_length = calculate_cipher_key_length(cipher_key);
	
	// choose proper number from cipher_key for letter
	// taking into consideration that when it is more letters that
	// length of ciper_key, go to begining of cipher_key
	return (int)(cipher_key/pow(10, key_length-(letter_shift_index%key_length)-1))%10;
}

int calculate_cipher_key_length(long int number) {
	int count = 0;
	while (number != 0) {
		count++;
		number = number/10;
	}
	return count;
}

int shift_letter(int shift, char letter, int cipher) {
	int shifted;
	if (cipher) {
		shifted = (letter + shift- (int)'A') % 26 + (int)'A'; 
	} else {
		shifted = (letter - shift + (int)'A') % 26 + (int)'A'; 
	}
	return  shifted;
}
