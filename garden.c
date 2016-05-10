#include <stdio.h>
#include "garden.h"

// returns 0 on success, 1 on failure
garden_t load_data(FILE gardenfd){
	char* data;
	char* town_bytes;

	char* town_name;
	int town_hall_color;
	int grass_type;
	int native_fruit;
	unsigned int seconds_played;
	unsigned short play_days;



	garden_t garden = {data, town_bytes, town_name, town_hall_color,
						grass_type, native_fruit, seconds_played, play_days};
	return garden;
}
