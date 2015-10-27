#include "room.h"

class Stairs : public Room{
public:
	virtual void setEntry(Room entry) = 0;
	virtual void setOut(Room out) = 0;
private:
	Room entry;
	Room out;
};