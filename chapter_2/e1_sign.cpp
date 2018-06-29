#include "apue.h" 
#include <fcntl.h> 
#include <stdio.h> 

#define WORD_MAX 100 
#define LETTER_MAX 26 

int main() 
{
	char word[WORD_MAX], sign_num[LETTER_MAX], sign[LETTER_MAX]; 
	char *w; 
	int index; 
	while (EOF != scanf("%s", word)) {
		memset(sign_num, 0, sizeof(sign_num)); 
		w = word; 
		while (*w) {
			index = *w - 'a'; 	
			++w; 
			if (0 > index || LETTER_MAX <= index ) 
				continue; 

			++(sign_num[index]); 
		}
		index = 0; 
		for (int i = 0; i < LETTER_MAX; ++i) {
			if (0 == sign_num[i]) 
				continue; 

			sign[index++] = 'a' + i; 
			if (1 < sign_num[i]) 
				sign[index++] = '0' + sign_num[i]; 
		}
		sign[index] = '\0'; 
		printf("%s %s\n", sign, word); 
	}

	return 0; 
}
