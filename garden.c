#include <stdio.h>
#include <stdint.h>
#include "garden.h"

garden_t load_data(FILE *gardenfd){
	char* data;
	char* town_bytes;

	char* town_name;
	int town_hall_color;
	int train_station_color;
	int grass_type;
	int native_fruit;
	uint32_t seconds_played;
	uint16_t play_days;

	//data
	fseek(gardenfd, SEEK_END, 0);
	fread(data, 1, ftell(gardenfd), gardenfd);
	//town_bytes
	fread(town_bytes, 0x14, 0x5C7B8, gardenfd);
	//town_name
	fread(town_name, 0x12, 0x5C7BA, gardenfd);
	//town_hall_color
	fread(&town_hall_color, 1, 0x5C7B8, gardenfd);
	town_hall_color = town_hall_color & 3;
	//train_station_color
	fread(&train_station_color, 1, 0x5C7B9, gardenfd);
	train_station_color = train_station_color & 3;
	//grass_type
	fread(&grass_type, 1, 0x4DA81, gardenfd);
	//native_fruit
	fread(&native_fruit, 1, 0x5C836, gardenfd);
	//seconds_played
	seconds_played = (uint32_t)data[0x5C7B0] << 24 |
					 (uint32_t)data[0x5C7B0 + 1] << 16 |
					 (uint32_t)data[0x5C7B0 + 2] << 8 |
					 (uint32_t)data[0x5C7B0 + 3];
	//play_days
	play_days = (uint16_t)data[0x5C83A] << 24 |
				(uint16_t)data[0x5C83A + 1] << 16 |
				(uint16_t)data[0x5C83A + 2] << 8 |
				(uint16_t)data[0x5C83A + 3];

	garden_t garden = {data, town_bytes, town_name, town_hall_color,
					   grass_type, native_fruit, seconds_played, play_days};
	return garden;
}
