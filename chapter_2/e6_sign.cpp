#include <stdio.h> 

#define GET_INDEX(i) i-'a'

char rule[26] = {
	'2','2','2','3','3','3',
	'4','4','4','5','5','5','6','6','6',
	'7','7','7','7','8','8','8','9','9','9','9'
};

char get_sign(char letter)
{
	if ('a' > letter || 'z' < letter)
		return letter; 

	return rule[GET_INDEX(letter)];
}

int main() 
{
	int max_length = 100; 
	char buffer[max_length], sign[max_length]; 
	char* letter;
	int index = 0; 
	while (EOF != scanf("%s", &buffer)) {
		letter = buffer;
		index = 0; 
		while (*letter) {
			sign[index++] = get_sign(*letter++);
		}
		sign[index] = '\0';
		printf("%s %s\n", sign, buffer);
	}

	return 0; 
}
