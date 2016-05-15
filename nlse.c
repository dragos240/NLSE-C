#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "garden.h"
#include "nlse.h"

extern void printchars(char* start, char* str, int len);
extern garden_t load_data(FILE *gardenfd); 

int main(int argc, char* argv[]){
	int lg;
	FILE *fd;
	garden_t garden;

	if(argc < 2 || strstr("garden.dat", argv[1]) == NULL){
		printf("%d %s\n", argc, argv[1]);
		printf("ERROR: Please specify a garden.dat file.\n");
		return 1;
	}

	fd = fopen(argv[1], "rb");
	if(fd == NULL){
		printf("ERROR: Could not open garden.dat for reading!\n");
		return 1;
	}

	garden = load_data(fd);
	printf("Garden.dat file loaded!\n");

	printchars("Town name: ", garden.town_name, 0x12);
	printf("Seconds played: %d\n", garden.seconds_played);
	printf("Play days: %d\n", garden.play_days);

	fclose(fd);
	
	return 0;
}
