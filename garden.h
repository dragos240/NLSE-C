#ifndef GARDEN_H
#define GARDEN_H
typedef struct garden_s{
	unsigned char* data;
	unsigned char* town_bytes;

	unsigned char* town_name;
	unsigned int town_hall_color;
	unsigned int train_station_color;
	unsigned int grass_type;
	unsigned int native_fruit;
	unsigned int seconds_played;
	unsigned short play_days;
} garden_t;

typedef struct player_s{
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
} player_t;

garden_t load_data(FILE *gardenfd);
int save_data(garden_t garden);
player_t get_player(char* dataarg);
int save_player(player_t player);
#endif
