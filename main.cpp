#include <string>
#include <iostream>

#include "include/world/world.h"

#include "include/player/Player.h"

#include "include/rooms/BattleRoom.h"
#include "include/rooms/CoreRoom.h"
#include "include/rooms/StandardRoom.h"

#include "include/creatures/Barbarian.h"

World* PopulateWorld()
{
    World* gameWorld = new World;
    //TODO: SUB OUT WITH JSON LIBRARY AND READ FROM FILE

    //Room One Setup (Startpoint)
    std::string room1Name = "Start";
    std::string room1Text = "You wake up in a room, dazed and confused.\n"
                            "You hear the soft voice of the computer... 'Warp core meltdown imminent...'";
    Room* Room1 = new StandardRoom(room1Name, room1Text, NULL, NULL, NULL, NULL);
    gameWorld->AddRoom(Room1);
    gameWorld->SetStart(Room1);

    //Room Two Setup (Hallway 1)
    std::string room2Name = "Hallway 1";
    std::string room2Text = "There is a long hallway with a door to the east and the west.\n"
                            "You remember something abou the warp core... it can be shut down\n"
                            "via a sequence of three keys and a command at the bridge.\n"
                            "Perhaps these rooms are worth investigating... you hear a loud banging from the room to the west...";

    Room* Room2 = new StandardRoom(room2Name, room2Text, NULL, NULL, Room1, NULL);
    Room1->SetNorthRoom(Room2);
    gameWorld->AddRoom(Room2);

    //Room Three Setup (Hallway - West Room)
    std::string room3Name = "Battle Room 1";
    std::string room3Text = "You hear something lurking in the corner...";
    Room* Room3 = new BattleRoom(room3Name, room3Text, 1, NULL, Room2, NULL, NULL);
    Room2->SetWestRoom(Room3);
    gameWorld->AddRoom(Room3);

    //push the object back for consuption in gameloop
    return gameWorld;
}

void GameLoop(World* gameWorld)
{
    Player player;

    std::cout << "Welcome to the spaceship game!" << std::endl << std::endl;
    gameWorld->SetCurrentRoom(gameWorld->GetStart());
    bool exit = false;

    do
    {
        char command;


        std::cout << gameWorld->GetCurrentRoom()->GetEntryText() << std::endl;

        std::cout << "What would you like to do?" << std::endl << "You can... ";
        if(gameWorld->GetCurrentRoom()->GetRoomTo(NORTH))
            std::cout << " Move (n)orth, ";
        if(gameWorld->GetCurrentRoom()->GetRoomTo(EAST))
            std::cout << " Move (e)ast, ";
        if(gameWorld->GetCurrentRoom()->GetRoomTo(SOUTH))
            std::cout << " Move (s)outh, ";
        if(gameWorld->GetCurrentRoom()->GetRoomTo(WEST))
            std::cout << " Move (w)est, ";
        if(gameWorld->GetCurrentRoom()->GetInvestigatable())
            std::cout << " (i)nvestigate, ";

        std::cout << " e(x)it" << std::endl << std::endl;

        std::cout << "Please enter your command: ";
        command = std::getchar();
        std::cin.ignore(1000, '\n');

        switch(tolower(command))
        {
            case 'n':
            {
                Room *tmpRoom = gameWorld->GetCurrentRoom()->GetRoomTo(NORTH);
                if (tmpRoom == NULL)
                    std::cout << "You cannot go that way." << std::endl;
                else
                {
                    std::cout << "Moving one room to the north." << std::endl;
                    gameWorld->SetCurrentRoom(tmpRoom);
                }

                break;
            }
            case 'e':
            {
                Room *tmpRoom = gameWorld->GetCurrentRoom()->GetRoomTo(EAST);
                if (tmpRoom == NULL)
                    std::cout << "You cannot go that way." << std::endl;
                else
                {
                    std::cout << "Moving one room to the east." << std::endl;
                    gameWorld->SetCurrentRoom(tmpRoom);
                }

                break;
            }
            case 's':
            {
                Room *tmpRoom = gameWorld->GetCurrentRoom()->GetRoomTo(SOUTH);
                if (tmpRoom == NULL)
                    std::cout << "You cannot go that way." << std::endl;
                else
                {
                    std::cout << "Moving one room to the south." << std::endl;
                    gameWorld->SetCurrentRoom(tmpRoom);
                }

                break;
            }
            case 'w':
            {
                Room *tmpRoom = gameWorld->GetCurrentRoom()->GetRoomTo(WEST);
                if (tmpRoom == NULL)
                    std::cout << "You cannot go that way." << std::endl;
                else
                {
                    std::cout << "Moving one room to the west." << std::endl;
                    gameWorld->SetCurrentRoom(tmpRoom);
                }

                break;
            }
            case 'i':
            {
                gameWorld->GetCurrentRoom()->Investigate(player);
                break;
            }
            case 'x':
            {
                exit = true;
                break;
            }
            default:
            {
                std::cout << "Invalid command!" << std::endl;
            }
        }
    } while(!exit);

}

int main()
{
    srand(time(NULL));

    //Init
    World* gameWorld = PopulateWorld();

    GameLoop(gameWorld);

    return 0;
}