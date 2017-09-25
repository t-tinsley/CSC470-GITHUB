
#ifndef CARD_H
#define CARD_H


class Card
{
public:

    Card();
    Card(int dv, char ds, int dav);
    void setVal(int v);
    void setAltVal(int av);
    int getVal();
    int getAltVal();
    void setSuit(char s);
    void printCard();
    ~Card();

private:
    int val;
    int alt_val;
    char suit;

};

#endif // CARD_H
