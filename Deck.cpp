#include <iostream>
#include <string>
#include  "Deck.h"
#include <ctime>
#include <algorithm>

using namespace std;

Deck:: Deck(){
    srand(time(0));         //iterates through all possible combinations and creates cards
    myIndex = 0;
    int deckPos = 0;
    for(int i = 0; i<4; i++){
        for(int j = 1; j<14; j++){
            myCards[deckPos] = Card(j, Card::Suit(i));
            deckPos++;
        }
    }
}

void Deck:: shuffle(){
    for(int i = 0; i< 200; i++){
        int rand1 = rand()%51;      //makes a bunch of random numbers and swaps the array elements
        int rand2 = rand()%51;
        swap(myCards[rand1], myCards[rand2]);
    }
}

Card Deck:: dealCard(){
    myIndex++;
    if(myIndex > 52)        //if we have passed the max index, we fail
        exit(0);
    else {
        return myCards[myIndex - 1];  //return the previous index since we increment index at the beginning
    }
}

int Deck:: size() const{
    return SIZE - myIndex;      //returns the remaining amount of cards
}