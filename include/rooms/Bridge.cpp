//
// Created by nathan on 3/17/15.
//

#include "Bridge.h"
#include <iostream>
Bridge::Bridge(std::string name, std::string enterText, Room *north, Room *east, Room *south, Room *west)
{
    this->roomName = name;
    this->onEnterText = enterText;
    this->canInvestigate = true;

    this->north = north;
    this->east = east;
    this->south = south;
    this->west = west;
}

Bridge::~Bridge()
{

}

void Bridge::Investigate(Player & player)
{
    if(player.GetCoreVerificationObtained(1) && player.GetCoreVerificationObtained(2) &&
            player.GetCoreVerificationObtained(3))
    {
        std::cout << "The warp core shards have all been shut down and you pull the levers to avoid\n"
                        "the self-destruct sequence." << std::endl;
        player.SetPlayerWon();
    }
    else
    {
        std::cout << "You haven't shut down all of the warp core shards!" << std::endl;
    }
}