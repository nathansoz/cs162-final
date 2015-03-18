//
// Created by nathan on 3/16/15.
//

#ifndef _CS162_FINAL_WORLD_H_
#define _CS162_FINAL_WORLD_H_

#include "../rooms/Room.h"
#include <vector>

const int NUM_TURNS = 30;

class World
{
private:
    std::vector<Room*> rooms;
    Room* currentRoom;
    Room* entryPoint;
    int numTurns = NUM_TURNS;

public:
    World();
    ~World();

    void AddRoom(Room*);
    Room* GetCurrentRoom();
    Room* GetStart();
    Room* SetCurrentRoom(Room*);
    Room* SetStart(Room*);
    void TurnOver();
    int GetTurns();

};


#endif //_CS162_FINAL_WORLD_H_
