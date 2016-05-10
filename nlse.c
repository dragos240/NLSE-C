#include <stdio.h>
#include <string.h>
#include "garden.h"
#include "nlse.h"

int main(int argc, char* argv[]){
	int lg;
	FILE *fd;

	if(argc < 2 || strstr("garden.dat", argv[1]) == NULL){
		printf("%d %s\n", argc, argv[1]);
		printf("ERROR: Please specify a garden.dat file.\n");
		return 1;
	}

	fd = fopen(argv[1], "r");
	if(fd == NULL){
		printf("ERROR: Could not open garden.dat for reading!\n");
		return 1;
	}

	printf("Garden.dat file loaded!\n");

	fclose(fd);
	
	return 0;
}
