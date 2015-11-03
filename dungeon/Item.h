#ifndef __item__
#define __item__

#include <iostream>

class Item{
public:
	Item(std::string name, int points);
	void setName(std::string nameNew);
	void setDescription(std::string descr);
	std::string getName();
	std::string getDescription();
	int use();
protected:
	int points;
	std::string name;
	std::string description;
};

#endif