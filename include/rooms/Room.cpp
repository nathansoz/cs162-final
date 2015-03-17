//
// Created by nathan on 3/14/15.
//

#include <stddef.h>
#include "Room.h"



Room::Room() {}
Room::~Room() {}

std::string Room::GetEntryText()
{
    return onEnterText;
}

Room* Room::GetRoomTo(Direction direction)
{
    switch(direction)
    {
        case NORTH:
            return this->north;
        case EAST:
            return this->east;
        case SOUTH:
            return this->south;
        case WEST:
            return this->west;
        default:
            return NULL;
    }
}

void Room::SetNorthRoom(Room * north)
{
    this->north = north;
}

void Room::SetEastRoom(Room * east)
{
    this->east = east;
}

void Room::SetSouthRoom(Room * south)
{
    this ->south = south;
}

void Room::SetWestRoom(Room * west)
{
    this->west = west;
}

bool Room::GetInvestigatable()
{
    return canInvestigate;
}

void Room::Investigate(Player& player)
{
}