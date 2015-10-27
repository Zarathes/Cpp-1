#include "Stairs.h"

class StairsDown : public Stairs {
public:
	void setEntry(Room entry);
	void setOut(Room out);
private:
	Room entry;
	Room out;
};