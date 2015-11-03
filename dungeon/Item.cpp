#include "stdafx.h"
#include "Item.h"

Item::Item(std::string name, int points)
	: name(name), points(points)
{
}

void Item::setName(std::string nameNew){
	name = nameNew;
}

void Item::setDescription(std::string descr){
	Item::description = descr;
}

std::string Item::getName(){
	return name;
}

std::string Item::getDescription(){
	return Item::description;
}

int Item::use(){
	return points;
}