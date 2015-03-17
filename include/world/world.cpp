//
// Created by nathan on 3/16/15.
//

#include "world.h"

World::World()
{
}
World::~World()
{
    int numRooms = rooms.size();

    for(int i = 0; i < numRooms; i++)
    {
        Room* tmpRoom = this->rooms.back();
        this->rooms.pop_back();
        delete tmpRoom;
    }
}

void World::AddRoom(Room* room)
{
    this->rooms.push_back(room);
}

Room* World::GetCurrentRoom()
{
    return this->currentRoom;
}

Room* World::GetStart()
{
    return this->entryPoint;
}

Room* World::SetStart(Room* start)
{
    this->entryPoint = start;
}

Room* World::SetCurrentRoom(Room* current)
{
    this->currentRoom = current;
}

