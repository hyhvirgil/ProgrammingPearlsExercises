#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define NUM 4300000000 

int main() 
{
	srand((unsigned int)time(NULL)); 
	for (int i = 0; i < NUM; ++i) {
		printf("%d: %u\n", i, (unsigned int)rand() % NUM); 
	}

	return 0; 
}
