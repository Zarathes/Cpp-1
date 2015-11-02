#include "Stairs.h"

class StairsUp : public Stairs{
public:
	void setEntry(Room entry);
	void setOut(Room out);
private:
	Room entry;
	Room out;
};