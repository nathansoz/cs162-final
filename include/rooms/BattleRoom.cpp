//
// Created by nathan on 3/16/15.
//
#include <iostream>

#include "Room.h"
#include "BattleRoom.h"
#include "../creatures/Barbarian.h"
#include "../creatures/BlueMen.h"
#include "../creatures/Goblin.h"
#include "../creatures/ReptilePeople.h"
#include "../creatures/Shadow.h"

BattleRoom::BattleRoom(std::string name, std::string enterText, int battleRoomNumber, Room* north, Room* east, Room* south, Room* west)
{
    this->roomName = name;
    this->onEnterText = enterText;
    this->canInvestigate = true;

    this->north = north;
    this->east = east;
    this->south = south;
    this->west = west;

    this->battleRoomNumber = battleRoomNumber;

    creature = SelectCreature();
    creatureDefeated = false;
    keyPickedUp = false;
}

BattleRoom::~BattleRoom()
{
    delete this->creature;
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

void BattleRoom::Investigate(Player& player)
{
    if(this->creatureDefeated)
    {
        player.SetKeyObtained(this->battleRoomNumber);
        SetKeyPickedUp();
        std::cout << "You have picked up a key! This key should work in the warp room directly across the hall." << std::endl;
        return;
    }

    std::cout << "There is a " << this->creature->GetName() << " in the room!" << std::endl;
    std::cout << "It moves toward you, but you have an ally!" << std::endl;
    std::cout << "Who is your ally?" << std::endl;

    char selection;
    int selectionInt;
    Character* ally;

    do
    {
        std::cout << "1) Barbarian" << std::endl;
        std::cout << "2) Blue Man" << std::endl;
        std::cout << "3) Goblin" << std::endl;
        std::cout << "4) Reptile Person" << std::endl;
        std::cout << "5) Shadow" << std::endl;
        std::cout << "choice: ";


        selection = getchar();

        if(std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        std::cin.ignore(1000, '\n');
        selectionInt = selection - '0';
    } while(selectionInt < 1 || selectionInt > 5);

    switch(selectionInt)
    {
        case 1:
            ally = new Barbarian("Barbarian");
            break;
        case 2:
            ally = new BlueMen("Blue Men");
            break;
        case 3:
            ally = new Goblin("Goblin");
            break;
        case 4:
            ally = new ReptilePeople("Reptile Person");
            break;
        case 5:
            ally = new Shadow("Shadow");
            break;
        default:
            exit(-1);
    }

    this->Battle(ally);


}

void BattleRoom::Battle(Character *ally)
{
    while (ally->IsAlive() && this->creature->IsAlive())
    {
        if(ally->IsAlive())
        {
            ally->Attack(this->creature);
        }

        if (this->creature->IsAlive())
        {
            this->creature->Attack(ally);
        }
    }

    if(ally->IsAlive())
    {
        std::cout << "Your ally is victorious!" << std::endl;
        this->SetDefeated();

    }
    else
    {
        std::cout << "Your ally has fallen. You retreat to the shadows of the room... " << std::endl;

    }
}

void BattleRoom::SetDefeated()
{
    this->onEnterText = "There is a defeated creature in the room. Perhaps you could investigate the corpse?";
    creatureDefeated = true;
}

void BattleRoom::SetKeyPickedUp()
{
    this->onEnterText = "There is nothing further in this room.";
    keyPickedUp = true;
}

bool BattleRoom::GetInvestigatable()
{
    if(!creatureDefeated || !keyPickedUp)
        return true;

    return false;

}