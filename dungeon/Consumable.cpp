#include "stdafx.h"
#include "Consumable.h"

Consumable::Consumable(std::string name, int points)
: Item(name, points)
{
}

void Consumable::setName(std::string nameNew){
	name = nameNew;
}

void Consumable::setDescription(std::string descr){
	description = descr;
}

std::string Consumable::getName(){
	return name;
}

std::string Consumable::getDescription(){
	return description;
}