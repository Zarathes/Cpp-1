#include "room.h"
#include <iostream>
#include "ReadTextFile.h"
#include <vector>


class Generator{
public:
	Generator(int d, int w, int h);
	bool createDungeon();
	Room* getStartRoom();
	Room* getEndRoom();
	void showMap(int CurrentLevel);
private:
	std::vector<std::string> size;
	std::vector<std::string> roomType;
	std::vector<std::string> state;
	std::vector<std::string> furniture;
	std::vector<std::string> lightning;

	std::vector<std::string> enemies;
	std::vector<std::string> attackPointsEnemy;
	std::vector<std::string> lifePointsEnemy;

	std::vector<std::string> consumbableNames;
	std::vector<std::string> equipableNames;
	std::vector<std::string> attackPointsItem;

	int mapLevel;

	int depth;
	int width;
	int height;

	Room* startRoom;
	Room* endRoom;
	ReadTextFile read;
	
	std::vector< std::vector< std::vector<Room> > > dungeon;
	std::string createDescription();
	std::vector<Enemy*> createEnemies();
	std::vector<Enemy*> createEndEnemy();
	std::vector<Consumable*> createConsumableItems();
	std::vector<Equipable*> createEquipableItems();
	std::vector<Exits> createExit(int width, int height);
};