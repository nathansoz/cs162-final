//
// Created by nathan on 3/16/15.
//

#ifndef _CS162_FINAL_BATTLEROOM_H_
#define _CS162_FINAL_BATTLEROOM_H_

#include "Room.h"
#include "../creatures/Character.h"
#include "../world/world.h"
#include "../player/Player.h"

class BattleRoom : public Room
{
protected:
    Character* creature;
    bool creatureDefeated;
    bool keyPickedUp;

    int battleRoomNumber;

    Character* SelectCreature();

public:
    BattleRoom(std::string name, std::string enterText, int battleRoomNumber, Room* north, Room* east, Room* south, Room* west);
    ~BattleRoom();

    void Investigate(Player&);
    void Battle(Character* ally);
    void SetDefeated();
    void SetKeyPickedUp();

    bool GetInvestigatable();

};


#endif //_CS162_FINAL_BATTLEROOM_H_
