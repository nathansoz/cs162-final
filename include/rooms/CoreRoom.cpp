//
// Created by nathan on 3/16/15.
//

#include <iostream>
#include "CoreRoom.h"

CoreRoom::CoreRoom(std::string name, std::string enterText, int coreRoomNumber, Room *north, Room *east, Room *south, Room *west)
{
    this->roomName = name;
    this->onEnterText = enterText;
    this->canInvestigate = true;
    this->coreRoomNumber = coreRoomNumber;

    this->north = north;
    this->east = east;
    this->south = south;
    this->west = west;
}

void CoreRoom::Investigate(Player & player)
{
    if(player.GetKeyObtained(coreRoomNumber))
    {
        std::cout << "This shard of the warp core has been shut down. Your data scanner has been given the verification code." << std::endl;
        player.SetCoreVerificationObtained(coreRoomNumber);
        this->SetCoreShutdown();
    }
    else
    {
        std::cout << "You search through your pockets but cannot find a matching key. Perhaps it can be found in another room." << std::endl;
    }
}

void CoreRoom::SetCoreShutdown()
{
    this->onEnterText = "The room is dark and silent. There is nothing to do here.";
    this->canInvestigate = false;
}