#include <string>
#include <iostream>

#include "include/world/world.h"

#include "include/player/Player.h"

#include "include/rooms/BattleRoom.h"
#include "include/rooms/CoreRoom.h"
#include "include/rooms/StandardRoom.h"
#include "include/rooms/Bridge.h"

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

    //Room Three Setup (Hallway1 - West Room)
    std::string room3Name = "Battle Room 1";
    std::string room3Text = "You hear something lurking in the corner...";
    Room* Room3 = new BattleRoom(room3Name, room3Text, 1, NULL, Room2, NULL, NULL);
    Room2->SetWestRoom(Room3);
    gameWorld->AddRoom(Room3);

    //Room Four Setup (Hallway 1 - East Room)
    std::string room4Name = "Core Room 1";
    std::string room4Text = "The warp core hums loudly... there is a slot for a key on the control panel...";
    Room* Room4 = new CoreRoom(room4Name, room4Text, 1, NULL, NULL, NULL, Room2);
    Room2->SetEastRoom(Room4);
    gameWorld->AddRoom(Room4);

    //Room Five Setup (Hallway 2)
    std::string room5Name = "Hallway 2";
    std::string room5Text = "You are in the middle of the long hallway. Again, you hear a loud banging to the west...";
    Room* Room5 = new StandardRoom(room5Name, room5Text, NULL, NULL, Room2, NULL);
    Room2->SetNorthRoom(Room5);
    gameWorld->AddRoom(Room5);

    //Room Six Setup (Hallway2 - West Room)
    std::string room6Name = "Battle Room 2";
    std::string room6Text = "You hear something lurking in the corner...";
    Room* Room6 = new BattleRoom(room6Name, room6Text, 2, NULL, Room5, NULL, NULL);
    Room5->SetWestRoom(Room6);
    gameWorld->AddRoom(Room6);

    //Room Seven Setup (Hallway2 - East Room)
    std::string room7Name = "Core Room 2";
    std::string room7Text = "The warp core hums loudly... there is a slot for a key on the control panel...";
    Room* Room7 = new CoreRoom(room7Name, room7Text, 2, NULL, NULL, NULL, Room5);
    Room5->SetEastRoom(Room7);
    gameWorld->AddRoom(Room7);

    //Room Eight Setup (Hallway 3)
    std::string room8Name = "Hallway 3";
    std::string room8Text = "You are at the end of the long hallway. The bridge is in front of you.\n"
                            "Again, you hear a loud banging to the west...";
    Room* Room8 = new StandardRoom(room8Name, room8Text, NULL, NULL, Room5, NULL);
    Room5->SetNorthRoom(Room8);
    gameWorld->AddRoom(Room8);

    //Room Nine Setup (Hallway2 - West Room)
    std::string room9Name = "Battle Room 2";
    std::string room9Text = "You hear something lurking in the corner...";
    Room* Room9 = new BattleRoom(room9Name, room9Text, 3, NULL, Room8, NULL, NULL);
    Room8->SetWestRoom(Room9);
    gameWorld->AddRoom(Room9);

    //Room Ten Setup (Hallway2 - East Room)
    std::string room10Name = "Core Room 2";
    std::string room10Text = "The warp core hums loudly... there is a slot for a key on the control panel...";
    Room* Room10 = new CoreRoom(room10Name, room10Text, 3, NULL, NULL, NULL, Room8);
    Room8->SetEastRoom(Room10);
    gameWorld->AddRoom(Room10);

    //Bridge
    std::string bridgeName = "Bridge";
    std::string bridgeText = "You reach the bridge. Red lights are flashing everywhere. The warp core switch is in the"
                                "center of the room.";
    Room* bridge = new Bridge(bridgeName, bridgeText, NULL, NULL, Room8, NULL);
    Room8->SetNorthRoom(bridge);
    gameWorld->AddRoom(bridge);


    //push the object back for consuption in gameloop
    return gameWorld;
}

void GameLoop(World* gameWorld)
{
    Player player;

    std::cout << "Welcome to the spaceship game!" << std::endl << std::endl;
    gameWorld->SetCurrentRoom(gameWorld->GetStart());

    do
    {

        char command;


        std::cout << gameWorld->GetCurrentRoom()->GetEntryText() << std::endl;
        std::cout << "You have " << gameWorld->GetTurns() << " clicks before core meltdown!" << std::endl;

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
                    gameWorld->TurnOver();
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
                    gameWorld->TurnOver();
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
                    gameWorld->TurnOver();
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
                    gameWorld->TurnOver();
                    gameWorld->SetCurrentRoom(tmpRoom);
                }

                break;
            }
            case 'i':
            {
                gameWorld->GetCurrentRoom()->Investigate(player);
                gameWorld->TurnOver();
                break;
            }
            case 'x':
            {
                std::cout << "Thank you for playing." << std::endl;
                delete gameWorld;
                exit(0);
            }
            default:
            {
                std::cout << "Invalid command!" << std::endl;
            }
        }
    } while(!player.GetPlayerWon() && gameWorld->GetTurns() > 0);

    if(player.GetPlayerWon())
    {
        std::cout << "You won!" << std::endl;
    }
    else
    {
        std::cout << "You are out of time... a rushing fireball comes your way. Darkness overtakes you." << std::endl;
    }

    delete gameWorld;

}

int main()
{
    srand(time(NULL));

    //Init
    World* gameWorld = PopulateWorld();

    GameLoop(gameWorld);

    return 0;
}