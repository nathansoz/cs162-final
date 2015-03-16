//
// Created by nathan on 3/16/15.
//

#ifndef _CS162_FINAL_BATTLEROOM_H_
#define _CS162_FINAL_BATTLEROOM_H_

#include "Room.h"
#include "../creatures/Character.h"

class BattleRoom : public Room
{
private:
    Character* creature;

    Character* SelectCreature();

public:
    BattleRoom();
    ~BattleRoom();

};


#endif //_CS162_FINAL_BATTLEROOM_H_
