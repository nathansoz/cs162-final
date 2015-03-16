//
// Created by nathan on 3/14/15.
//

#ifndef _CS162_FINAL_ROOM_H_
#define _CS162_FINAL_ROOM_H_

enum Direction { NORTH, EAST, SOUTH, WEST };

class Room {

private:
    Room* north;
    Room* east;
    Room* south;
    Room* west;

public:
    Room();
    ~Room();

    virtual Room* GetRoomTo(Direction);
};


#endif //_CS162_FINAL_ROOM_H_
