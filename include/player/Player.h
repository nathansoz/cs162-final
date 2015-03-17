//
// Created by nathan on 3/16/15.
//

#ifndef _CS162_FINAL_PLAYER_H_
#define _CS162_FINAL_PLAYER_H_


class Player
{
private:

    bool key1Obtained;
    bool key2Obtained;
    bool key3Obtained;

    bool core1Verification;
    bool core2Verification;
    bool core3Verification;

public:
    Player();
    ~Player();
    void SetKeyObtained(int);
    bool GetKeyObtained(int);

    void SetCoreVerificationObtained(int);
    bool GetCoreVerificationObtained(int);

};


#endif //_CS162_FINAL_PLAYER_H_
