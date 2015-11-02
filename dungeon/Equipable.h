#include "Item.h"
class Equipable: public Item{
public:
	void setName(std::string nameNew);
	void setDescription(std::string descr);
	std::string getName();
	std::string getDescription();
	void use();
private:
	std::string name;
	std::string description;
};