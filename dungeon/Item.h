#ifndef __item__
#define __item__

#include <iostream>

class Item{
public:
	void setName(std::string name);
	void setDescription(std::string descr);
	std::string getName();
	std::string getDescription();
	void use();
protected:
	std::string name;
	std::string description;
};

#endif