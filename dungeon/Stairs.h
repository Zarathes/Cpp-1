#include "room.h"

class Stairs : public Room{
public:
	void setEntry(Room entry);
	void setOut(Room out);
private:
	Room entry;
	Room out;
};