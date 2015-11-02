#include "stdafx.h"
#include "Consumable.h"

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