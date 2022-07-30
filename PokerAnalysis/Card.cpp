#include "Card.h"

string Card::getSuit(){
    return suit;
}

int Card::getRankInt(){
    return rank;
}

string Card::getRank(){
    if(rank == 0){
        return "Ace";
    }
    if(rank == 1){
        return "Two";
    }
    if(rank == 2){
        return "Three";
    }
    if(rank == 3){
        return "Four";
    }
    if(rank == 4){
        return "Five";
    }
    if(rank == 5){
        return "Six";
    }
    if(rank == 6){
        return "Seven";
    }
    if(rank == 7){
        return "Eight";
    }
    if(rank == 8){
        return "Nine";
    }
    if(rank == 9){
        return "Ten";
    }
    if(rank == 10){
        return "Jack";
    }
    if(rank == 11){
        return "Queen";
    }
    if(rank == 12){
        return "King";
    }
    return "hi";
}

void Card::setSuit(string suit){
    this->suit = suit;
}

void Card::setRank(int rank){
    this->rank = rank;
}


Card::Card(){
    suit = "";
    rank = 0;
}

Card::Card(string suit, int rank){
    this->suit = suit;
    this->rank = rank;
}

