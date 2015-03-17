//
// Created by nathan on 3/14/15.
//

#ifndef _CS162_FINAL_ROOM_H_
#define _CS162_FINAL_ROOM_H_

#include <string>
#include "../player/Player.h"

enum Direction { NORTH, EAST, SOUTH, WEST };

class Room {

protected:
    Room* north;
    Room* east;
    Room* south;
    Room* west;

    std::string roomName;
    std::string onEnterText;
    bool canInvestigate;

public:
    Room();
    virtual ~Room() = 0;

    virtual Room* GetRoomTo(Direction);
    virtual std::string GetEntryText();

    virtual void SetNorthRoom(Room*);
    virtual void SetEastRoom(Room*);
    virtual void SetSouthRoom(Room*);
    virtual void SetWestRoom(Room*);

    virtual void Investigate(Player&);

    virtual bool GetInvestigatable();

};


#endif //_CS162_FINAL_ROOM_H_
