

#ifndef Card_h
#define Card_h

#include <iostream>
#include <string>
using namespace std;


class Card{
public:

    string getSuit();
    string getRank();
    int getRankInt();
    void setSuit(string suit);
    void setRank(int rank);
    friend ostream& operator<<(ostream& out, const Card& card);
    Card();
    Card(string suit, int rank);
private:
    string suit;
    int rank;
    
};

#endif
