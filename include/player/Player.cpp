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

    core1Verification = false;
    core2Verification = false;
    core3Verification = false;

    won = false;

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

bool Player::GetKeyObtained(int key)
{
    switch(key)
    {
        case 1:
            return key1Obtained;
        case 2:
            return key2Obtained;
        case 3:
            return key3Obtained;
        default:
            return false;
    }

}

void Player::SetCoreVerificationObtained(int core)
{
    switch(core)
    {
        case 1:
            core1Verification = true;
            break;
        case 2:
            core2Verification = true;
            break;
        case 3:
            core3Verification = true;
            break;
        default:
            exit(-1);
    }
}

bool Player::GetCoreVerificationObtained(int core)
{
    switch(core)
    {
        case 1:
            return core1Verification;
        case 2:
            return core2Verification;
        case 3:
            return core3Verification;
        default:
            return false;
    }
}

void Player::SetPlayerWon()
{
    won = true;
}

bool Player::GetPlayerWon()
{
    return won;
}