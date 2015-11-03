#include "stdafx.h"

#include "Equipable.h"


Equipable::Equipable(std::string name, int points)
: Item(name, points)
{
}

void Equipable::setName(std::string nameNew){
	name = nameNew;
}

void Equipable::setDescription(std::string descr){
	description = descr;
}

std::string Equipable::getName(){
	return name;
}

std::string Equipable::getDescription(){
	return description;
}