#include "Deck.h"

void Deck::setCardIndex(int x){
    cardIndex = x;
}

bool Deck::empty(){ //returns true if deck has no cards
    if(cardIndex==53)
        return true;
    return false;
}
void Deck::shuffle(){
    for(int i=0; i<52; i++){
        Card temp = deck[i];
        int random = rand()%53;
        deck[i] = deck[random];
        deck[random] = temp;
    }
} // puts cards in random order


Card Deck::dealCard(){
//    cout << "at this index: " << cardIndex << endl;
    cardIndex+=1;
//    cout << "at this index: " << cardIndex << endl;
    return deck[cardIndex-1];
} // returns the next card in the deck

Card Deck::getCardAt(int index){
    return deck[index];
}// gets the Card at the given index

Deck::Deck(){
    cardIndex = 0;
    for(int i=0; i<52; i++){
        if(i<13){ //hearts
            deck[i] = Card("Hearts", i%13);
        }
        else if(i<26){ //diamonds
            deck[i] = Card("Diamonds", i%13);
        }
        else if(i<39){ //spades
            deck[i] = Card("Spades", i%13);
        }
        else{ //clubs
            deck[i] = Card("Clubs", i%13);
        }
    }
    
} // this is the constructor



void Deck::printDeck(){
    for(int i = 0; i<52; i++){
        cout << i+1 << ": " << deck[i].getRank() << " of " << deck[i].getSuit() << endl;
    }
}
