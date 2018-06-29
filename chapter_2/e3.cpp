#include <stdio.h>

void jump_round(int* array, int max_size, int index, int i) 
{
	int temp = array[index]; 
	while (index + i < max_size) {
		array[index] = array[index+i]; 
		index += i; 
	}
	array[index] = temp; 
}

void jump(int* array, int max_size, int n, int i) 
{
	if (max_size < n) 
		return; 

	for (int index = max_size-n; index < max_size-n+i; ++index) {
		jump_round(array, max_size, index, i); 
	}
}

void left_rotation_jump(int* array, int max_size, int i)
{
	int n = max_size; 
	if (0 == n || n == i)
		return; 
	else if (n < i) 
		i %= n; 
	
	if (0 == i) 
		return; 

	jump(array, max_size, n, i); 
	if (0 == n%i)
		return; 

	do {
		int temp = i; 
		i = abs(i - (n - i)); 
		n = i; 
		jump(array, max_size, n, i); 
	} while(1 < i && 0 != n%i); 
}

void print(int* array, int max_size, char* reason) 
{
	char buffer[100] = '\0'; 
	for (int i = 0; i < max_size; ++i) {
		sprintf(buffer, "%d ", array[i]); 
	}
	printf("%s: %s\n\n", reason, buffer); 
}

void reset(int* array, int max_size) 
{
	for (int i = 0; i < max_size; ++i) {
		array[i] = i + 1; 
	}
}

int main() 
{
	int max_size = 12; 
	int array[max_size];  
	reset(array, max_size); 
	print(array, max_size, "default"); 

	left_rotation_jump(array, max_size, 1); 
	print(array, max_size, "move 1"); 

	reset(array, max_size); 
	left_rotation_jump(array, max_size, 2); 
	print(array, max_size, "move 2"); 

	reset(array, max_size); 
	left_rotation_jump(array, max_size, 3); 
	print(array, max_size, "move 3"); 

	reset(array, max_size); 
	left_rotation_jump(array, max_size, 4); 
	print(array, max_size, "move 5"); 

	reset(array, max_size); 
	left_rotation_jump(array, max_size, 7); 
	print(array, max_size, "move 7"); 

	reset(array, max_size); 
	left_rotation_jump(array, max_size, 8); 
	print(array, max_size, "move 8"); 

	reset(array, max_size); 
	left_rotation_jump(array, max_size, 13); 
	print(array, max_size, "move 13"); 
	
	reset(array, max_size); 
	left_rotation_jump(array, max_size, 15); 
	print(array, max_size, "move 15"); 
	
	return 0; 
}
