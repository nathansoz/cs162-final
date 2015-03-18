//
// Created by nathan on 3/17/15.
//

#ifndef _CS162_FINAL_BRIDGE_H_
#define _CS162_FINAL_BRIDGE_H_

#include "Room.h"

class Bridge : public Room
{
private:

public:
    Bridge(std::string name, std::string enterText, Room *north, Room *east, Room *south, Room *west);
    ~Bridge();
    void Investigate(Player&);
};


#endif //_CS162_FINAL_BRIDGE_H_
