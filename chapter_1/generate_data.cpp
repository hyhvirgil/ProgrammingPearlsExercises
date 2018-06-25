#include "apue.h"
#include <stdio.h> 
#include <fcntl.h> 
#include <vector> 
#include <algorithm> 

int 
main(void) 
{
	const int MAX_BIT = 8; 
	const int MAX_NUM = 10000000; 
	const int GENERATE_NUM = 8000000; 
	int fd; 
	char buffer[MAX_BIT] = {'\0'}; 

	if ((fd = open("data.txt", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0) {
		err_sys("open_error"); 	
	}

	std::vector<int> vec; 
	vec.reserve(MAX_NUM); 
	for (int i = 0; i < MAX_NUM; ++i) {
		vec.push_back(i); 
	}
	std::random_shuffle(vec.begin(), vec.end()); 

	vec.erase(vec.begin() + GENERATE_NUM, vec.end()); 

	for (int i = 0; i < (int)vec.size(); ++i) {
		sprintf(buffer, "%7d\n", vec[i]); 
		if (0 > write(fd, buffer, MAX_BIT)) {
			err_sys("write_error"); 
		}
	}

	close(fd); 
	
    return 0; 
}; 
