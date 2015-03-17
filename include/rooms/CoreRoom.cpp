//
// Created by nathan on 3/16/15.
//

#include "CoreRoom.h"

CoreRoom::CoreRoom(std::string name, std::string enterText, Room *north, Room *east, Room *south, Room *west)
{
    this->roomName = name;
    this->onEnterText = enterText;
    this->canInvestigate = false;

    this->north = north;
    this->east = east;
    this->south = south;
    this->west = west;
}