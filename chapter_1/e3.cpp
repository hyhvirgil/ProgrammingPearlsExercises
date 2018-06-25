#include "apue.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> 
#include <sys/time.h> 

void set_bit(int num, char* bit_array, int max_size) 
{
	if (0 > num || max_size <= num) 
		return; 

	int index = num / 8; 
	int bit = num % 8;  
	char mark = 1; 
	mark = mark << bit; 
	mark = ~mark; 
	bit_array[index] = bit_array[index] | mark; 
}

int get_bit(int num, char* bit_array, int max_size) 
{
	if (0 > num || max_size <= num) 
		return 0; 

	int index = num / 8; 
	int bit = num % 8; 
	char mark = bit_array[index] >> bit; 
	return mark & 1; 
}

int main() 
{
	const int MAX_BIT = 8; 
	const int MAX_NUM = 10000000; 
	const int ARRAY_SIZE = MAX_NUM / 8; 
	int fd; 
	int write_fd; 
	int num = 0; 
	char buffer[MAX_BIT]; 
	char bit_array[ARRAY_SIZE]; 
	struct timeval begin_tv, end_tv;  

	gettimeofday(&begin_tv, NULL); 

	if ((fd = open("data.txt", O_RDONLY, FILE_MODE)) < 0) {
	       err_sys("open_error");
	}
	if ((write_fd = open("result.txt", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0) {
	       err_sys("open_write_file_error");
	}

	while (0 < read(fd, buffer, MAX_BIT)) {
		num = atoi(buffer); 
		set_bit(num, bit_array, MAX_NUM); 
	}

	for (int i = 0; i < MAX_NUM; ++i) {
		if (0 < get_bit(i, bit_array, MAX_NUM)) {
			sprintf(buffer, "%7d\n", i); 
			if (0 > write(write_fd, buffer, MAX_BIT)) {
				err_sys("write_result_file_error"); 
			}
		}
	}

	close(fd); 
	close(write_fd); 

	gettimeofday(&end_tv, NULL); 
	unsigned int interval = (end_tv.tv_sec*1000 + end_tv.tv_usec/1000) - (begin_tv.tv_sec*1000 + begin_tv.tv_usec/1000); 
	printf("run time(millisecond) = %u\n", interval); 

    return 0; 
} 
