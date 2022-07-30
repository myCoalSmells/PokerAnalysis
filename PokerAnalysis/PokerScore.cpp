#include "PokerScore.h"



void PokerScore::operator+=(const Scores& score){
    scores.push_back(score);
}



int PokerScore::size(){
    return scores.size();
}

Scores& PokerScore::operator[](unsigned int index){
    return scores[index];
}

PokerScore::PokerScore(){
    
}

bool operator==(const PokerScore& p, Scores score){
    
    for(int i=0; i<p.scores.size(); i++){
        if(p.scores[i]==score){
            return true;
        }
    }
    return false;
    
}
