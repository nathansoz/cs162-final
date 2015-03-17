//
// Created by nathan on 3/16/15.
//

#include <stdlib.h>
#include "Player.h"

Player::Player()
{
    key1Obtained = false;
    key2Obtained = false;
    key3Obtained = false;
}

Player::~Player()
{
}

void Player::SetKeyObtained(int key)
{
    switch(key)
    {
        case 1:
            key1Obtained = true;
            break;
        case 2:
            key2Obtained = true;
            break;
        case 3:
            key3Obtained = true;
            break;
        default:
            exit(-1);
    }

}