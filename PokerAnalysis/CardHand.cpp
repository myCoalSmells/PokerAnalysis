

#include "CardHand.h"


void CardHand::drawCard(Deck &deck){
    hand.push_back(deck.dealCard());
}

Card CardHand::getCardAt(int index){
    return hand[index];
}

PokerScore CardHandScorer::scorePokerHand(CardHand &ch){
    PokerScore ps;

    bool same_suit;
    same_suit = false;

    int ranks[13] = {0};
    int suits[4] = {0};
    int first_value_index;
    first_value_index = ch.getCardAt(0).getRankInt();

    for (int i = 0; i < 5; i++) {
        ranks[ch.getCardAt(i).getRankInt()] = ranks[ch.getCardAt(i).getRankInt()] += 1;
        
        string suit = ch.getCardAt(i).getSuit();
        if (suit == "Hearts") {
            suits[0] = suits[0] + 1;
        } else if (suit == "Clubs") {
            suits[1] = suits[1] + 1;
        } else if (suit == "Diamonds") {
            suits[2] = suits[2] + 1;
        } else if (suit == "Spades") {
            suits[3] = suits[3] + 1;
        }
    }

    //FLUSH and checking if suits are the same
    for (int i = 0; i < 4; i++) {
        if (suits[i] == 5) {
            ps += FLUSH;
            same_suit = true;
        }
    }

    for (int i = 0; i < 13; i++) {
        if (same_suit) {
            //STRAIGHT FLUSh
            bool is_straight_flush = true;
            for (int j = first_value_index; j < first_value_index + 5; j++) {
                if (ranks[j] != 1) {
                    is_straight_flush = false;
                    break;
                }
            }

            if (is_straight_flush) {
                ps += STRAIGHT_FLUSH;
                ps += STRAIGHT;
            }

            //ROYAL FLUSH
            if (ranks[0] == 1 && ranks[9] == 1 && ranks[10] == 1 && ranks[11] == 1 && ranks[12] == 1) {
                ps += ROYAL_FLUSH;
            }
        } else {
            //STRAIGHT
            bool is_straight = true;
            for (int j = first_value_index; j < first_value_index + 5; j++) {
                if (ranks[j] != 1) {
                    is_straight = false;
                    break;
                }
            }

            if (is_straight) {
                ps += STRAIGHT;
            }
            //FOAK
            if (ranks[i] == 4) {
                ps += FOUR_OF_A_KIND;
                ps += THREE_OK_A_KIND;
                ps += ONE_PAIR;
                break;
            //TOAK and FULL HOUSE
            } else if (ranks[i] == 3) {
                ps += THREE_OK_A_KIND;
                ps += ONE_PAIR;

                for (int j = i + 1; j < 13; j++) {
                    if (ranks[j] == 2) {
                        ps += FULL_HOUSE;
                    }
                }
                break;
            //ONE PAIR AND TWO PAIR
            } else if (ranks[i] == 2) {
                ps += ONE_PAIR;

                for (int j = i + 1; j < 13; j++) {
                    if (ranks[j] == 2) {
                       ps += TWO_PAIR;
                    }
                }
                break;
            }
        }
    }

    //HIGH CARD
    ps += HIGH_CARD;

    return ps;
}


