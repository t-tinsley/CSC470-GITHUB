
#ifndef NINJA_H
#define NINJA_H
#include <vector>
#include "Card.h"
#include "Player.h"
#include <string>



class Ninja: public Player
{
public:
    Ninja();
    ~Ninja();

    int getHV(int x);
    void getHand();
    void setHandValue(int i);
    void playHand();
    void takeCard(const Card c_card, int h_num);
    void payOff(double po, int hand_num);
    bool soft;
    double getBet(int h_n);
    void loss(int hand_num);
    void clearHands();
    void split(int h);
    int getSplitAmt();
    bool splitAble(int t);
    void dble(int h);
    bool dbleAble(int h);
    int getHandSize(int s);




private:

    double bet1, bet2, bet3, bet4;
    int split_amt;
    int h1, h2, h3, h4;




    std::vector<Card> hand1;
    std::vector<Card> hand2;
    std::vector<Card> hand3;
    std::vector<Card> hand4;
};

#endif // NINJA_H
