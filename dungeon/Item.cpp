#include "stdafx.h"
#include "Item.h"

void Item::setName(std::string name){
	Item::name = name;
}

void Item::setDescription(std::string descr){
	Item::description = descr;
}

std::string Item::getName(){
	return Item::name;
}

std::string Item::getDescription(){
	return Item::description;
}