#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "helpers.h"
#include "garden.h"

extern unsigned short toUInt16(unsigned char* data, int location);
extern unsigned int toUInt32(unsigned char* data, int location);



garden_t load_data(FILE *gardenfd){
	int data_len;

	unsigned char* data;
	unsigned char* town_bytes;

	unsigned char* town_name;
	unsigned int town_hall_color;
	unsigned int train_station_color;
	unsigned int grass_type;
	unsigned int native_fruit;
	unsigned int seconds_played;
	unsigned short play_days;

	//data
	fseek(gardenfd, 0L, SEEK_END); //size
	data_len = ftell(gardenfd);
	fseek(gardenfd, 0L, SEEK_SET);
	data = (char*)malloc(data_len);
	fread(data, 1, data_len, gardenfd);
	//town_bytes
	town_bytes = (char*)malloc(0x14);
	fseek(gardenfd, 0x5C7B8, SEEK_SET);
	fread(town_bytes, 1, 0x14, gardenfd);
	//town_name
	town_name = (char*)malloc(0x12);
	fseek(gardenfd, 0x5C7BA, SEEK_SET);
	fread(town_name, 1, 0x12, gardenfd);
	//town_hall_color
	fseek(gardenfd, 0x5C7B8, SEEK_SET);
	fread(&town_hall_color, 1, 1, gardenfd);
	town_hall_color = town_hall_color & 3;
	//train_station_color
	fseek(gardenfd, 0x5C7B9, SEEK_SET);
	fread(&train_station_color, 1, 1, gardenfd);
	train_station_color = train_station_color & 3;
	//grass_type
	fseek(gardenfd, 0x4DA81, SEEK_SET);
	fread(&grass_type, 1, 1, gardenfd);
	//native_fruit
	fseek(gardenfd, 0x5C836, SEEK_SET);
	fread(&native_fruit, 1, 1, gardenfd);
	//seconds_played
	seconds_played = toUInt32(data, 0x5C7B0);
	//play_days
	play_days = toUInt16(data, 0x5C83A);

	garden_t garden = {data, town_bytes, town_name, town_hall_color,
			train_station_color, grass_type, native_fruit, seconds_played, play_days};
	return garden;
}

int save_data(garden_t garden){
	unsigned char* data;
	unsigned char* town_bytes;

	unsigned char* town_name;
	unsigned int town_hall_color;
	unsigned int train_station_color;
	unsigned int grass_type;
	unsigned int native_fruit;
	unsigned int seconds_played;
	unsigned short play_days;

	data = garden.data;
	town_bytes = garden.town_bytes;
	town_name = garden.town_name;
	town_hall_color = garden.town_hall_color;
	train_station_color = garden.train_station_color;
	grass_type = garden.grass_type;
	native_fruit = garden.native_fruit;
	seconds_played = garden.seconds_played;
	play_days = garden.play_days;

	return 0;
}

player_t get_player(char* dataarg){
	unsigned char* data;
	unsigned char* player_bytes;

	unsigned int u32;
	char hair, hair_color, face,
		 eye_color, tan, u9;

	char* name;
	int gender;
	char* home_town;

	char* badges;
	char** pockets;
	char** island_box;
	char** dressers;

	data = dataarg;
}

int save_player(player_t player){

}

