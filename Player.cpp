// FILE: Player.cpp
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Card.h"
#include <algorithm>

using namespace std;


void Player::addCard(Card c){   //Add the input card to the player's hand
    myHand.push_back(c);
}

bool Player::cardInHand(Card c) const{   //boolean: is the card in the player's hand?
    auto start = myHand.begin();
    auto end = myHand.end();
    auto index = find(start, end,c);   //from the algorithm library

    if (index!=end)
        return true;
    return false;
}

void Player::bookCards(Card a, Card b){  // "Book" two cards together in a pair

    auto start = myHand.begin();
    auto end = myHand.end();
    auto indexA = find(start, end, a);
    auto indexB = find(start, end, b);

    if(indexA != end && indexB != end){
        myHand.erase(indexA);
        auto indexB = find(start,end,b);
        myHand.erase(indexB);
        myBook.push_back(a);
    }
}

Card Player::chooseCardFromHand() const{   //returns a random card in the player's hand
    return myHand[rand()%myHand.size()];
}

string Player::showHand() const{  //show the hand as a string of cards separated by a space
    string output = "";
    auto start = myHand.begin();
    auto end = myHand.end();

    for(auto index = start; index != end; index++)
        output = output + index->toString() +" ";

    return output;
}

Card Player::removeCardFromHand(Card card){   //remove and return the input card

    auto start = myHand.begin();
    auto end = myHand.end();
    auto index= find(start, end, card);

    if(index  != end){
        myHand.erase(index);   //delete the card
        return card;           //give it back
    }
    else
        return Card();  //new card because the card doesn't exist
}

string Player::showBooks() const{
    string output = "";
    auto start = myHand.begin();
    auto end = myHand.end();

    for(auto index = start; index != end; index++)

        output = output + index->toString() +" ";

    return output;
}

int Player::getHandSize() const{

    return myHand.size();
}

int Player::getBookSize() const{

    return myBook.size();
}

bool Player::sameRankInHand(Card card) const{
    if (myHand.size()==0)
        return false;
    auto start = myHand.begin();
    auto end = myHand.end();

    for(auto i = start; i != end; i++){
        if(i->getRank() == card.getRank())
            return true;
    }
    return false;
}


bool Player::checkHandForPair(Card &cardA, Card &cardB){   //return true or false and also change the cards to the booked cards
    for(auto index = myHand.begin(); index != myHand.end(); index++){
        for(auto i = myHand.begin(); i != myHand.end(); i++){
            if(index->getRank() == i->getRank() && (index)!=(i))
            {
                cardA = *index;   //change the cards in the given address
                cardB = *i;
                return true;
            }
        }
    }

    return false;  //and do not change the cards
}

Card Player::cardWithSameRankInHand(Card& c) const{
    auto start = myHand.begin();
    auto end = myHand.end();

    for(auto i = start; i != end; i++)
        if(i->getRank() == c.getRank())
            return *i;
    return Card();
}





































