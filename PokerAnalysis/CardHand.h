#ifndef CardHand_h
#define CardHand_h

#include <vector>
#include "Card.h"
#include "Deck.h"
#include "PokerScore.h"

class CardHand{
public:
    void drawCard(Deck &deck);
    Card getCardAt(int index);
private:
    vector<Card> hand;
};

class CardHandScorer{
public:
    static PokerScore scorePokerHand(CardHand &ch);
private:
};

#endif
