//
// Created by nathan on 3/16/15.
//

#ifndef _CS162_FINAL_STANDARDROOM_H_
#define _CS162_FINAL_STANDARDROOM_H_

#include "Room.h"

class StandardRoom : public Room
{

private:

public:

    StandardRoom(std::string name, std::string enterText, Room* north, Room* east, Room* south, Room* west);
    ~StandardRoom();


};


#endif //_CS162_FINAL_STANDARDROOM_H_
