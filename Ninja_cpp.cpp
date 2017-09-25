
#include "Ninja.h"
#include <iostream>
#include <vector>
#include "Player.h"
#include <string>



Ninja::Ninja()
{

    bank_roll = 500;
    bet1 = 25;
    BJ = false;
    split_amt = 0;
}

double Ninja::getBet(int h_n)
{
    switch(h_n)
    {
    case 1:
        return bet1;
    case 2:
        return bet2;
    case 3:
        return bet3;
    case 4:
        return bet4;


    }

}

int Ninja::getHV(int x)
{
    switch(x)
    {
    case 1:
        return h1;
    case 2:
        return h2;
    case 3:
        return h3;
    case 4:
        return h4;
    }
}

void Ninja::payOff(double po, int hand_num)
{
    if(po==0)
    {
        switch(hand_num)
        {
        case 1:
            bank_roll = bet1 + bank_roll;
            break;
        case 2:
            bank_roll = bet2 + bank_roll;
            break;
        case 3:
            bank_roll = bet3 + bank_roll;
            break;
        case 4:
            bank_roll = bet4 + bank_roll;
            break;
        }
    }
    else
    {

        bank_roll = bet1 * 1.5 + bank_roll;
    }

}

void Ninja::loss(int hand_num)
{
    switch(hand_num)
    {
    case 1:
        bank_roll = bank_roll - bet1;
        break;
    case 2:
        bank_roll = bank_roll - bet2;
        break;
    case 3:
        bank_roll = bank_roll - bet3;
        break;
    case 4:
        bank_roll = bank_roll - bet4;
        break;

    }


}

void Ninja::getHand()
{
    switch(split_amt)
    {
    case 0:

        for(unsigned int a=0; a<hand1.size(); a++)
        {
            hand1[a].printCard();
        }
        std::cout <<  std::endl;
        break;


    case 1:
        for(unsigned int a=0; a<hand1.size(); a++)
        {
            hand1[a].printCard();
        }
        std::cout <<  std::endl;
        for(unsigned int a=0; a<hand2.size(); a++)
        {
            hand2[a].printCard();
        }
        std::cout << std::endl;
        break;


    case 2:
        for(unsigned int a=0; a<hand1.size(); a++)
        {
            hand1[a].printCard();
        }
        std::cout <<  std::endl;
        for(unsigned int a=0; a<hand2.size(); a++)
        {
            hand2[a].printCard();
        }
        std::cout << std::endl;
        for(unsigned int a=0; a<hand3.size(); a++)
        {
            hand3[a].printCard();
        }
        std::cout << std::endl;
        break;


    case 3:
        for(unsigned int a=0; a<hand1.size(); a++)
        {
            hand1[a].printCard();
        }
        std::cout <<  std::endl;
        for(unsigned int a=0; a<hand2.size(); a++)
        {
            hand2[a].printCard();
        }
        std::cout << std::endl;
        for(unsigned int a=0; a<hand3.size(); a++)
        {
            hand3[a].printCard();
        }
        std::cout << std::endl;
        for(unsigned int a=0; a<hand4.size(); a++)
        {
            hand4[a].printCard();
        }
        std::cout << std::endl;
        break;
    }
}

bool Ninja::splitAble(int t)
{
    switch(t)
    {
    case 1:
        if(hand1[0].getVal() == hand1[1].getVal() && hand1.size() == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    case 2:
        if(hand2[0].getVal() == hand2[1].getVal() && hand2.size() == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    case 3:
        if(hand3[0].getVal() == hand3[1].getVal() && hand3.size() == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    default:
        return false;
    }


}

int Ninja::getHandSize(int s)
{
    switch(s)
    {
    case 1:
        return hand1.size();
    case 2:
        return hand2.size();
    case 3:
        return hand3.size();
    case 4:
        return hand4.size();

    }
}
void Ninja::setHandValue(int i)
{
    int value=0;
    soft = false;
    BJ = false;

    switch(i)
    {
    case 1:
    {

        if(hand1.size()==2 && (hand1[0].getVal() + hand1[1].getVal() == 21))
        {
            BJ = true;
            h1=21;
        }
        else
        {
            for(unsigned int s=0; s<hand1.size(); s++)
            {
                if(hand1[s].getVal() == 11)
                {
                    if(value < 11)
                    {
                        soft = true;
                        value = value + hand1[s].getVal();
                    }
                    else
                    {
                        if(value > 10)
                        {
                            value = value + hand1[s].getAltVal();
                        }
                    }
                }
                else
                {
                    value = value + hand1[s].getVal();
                }


                if(value > 21 && soft == false)
                {
                    //std::cout << "\n bust! " << value << std::endl;
                    h1 = value;
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
            h1 = value;
        }

    }

    case 2:
    {
        for(unsigned int s=0; s<hand2.size(); s++)
        {
            if(hand2[s].getVal() == 11)
            {
                if(value < 11)
                {
                    soft = true;
                    value = value + hand2[s].getVal();
                }
                else
                {
                    if(value > 10)
                    {
                        value = value + hand2[s].getAltVal();
                    }
                }
            }
            else
            {
                value = value + hand2[s].getVal();
            }


            if(value > 21 && soft == false)
            {
                //std::cout << "\n bust! " << value << std::endl;
                h2 = value;
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
        h2 = value;

    }

    case 3:
    {
        for(unsigned int s=0; s<hand3.size(); s++)
        {
            if(hand3[s].getVal() == 11)
            {
                if(value < 11)
                {
                    soft = true;
                    value = value + hand3[s].getVal();
                }
                else
                {
                    if(value > 10)
                    {
                        value = value + hand3[s].getAltVal();
                    }
                }
            }
            else
            {
                value = value + hand3[s].getVal();
            }


            if(value > 21 && soft == false)
            {
                //std::cout << "\n bust! " << value << std::endl;
                h3 = value;
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
        h3 = value;

    }

    case 4:
    {
        for(unsigned int s=0; s<hand4.size(); s++)
        {
            if(hand4[s].getVal() == 11)
            {
                if(value < 11)
                {
                    soft = true;
                    value = value + hand4[s].getVal();
                }
                else
                {
                    if(value > 10)
                    {
                        value = value + hand4[s].getAltVal();
                    }
                }
            }
            else
            {
                value = value + hand4[s].getVal();
            }


            if(value > 21 && soft == false)
            {
                //std::cout << "\n bust! " << value << std::endl;
                h4 = value;
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
        h4 = value;

    }
    }
}

void Ninja::takeCard(const Card c_card, int h_num)
{

    switch(h_num)
    {
    case 1:
        hand1.push_back(c_card);
        break;
    case 2:
        hand2.push_back(c_card);
        break;
    case 3:
        hand3.push_back(c_card);
        break;
    case 4:
        hand4.push_back(c_card);
        break;
    }

}

void Ninja::clearHands()
{
    hand1.clear();
    hand2.clear();
    hand3.clear();
    hand4.clear();
    bet1 = 25;
    bet2 = 0;
    bet3 = 0;
    bet4 = 0;
    split_amt=0;

}

void Ninja::dble(int h)
{
    switch(h)
    {
    case 1:
        bet1 = bet1*2;
        break;
    case 2:
        bet2 = bet2*2;
        break;
    case 3:
        bet3 = bet3*2;
        break;
    case 4:
        bet4 = bet4*2;
        break;

    }
}
void Ninja::playHand() {}

int Ninja::getSplitAmt()
{
    return 1 + split_amt;
}

void Ninja::split(int h)
{
    split_amt++;

    switch(h)
    {

    case 1:
        switch(split_amt)
        {
        case 1:
            hand2.push_back(hand1[1]);
            bet2= bet1;
            hand1.pop_back();
            break;

        case 2:
            hand3.push_back(hand1[1]);
            bet3= bet1;
            hand1.pop_back();
            break;

        case 3:
            hand4.push_back(hand1[1]);
            bet4= bet1;
            hand1.pop_back();
            break;

        }
        break;
    case 2:
        switch(split_amt)
        {
        case 2:
            hand3.push_back(hand2[1]);
            bet3= bet2;
            hand2.pop_back();
            break;

        case 3:
            hand4.push_back(hand2[1]);
            bet4= bet2;
            hand2.pop_back();
            break;
        }
        break;
    case 3:
        switch(split_amt)
        {

        case 3:
            hand4.push_back(hand2[1]);
            bet4= bet2;
            hand2.pop_back();
            break;
        }
        break;
    }

}

bool Ninja::dbleAble(int h)
{
    switch(h)
    {
    case 1:
        if(hand1.size() == 2 && (h1== 11 || h1==10 || h1==9))
        {
            return true;
        }
        else
        {
            return false;
        }
    case 2:
        if(hand2.size() == 2 && (h2== 11 || h2==10 || h2==9))
        {
            return true;
        }
        else
        {
            return false;
        }
    case 3:
        if(hand3.size() == 2 && (h3== 11 || h3==10 || h3==9))
        {
            return true;
        }
        else
        {
            return false;
        }
    case 4:
        if(hand4.size() == 2 && (h4== 11 || h4==10 || h4==9))
        {
            return true;
        }
        else
        {
            return false;
        }
    default:
        return false;
    }
}
Ninja::~Ninja() {}
