#include "stdafx.h"

#include "Equipable.h"

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