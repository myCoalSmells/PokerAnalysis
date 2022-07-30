

#ifndef Deck_h
#define Deck_h

#include <iostream>
using namespace std;
#include "Card.h"


class Deck{
public:
    bool empty(); //returns true if deck has no cards
    void shuffle(); // puts cards in random order
    friend ostream& operator<<(ostream& out, const Deck& deck); // prints all the cards to the console
    Card dealCard(); // returns the next card in the deck
    Card getCardAt(int index);// gets the Card at the given index
    Deck(); // this is the constructor
    void printDeck();
    void setCardIndex(int x);
private:
    int cardIndex; //marks the index of the next card in the deck
    Card deck[52];// this is your final deck of cards
    const int DECK_SIZE = 52;// this is the size of your deck
};


#endif
