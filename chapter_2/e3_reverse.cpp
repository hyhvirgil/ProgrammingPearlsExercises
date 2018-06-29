#include <stdio.h> 

void print(int* array, int max_size, const char* reason, int step_num) 
{
	char buffer[100] = {'\0'}; 
    for (int i = 0; i < max_size; ++i) {
        sprintf(buffer, "%s %d", buffer, array[i]); 
    }   
    printf("%s %d: %s\n\n", reason, step_num, buffer); 
}

void reset(int* array, int max_size) 
{
    for (int i = 0; i < max_size; ++i) {
        array[i] = i + 1;  
    }   
}

void swap(int* a, int* b)
{
	int temp = *a; 
	*a = *b; 
	*b = temp; 
}

void reverse(int* array, int begin, int end)
{
	while (begin < end) {
		swap(&array[begin], &array[end]); 
		++begin; 
		--end; 
	}
}

void reverse_rotation(int* array, int max_size, int i)
{
	i = i % max_size; 
	reverse(array, 0, i-1); 
	reverse(array, i, max_size-1); 
	reverse(array, 0, max_size-1); 
}

int main()
{
	int max_size = 12; 
	int array[max_size]; 
	reset(array, max_size); 
	print(array, max_size, "default", 0); 

	int i; 
	while (EOF != scanf("%d", &i)) {
		reset(array, max_size); 
		reverse_rotation(array, max_size, i); 
		print(array, max_size, "move ", i); 
	}

	return 0; 
}

