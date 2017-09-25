
#include "Dealer.h"
#include <iostream>
#include <vector>
#include "Player.h"



Dealer::Dealer()
{
    BJ=false;
    bank_roll = 100000;
}


int Dealer::getHV(int x)
{
    return h;

}

void Dealer::getHand()
{
    for(unsigned int a = 0; a<hand.size(); a++)
    {
        hand[a].printCard();
    }
    std::cout << std::endl;

}

void Dealer::setHandValue(int i)
{
    int value=0;
    soft = false;
    BJ = false;
    if(hand.size()==2 && (hand[0].getVal() + hand[1].getVal() == 21))
    {
        BJ = true;
        h=21;
    }
    else
    {
        for(unsigned int s=0; s<hand.size(); s++)
        {
            if(hand[s].getVal() == 11)
            {
                if(value < 11)
                {
                    soft = true;
                    value = value + hand[s].getVal();
                }
                else
                {
                    if(value > 10)
                    {
                        value = value + hand[s].getAltVal();
                    }
                }
            }
            else
            {
                value = value + hand[s].getVal();
            }


            if(value > 21 && soft == false)
            {
                //std::cout << "\n bust! " << value << std::endl;
                h = value;
            }
            else
            {
                if(value > 21 && soft == true)
                {
                    soft = false;
                    value = value - 10;
                }
            }
        }
        h = value;
    }

}

void Dealer::payOff(double po, int hand_num)
{
    bank_roll = bank_roll - po;

}

void Dealer::takeCard(const Card c_card, int h_num)
{
    if(h_num != 1)
    {
        std::cout << "Dealer cannot have more than 1 hand" << std::endl;
    }
    else
    {
        hand.push_back(c_card);
    }
}

int Dealer::topCard()
{
    return hand[0].getVal();
}
void Dealer::playHand() {}

void Dealer::clearHands()
{
    hand.clear();

}

Dealer::~Dealer() {}
