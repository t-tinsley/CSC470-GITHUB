
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"


class Player
{
public:
    Player();
    ~Player();

    virtual void getHand() = 0;
    virtual void setHandValue(int i)=0;
    virtual void playHand()=0;
    void payOff(double po, int hand_num);
    virtual void takeCard(const Card c_card, int h_num)=0;
    double getBR();
    bool BJ;
    virtual void clearHands()=0;


protected:
    double bank_roll;
    bool split;




};

#endif
