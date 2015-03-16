//
// Created by nathan on 3/16/15.
//
#include "Room.h"
#include "BattleRoom.h"
#include "../creatures/Barbarian.h"
#include "../creatures/BlueMen.h"
#include "../creatures/Goblin.h"
#include "../creatures/ReptilePeople.h"
#include "../creatures/Shadow.h"

BattleRoom::BattleRoom()
{
    creature = SelectCreature();
}

BattleRoom::~BattleRoom()
{
    delete creature;
}

Character* BattleRoom::SelectCreature()
{
    int characterNumber = (rand() % 5) + 1;

    switch(characterNumber)
    {
        case 1:
            return new Barbarian("Barbarian");
        case 2:
            return new BlueMen("Blue Man");
        case 3:
            return new Goblin("Goblin");
        case 4:
            return new ReptilePeople("Reptile Person");
        case 5:
            return new Shadow("Shadow");
        default:
            exit(-1);
    }
}