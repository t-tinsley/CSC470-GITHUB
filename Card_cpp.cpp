
#include <iostream>
#include <string>
#include <sstream>
#include "Card.h"


Card::Card(int dv, char ds, int dav)
{
    val= dv;
    suit = ds;
    alt_val = dav;
}

Card::Card() {}

void Card::setVal(int v)
{
    val = v;
}
void Card::setAltVal(int av)
{
    alt_val = av;
}
int Card::getVal()
{
    return val;
}
int Card::getAltVal()
{
    return alt_val;
}
void Card::setSuit(char s)
{
    suit=s;
}
void Card::printCard()
{
    switch(alt_val)
    {
    case 1:
        std::cout << "A" << suit << ", ";
        break;
    case 11:
        std::cout << "J" << suit << ", ";
        break;
    case 12:
        std::cout << "Q" << suit << ", ";
        break;
    case 13:
        std::cout << "K" << suit << ", ";
        break;
    default:
        std::cout << val << suit << ", ";
    }
}





Card::~Card() {}
