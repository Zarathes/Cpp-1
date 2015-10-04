#include<iostream>

class Item{
public:
	std::string getName();
	std::string getDescription();
	void use();
protected:
	std::string name;
	std::string description;
}