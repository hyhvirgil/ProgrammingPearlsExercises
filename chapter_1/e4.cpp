#include "apue.h"
#include <stdio.h> 
#include <fcntl.h> 
#include <algorithm> 

void random_shuffle(int* array, int max_num) 
{
	for (int i = 1; i < max_num; ++i) {
		// random_num rand()%i
		int random_num = i-1; 
		int temp = array[random_num]; 
		array[random_num] = array[i]; 
		array[i] = temp; 
	}
}

int 
main(void) 
{
	const int MAX_BIT = 8; 
	const int MAX_NUM = 10000000; 
	const int GENERATE_NUM = 8000000; 
	int fd; 
	char buffer[MAX_BIT] = {'\0'}; 
	int array[MAX_NUM]; 

	if ((fd = open("data.txt", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0) {
		err_sys("open_error"); 	
	}

	for (int i = 0; i < MAX_NUM; ++i) {
		array[i] = i;  
	}
	random_shuffle(array, MAX_NUM); 

	for (int i = 0; i < GENERATE_NUM; ++i) {
		sprintf(buffer, "%7d\n", array[i]); 
		if (0 > write(fd, buffer, MAX_BIT)) {
			err_sys("write_error"); 
		}
	}

	close(fd); 
	
    return 0; 
}; 
