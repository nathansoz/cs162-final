//
// Created by nathan on 3/16/15.
//

#ifndef _CS162_FINAL_COREROOM_H_
#define _CS162_FINAL_COREROOM_H_


#include "Room.h"

class CoreRoom : public Room
{
private:
    int coreRoomNumber;
    void SetCoreShutdown();
public:
    CoreRoom(std::string name, std::string enterText, int coreRoomNumber, Room* north, Room* east, Room* south, Room* west);
    void Investigate(Player&);

};


#endif //_CS162_FINAL_COREROOM_H_
