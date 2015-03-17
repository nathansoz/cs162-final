//
// Created by nathan on 3/16/15.
//

#ifndef _CS162_FINAL_WORLD_H_
#define _CS162_FINAL_WORLD_H_

#include "../rooms/Room.h"
#include <vector>

class World
{
private:
    std::vector<Room*> rooms;
    Room* currentRoom;
    Room* entryPoint;

public:
    World();
    ~World();

    void AddRoom(Room*);
    Room* GetCurrentRoom();
    Room* GetStart();
    Room* SetCurrentRoom(Room*);
    Room* SetStart(Room*);

};


#endif //_CS162_FINAL_WORLD_H_
