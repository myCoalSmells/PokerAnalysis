

#include <iostream>
#include "Deck.h"
#include "CardHand.h"

PokerScore testPokerScore(){
    Deck d;
    d.shuffle();
    CardHand ch1, ch2, ch3, ch4, ch5;
    for(int i=0; i<5; i++){
        ch1.drawCard(d);
        ch2.drawCard(d);
        ch3.drawCard(d);
        ch4.drawCard(d);
        ch5.drawCard(d);
    }
    
    CardHandScorer chs;
    PokerScore ch1Score = chs.scorePokerHand(ch1);
    
    return ch1Score;
}

void testShuffle(){
    Deck hi;
    hi.shuffle();
    hi.printDeck();
}

int main() {
    srand((unsigned)time(0));

    int rf(0), sf(0), f(0), fh(0), fl(0), s(0), thr(0), tp(0), op(0), hc(0);
    for(int i=0; i<1000; i++){

        
        PokerScore ps = testPokerScore();
        if(ps == ROYAL_FLUSH){
            rf++;
        }
        if(ps == STRAIGHT_FLUSH){
            sf++;
        }
        if(ps == FOUR_OF_A_KIND){
            f++;
        }
        if(ps == FULL_HOUSE){
            fh++;
        }
        if(ps == FLUSH){
            fl++;
        }
        if(ps == STRAIGHT){
            s++;
        }
        if(ps == THREE_OK_A_KIND){
            thr++;
        }
        if(ps == TWO_PAIR){
            tp++;
        }
        if(ps == ONE_PAIR){
            op++;
        }
        if(ps == HIGH_CARD){
            hc++;
        }
        
    }
    
    cout << "ROYAL_FLUSH: " << rf << endl;
    cout << "STRAIGHT_FLUSH: " << sf << endl;
    cout << "FOUR_OF_A_KIND: " << f << endl;
    cout << "FULL_HOUSE: " << fh << endl;
    cout << "FLUSH: " << fl << endl;
    cout << "STRAIGHT: " << s << endl;
    cout << "THREE_OF_A_KIND: " << thr << endl;
    cout << "TWO_PAIR: " << tp << endl;
    cout << "ONE_PAIR: " << op << endl;
    cout << "HIGH_CARD: " << hc << endl;


    
}
