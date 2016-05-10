#ifndef NLSE_H
#define NLSE_H
typedef struct garden_s{
	char* data,
	char* town_bytes;

	char* town_name;
	int town_hall_color;
	int grass_type;
	int native_fruit;
	unsigned int seconds_played;
	unsigned short play_days;
} garden_t;

int load_garden(char *garden);

#endif