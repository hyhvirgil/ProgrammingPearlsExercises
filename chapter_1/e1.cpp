#include "apue.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> 
#include <vector> 
#include <sys/time.h> 
#include <algorithm> 

int main() 
{
	const int MAX_BIT = 8; 
	const int MAX_NUM = 10000000; 
	int fd; 
	int write_fd; 
	int num = 0; 
	struct timeval begin_tv, end_tv; 
	char buffer[MAX_BIT]; 
	std::vector<int> vec; 

	gettimeofday(&begin_tv, NULL); 

	if ((fd = open("data.txt", O_RDONLY, FILE_MODE)) < 0) {
	       err_sys("open_error");
	}
	if ((write_fd = open("result.txt", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0) {
	       err_sys("open_write_file_error");
	}

	vec.reserve(MAX_NUM); 
	while (0 < read(fd, buffer, MAX_BIT)) {
		num = atoi(buffer); 
		vec.push_back(num); 
	}

	std::sort(vec.begin(), vec.end()); 
	for (int i = 0; i < (int)vec.size(); ++i) {
		sprintf(buffer, "%7d\n", vec[i]); 
		if (0 > write(write_fd, buffer, MAX_BIT)) {
			err_sys("write_result_file_error"); 
		}
	}

	close(fd); 
	close(write_fd); 

	gettimeofday(&end_tv, NULL); 
	unsigned int interval = (end_tv.tv_sec*1000 + end_tv.tv_usec/1000) - (begin_tv.tv_sec*1000 + begin_tv.tv_usec/1000); 
	printf("run time(millisecond) = %u\n", interval); 

    return 0; 
} 
