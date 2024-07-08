#include<stdio.h>
#include<string.h>


void vigenere_en(char* plaintext, char* key, char* ciphertext) {

	int i = 0;
	while(i<strlen(plaintext)){
		int temp = 0;

		temp = plaintext[i] - 97; //plaintext 
		temp += (key[(i % (strlen(key)))] - 97); //key + plaintext

		if (temp > 26) 
			temp %= 26; //mod 26

		ciphertext[i] = (temp + 97); //ciphertext의 각 요소마다 알파벳 아스키코드 대입

		i++;
	}
	ciphertext[i] = NULL; //문자 다음 요소에 NULL삽입.

}

void vigenere_de(char* ciphertext, char* key, char* plaintext) {

	int i = 0;
	while (i < strlen(ciphertext)) {
		int temp = 0;

		temp = ciphertext[i] - 97; //ciphertext 
		temp -= (key[ (i % (strlen(key) )) ] - 97); //key + ciphertext

		if (temp < 0)
			temp += 26; //mod 26

		plaintext[i] = (temp + 97); //plaintext의 각 요소마다 알파벳 아스키코드 대입

		i++;
	}
	plaintext[i] = NULL; //문자 다음 요소에 NULL삽입.

}


void main() {
	char plaintext[301];
	char key[11];
	char ciphertext[301];

	int choose = 0;
	while(true)
	{
		printf("====================VigenereCipher====================\n");
		printf("1.암호화\n2.복호화\n선택하세요 : ");
		scanf_s("%d",&choose);
		getchar();

		printf("암호화 키 입력 (최대 10자) : ");
		gets_s(key);

		if (choose == 1) {
			printf("평문입력 (최대 300자, 알파벳소문자) : ");
			gets_s(plaintext);

			printf("암호문 : ");
			vigenere_en(plaintext, key, ciphertext);

			printf("%s\n", ciphertext);
		}

		else if (choose == 2) {
			printf("암호문입력 (최대 300자, 알파벳소문자) : ");
			gets_s(ciphertext);

			printf("평문 : ");
			vigenere_de(ciphertext, key, plaintext);

			printf("%s\n", plaintext);
		}

		else
			printf("다시입력하세요.\n");
		
	}
}
