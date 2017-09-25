
#ifndef DEALER_H
#define DEALER_H
#include "Player.h"
#include <vector>
#include "Card.h"


class Dealer: public Player
{
public:
    Dealer();
    ~Dealer();

    int getHV(int x);
    void getHand();
    void setHandValue(int i);
    void playHand();
    void takeCard(const Card c_card, int h_num);
    void payOff(double po, int hand_num);
    bool soft;
    int topCard();
    void clearHands();


private:
    std::vector<Card> hand;
    int h;


};

#endif // DEALER_H
