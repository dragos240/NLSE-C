#include <stdio.h>
#include "helpers.h"

void printchars(char* start, char* str, int len){
	int i;
	printf("%s", start);
	for(i = 0; i < len; i++){
		putchar(str[i]);
	}
	putchar('\n');
}

unsigned short toUInt16(unsigned char* data, int location){
	unsigned short result;

	result = (data[location + 1] << 8) |
			 (data[location + 0] << 0);

	return result;

}

unsigned int toUInt32(unsigned char* data, int location){
	unsigned int result;

	result = (data[location + 3] << 24) |
			 (data[location + 2] << 16) |
			 (data[location + 1] << 8) |
			 (data[location + 0] << 0);

	return result;
}
