#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
#include "Ninja.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <deque>
#include <string>


void shuffleDeck(Card thisDeck[], int r, char display);
void decksToShoe(Card s_deck1[], Card s_deck2[], Card s_shoe[], char display);
void shuffleShoe(Card s_shoe[], char display);
void dealHand(int *i, Ninja *jt, Ninja *r, Ninja *jas, Dealer *h, const Card sdd_shoe[]);
//void ninjaStrat(int *i, Ninja *ninja, const Card sdd_shoe[]);
void dealerHand(int *i, Dealer *h, const Card sdd_shoe[]);
void payOut(Ninja *ninja, Dealer *h);
void basicStrat(int *i, Ninja *ninja, Dealer *h, const Card sdd_shoe[]);
int pool_A = 8;
int pool_23 = 16;
int pool_456 = 24;
int pool_789 = 24;
int pool_10 = 32;

int main()
{

    Card AceD(11, 'd', 1), TwoD(2, 'd', 0), ThreeD(3, 'd', 0), FourD(4, 'd', 0), FiveD(5, 'd', 0), SixD(6, 'd', 0), SevenD(7, 'd', 0), EightD(8, 'd', 0), NineD(9, 'd', 0);
    Card TenD(10, 'd', 0), JackD(10, 'd', 11), QueenD(10, 'd', 12), KingD(10, 'd', 13), AceC(11, 'c', 1), TwoC(2, 'c', 0), ThreeC(3, 'c', 0), FourC(4, 'c', 0), FiveC(5, 'c', 0);
    Card SixC(6, 'c', 0), SevenC(7, 'c', 0), EightC(8, 'c', 0), NineC(9, 'c', 0), TenC(10, 'c', 0), JackC(10, 'c', 11), QueenC(10, 'c', 12), KingC(10, 'c', 13), AceH(11, 'h', 1);
    Card TwoH(2, 'h', 0), ThreeH(3, 'h', 0), FourH(4, 'h', 0), FiveH(5, 'h', 0), SixH(6, 'h', 0), SevenH(7, 'h', 0), EightH(8, 'h', 0), NineH(9, 'h', 0), TenH(10, 'h', 0);
    Card JackH(10, 'h', 11), QueenH(10, 'h', 12), KingH(10, 'h', 13), AceS(11, 's', 1), TwoS(2, 's', 0), ThreeS(3, 's', 0), FourS(4, 's', 0), FiveS(5, 's', 0), SixS(6, 's', 0);
    Card SevenS(7, 's', 0), EightS(8, 's', 0), NineS(9, 's', 0), TenS(10, 's', 0), JackS(10, 's', 11), QueenS(10, 's', 12), KingS(10, 's', 13);

    Card Deck1[52] = {AceD, TwoD, ThreeD, FourD, FiveD, SixD, SevenD, EightD, NineD, TenD, JackD, QueenD, KingD,
                      AceS, TwoS, ThreeS, FourS, FiveS, SixS, SevenS, EightS, NineS, TenS, JackS, QueenS, KingS,
                      AceC, TwoC, ThreeC, FourC, FiveC, SixC, SevenC, EightC, NineC, TenC, JackC, QueenC, KingC,
                      AceH, TwoH, ThreeH, FourH, FiveH, SixH, SevenH, EightH, NineH, TenH, JackH, QueenH, KingH
                     };

    Card Deck2[52] = {AceD, TwoD, ThreeD, FourD, FiveD, SixD, SevenD, EightD, NineD, TenD, JackD, QueenD, KingD,
                      AceS, TwoS, ThreeS, FourS, FiveS, SixS, SevenS, EightS, NineS, TenS, JackS, QueenS, KingS,
                      AceC, TwoC, ThreeC, FourC, FiveC, SixC, SevenC, EightC, NineC, TenC, JackC, QueenC, KingC,
                      AceH, TwoH, ThreeH, FourH, FiveH, SixH, SevenH, EightH, NineH, TenH, JackH, QueenH, KingH
                     };


    Card dd_shoe[104];
    srand(time(0));
    int rand_i, rand_i2;
    int c_index = 0;
    char S = 'h';
    double total_hand = 0;
    int Its_Alive = 0;

    Ninja James;
    Ninja Ryan;
    Ninja Jason;
    Dealer House;

    Card TESTER[] = {SevenC, JackD, JackD, SixH, SevenC, JackD, JackD, JackD, FourH, TenH, SevenS, NineS, EightS, TenH, TenH, TenH};
    while(Its_Alive < 100000)
    {

        shuffleDeck(Deck1, 1, S);
        shuffleDeck(Deck2, 1, S);

        for(int i = 0; i < 9; i++)   //calling shuffle for deck 1 and 2, random method each time
        {
            rand_i = rand()%3;
            if(S=='s')
            {
                std::cout << "random int = " << rand_i << std::endl;
            }
            shuffleDeck(Deck1, rand_i, S);
            rand_i2 = rand()%3;
            if(S=='s')
            {
                std::cout << "random int2 = " << rand_i2 << std::endl;
            }
            shuffleDeck(Deck2, rand_i2, S);
            if(S=='s')
            {
                std::cout << std::endl;
            }
        }
        shuffleDeck(Deck1, 1, S);
        shuffleDeck(Deck2, 1, S);


        decksToShoe(Deck1, Deck2, dd_shoe, S);
        shuffleShoe(dd_shoe, S);

//for(int a = 0; a < 104; a++) {dd_shoe[a].printCard();}
//std::cout << "\n \n";



        while(c_index < 70)
        {
            dealHand(&c_index, &James, &Ryan, &Jason, &House, dd_shoe);
            total_hand++;
            if (House.BJ == false)
            {
                basicStrat(&c_index, &James, &House, dd_shoe);
                basicStrat(&c_index, &Ryan, &House, dd_shoe);
                basicStrat(&c_index, &Jason, &House, dd_shoe);
            }



            dealerHand(&c_index, &House, dd_shoe);

            payOut(&James, &House);
            payOut(&Ryan, &House);
            payOut(&Jason, &House);

            std::cout << std::endl;


        }
        Its_Alive++;
        c_index= 0;




    }
    double a = James.getBR();
    double a_perc = ((a - 500) * -100) / (25 * total_hand);

    double b = Ryan.getBR();
    double b_perc = ((b - 500) * -100) / (25 * total_hand);

    double c = Jason.getBR();
    double c_perc = ((c - 500) * -100) / (25 * total_hand);

    std::cout << "james bank roll: " << a  << ", " << a_perc << "%" << std::endl;
    std::cout << "ryan bank roll: " << b << ", " << b_perc << "%" << std::endl;
    std::cout << "jason bank roll: " << c << ", " << c_perc << "%" << std::endl;

    std::cout <<"house has $" << House.getBR() << " left \n"<< std::endl;
    std::cout << "total hands: " << total_hand << std::endl;



    return 0;

}


void shuffleDeck(Card thisDeck[], int r, char display)  //take sorted deck and shuffle it 3 different ways. display = 's' will show all data
{
    if(display=='s')
    {
        std::cout << "chosen method: " << r << std::endl;
    }

    switch(r)
    {

    case 0:
    {
        std::vector <Card> holder;
        std::vector <Card> holder2;
        int cut=15+rand()%21;
        int x = cut;
        int y = cut - 1;
        int i = 0;


        while (x <= 51)
        {
            holder.push_back(thisDeck[x]);
            x++;
        }
        while (y >= 0)
        {
            holder2.push_back(thisDeck[y]);
            y= y - 1;
        }

        while (holder.empty() == false || holder2.empty() == false)
        {
            int r = rand()%2;
            if(r==1)
            {
                if(holder.empty()==true) {}
                else
                {
                    thisDeck[i]= holder[holder.size()-1];
                    holder.pop_back();
                    i++;
                }
            }
            else
            {
                if(holder2.empty()==true) {}
                else
                {
                    thisDeck[i]= holder2[holder2.size()-1];
                    holder2.pop_back();
                    i++;
                }
            }

        }
    }
    break;


    case 1:
    {
        int slug_total=0;
        int slug=0;
        int i=0;
        std::deque<Card> holder;
        //srand(time(0));
        int repeater=0;
        while(repeater < 3)
        {

            do
            {
                while(i+slug_total < 52)
                {
                    int r=rand()%2;
                    slug = 1+rand()%5;
                    if(display=='s')
                    {
                        std::cout << "r: " << r << ", slug is: " << slug << std::endl;
                    }
                    if(r==1)
                    {

                        holder.push_back(thisDeck[i+slug_total]);
                        i++;
                    }
                    else
                    {
                        holder.push_front(thisDeck[i+slug_total]);
                        i++;
                    }
                }
                slug_total=slug + slug_total;

            }
            while(slug_total + 6 < 52);

            if(slug_total==52) {}
            else
            {
                for(int a = 52- slug_total; a<52; a++)
                {
                    holder.push_back(thisDeck[a]);
                }
            }
            for(int i=0; i<52; i++)
            {
                thisDeck[i]=holder[i];
            }
            repeater++;
        }

    }
    break;
    case 2:
    {
        int i=0;

        std::vector<Card> holder;
        std::vector<int> int_vect;
        //srand(time(0));
        while(i< 52)
        {
            int r=1+rand()%2;
            if ( r % 2 == 0)
            {
                //cout << " rand r is: " << r ;
                holder.push_back(thisDeck[i]);
                i++;
            }
            else  //cout << " and for else rand r is: " << r << endl;
            {
                int_vect.push_back(i);
                i++;
            }
        }
        for(unsigned int x = 0; x < int_vect.size(); x++)
        {
            i = int_vect[x];
            holder.push_back(thisDeck[i]);

        }
        for(int i=0; i<52; i++)
        {
            thisDeck[i]=holder[i];
        }

    }
    break;

    }
    if(display == 's')
    {
        for(int u = 0; u<52; u++)
        {
            thisDeck[u].printCard();
        }
        std::cout << std::endl;
    }

}
void decksToShoe(Card s_deck1[], Card s_deck2[], Card s_shoe[], char display)   // takes 2 shuffled decks and strips them to s_shoe, (display = 's' will show all data)
{
    int i = 0, i2 = 0, k=0, rand_i;
    std::vector<Card> holder1;
    std::vector<int> r_holder;
    std::deque<Card> holder2;

    while(holder1.size() != 104)
    {
        if(k%2 == 0)
        {
            for(int a=0; a<4; a++)
            {
                holder1.push_back(s_deck1[i*4+a]);
            }
            i++;
        }
        else
        {
            for(int a=0; a<4; a++)
            {
                holder1.push_back(s_deck2[i2*4+a]);
            }
            i2++;
        }
        k++;
    }
    i=0;
    while(holder2.size() != 104)
    {
        rand_i = 1+rand()%2;
        if(display=='s')
        {
            std::cout << "rand_i: " << rand_i << std::endl;
        }
        if(rand_i == 1)
        {
            holder2.push_back(holder1[i]);

        }
        else
        {
            holder2.push_front(holder1[i]);
        }
        i++;

    }
    for(unsigned int j=0; j<104; j++)
    {
        s_shoe[j]=holder2[j];
    }

    if(display == 's')
    {
        for(unsigned int j=0; j<104; j++)
        {
            s_shoe[j].printCard();
        }
    }

}
void shuffleShoe(Card s_shoe[], char display)   //takes shoe and splits it into diff size holders and riffles them back together
{
    std::deque<Card> holder1;
    std::vector<Card> holder2, holder3;
    std::vector<int> holder_i;
    int rand_i, i=0;



    while(holder1.size() != 104)
    {
        rand_i = 1+rand()%2;
        if(rand_i == 1)
        {
            holder1.push_front(s_shoe[i]);
        }
        else
        {
            holder1.push_back(s_shoe[i]);
        }
        i++;
    }
    i=0;
    if(display == 's')
    {
        for(unsigned int k=0; k< holder1.size(); k++)
        {
            holder1[k].printCard();
        }
        std::cout << std::endl;
    }


    while(holder_i.size() != 104)
    {
        holder_i.push_back(rand()%2);
    }
    if(display == 's')
    {
        for(unsigned int a=0; a<holder_i.size(); a++)
        {
            std::cout << holder_i[a];
        }
        std::cout << std::endl;
    }

    while(i < 104)
    {
        if(holder_i[i] == 0)
        {
            holder2.push_back(holder1[i]);
            i++;
        }
        else
        {
            holder3.push_back(holder1[i]);
            i++;
        }
    }
    i=0;

    holder_i.clear();
    holder1.clear();

    if(display == 's'){
        for(unsigned int j=0; j < holder2.size(); j++){
            holder2[j].printCard();
        }
        std::cout << std::endl;
        if(display == 's')for(unsigned int j=0; j < holder3.size(); j++){
                holder3[j].printCard();
            }
    }

    while(holder2.empty() == false && holder3.empty() == false){
        rand_i = 1+rand()%2;
        if(rand_i == 1){
            if(i % 2 == 0){
                holder1.push_back(holder2[holder2.size()-1]);
                holder2.pop_back();
                i++;
            }else{
                holder1.push_front(holder2[holder2.size()-1]);
                i++;
                holder2.pop_back();
            }
        }else{
            if(i % 2 != 0){
                holder1.push_back(holder3[holder3.size()-1]);
                i++;
                holder3.pop_back();
            }
            else{
                holder1.push_front(holder3[holder3.size() -1]);
                holder3.pop_back();
                i++;
            }
        }
    }
    while(holder2.size() != 0){
        holder1.push_back(holder2[holder2.size() - 1]);
        holder2.pop_back();
    }
    while(holder3.size() != 0){
        holder1.push_back(holder2[holder3.size() - 1]);
        holder3.pop_back();
    }


    for(int y = 0; y < 104; y++){
        s_shoe[y] = holder1[y];

    }
    if(display == 'h'){
        for(int k=0; k< 104; k++)
        {
            if(s_shoe[k].getVal() > 11)
            {
                std::cout << "holder2 size: " << holder2.size() << "\nholder3 size: " << holder3.size() << std::endl;
            }
        }
    }

}
void dealHand(int *i, Ninja *jt, Ninja *r, Ninja *jas, Dealer *h, const Card sdd_shoe[]) // deals 2 cards to each Player{
    double house_amt = 0;
    for(int cx2 = 0; cx2 < 2; cx2++){
        if(jt->getBR() > 24){
            jt->takeCard(sdd_shoe[*i], 1);
            *i = *i + 1;
        }
        if(r->getBR() > 24){
            r->takeCard(sdd_shoe[*i], 1);
            *i = *i + 1;
        }
        if(jas->getBR() > 24){
            jas->takeCard(sdd_shoe[*i], 1);
            *i = *i + 1;
        }

        h->takeCard(sdd_shoe[*i], 1);
        *i= *i + 1;
    }

    jt->setHandValue(1);
    r->setHandValue(1);
    jas->setHandValue(1);
    h->setHandValue(1);

    if(h->topCard() == 11){
        //std::cout << "Would you like insurance? (y/n)" << std::endl;
    }


    if(jt->BJ == true && h->topCard() == 11){
        jt->payOff(0,1);
        house_amt = house_amt + jt->getBet(1);
    }
    if(r->BJ == true && h->topCard() == 11){
        r->payOff(0,1);
        house_amt = house_amt + r->getBet(1);
    }
    if(jas->BJ == true && h->topCard() == 11){
        jas->payOff(0,1);
        house_amt = house_amt + jas->getBet(1);
    }

    h->payOff(house_amt, 1);



}
//void ninjaStrat(int *i, Ninja *ninja, const Card sdd_shoe[]) {}
void dealerHand(int *i, Dealer *h, const Card sdd_shoe[]){

    if(h->getHV(1) != 21){

        while (h->getHV(1) < 17 || h->getHV(1) == 17 && h->soft == true)
        {
            h->takeCard(sdd_shoe[*i], 1);
            *i = *i+1;
            h->setHandValue(1);
        }
    }

}
void payOut(Ninja *ninja, Dealer *h){
    double house_amt = 0;



    if(ninja->BJ == true && h->BJ == false && h->topCard() != 11){
        ninja->payOff(1.5, 1);
        house_amt = house_amt + ninja->getBet(1) * 1.5 ;
    }
    for(int a = 1; a <= ninja->getSplitAmt(); a++){

        if(ninja->getHV(a) > 21){
            ninja->loss(a);
            house_amt = house_amt - ninja->getBet(a);
        }

        if(h->getHV(a) > 21){
            if(ninja->getHV(a) < 22 && ninja->BJ == false)
            {
                ninja->payOff(0, a);
                house_amt = house_amt + ninja->getBet(a);
            }
        }
        if( h->getHV(1) < 22 && ninja->getHV(a) < 22 && ninja->getHV(a) > h->getHV(1) && ninja->BJ == false){
            ninja->payOff(0,a);
            house_amt = house_amt + ninja->getBet(a);
        }else{
            if(h->getHV(1) < 22 && ninja->getHV(a) < 22 && ninja->getHV(a) < h->getHV(1))
            {
                ninja->loss(a);
                house_amt = house_amt - ninja->getBet(a);
            }
        }

    }
    h->payOff(house_amt, 1);
    h->clearHands();
    ninja->clearHands();

}
void basicStrat(int *i, Ninja *ninja, Dealer *h,const  Card sdd_shoe[]){

    for(int a = 1; a <= ninja->getSplitAmt(); a++){

        if(ninja->getHandSize(a) == 1){
            ninja->takeCard(sdd_shoe[*i], a);
            *i=*i+1;
            ninja->setHandValue(a);
        }

        while(ninja->splitAble(a) == true && ninja->getHV(a) != 10 && ninja->getHV(a) != 20 && h->topCard() < 7){
            ninja->split(a);
            ninja->takeCard(sdd_shoe[*i], a);
            *i=*i+1;
            ninja->setHandValue(a);
        }

        if(h->topCard() < 7){
            ninja->setHandValue(a);
            if(ninja->dbleAble(a) == true){
                ninja->takeCard(sdd_shoe[*i], a);
                *i= *i+1;
                ninja->dble(a);
                ninja->setHandValue(a);
            }else{
                while(ninja->getHV(a) < 12 || (ninja->getHV(a) < 18 && ninja->soft == true)){
                    ninja->takeCard(sdd_shoe[*i], a);
                    *i= *i+1;
                    ninja->setHandValue(a);
                }
            }
        }

        if(ninja->dbleAble(a) == true && ninja->getHV(a) == 11 && h->getHV(1) > 6){
            ninja->takeCard(sdd_shoe[*i], a);
            *i= *i+1;
            ninja->dble(a);
            ninja->setHandValue(a);
        }else{
            if(h->topCard() > 6 && ninja->splitAble(a) == true && (ninja->getHV(a) == 16 || ninja->getHV(a) == 12)){
                ninja->split(a);
                ninja->takeCard(sdd_shoe[*i], a);
                *i=*i+1;
                ninja->setHandValue(a);
            }
        }

        if(ninja->dbleAble(a) == true && h->topCard() > 6 && ninja->splitAble(a) == false){
            ninja->takeCard(sdd_shoe[*i], a);
            *i= *i+1;
            ninja->dble(a);
            ninja->setHandValue(a);
        }else{
            if(h->topCard() > 6 && ninja->splitAble(a) == false){
                while(ninja->getHV(a) < 17 || (ninja->getHV(a) < 18 && ninja->soft == true && h->topCard() > 9)){
                    ninja->takeCard(sdd_shoe[*i], a);
                    *i= *i+1;
                    ninja->setHandValue(a);
                }
            }

        }
    }
}



