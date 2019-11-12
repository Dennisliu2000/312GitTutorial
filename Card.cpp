#include <iostream>
#include <string>
#include  "Card.h"

using namespace std;

Card::Card(){       //default is Ace of Spades
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{      //concatenates the rank string and suit string
    return this->rankString(myRank)  + this->suitString(mySuit);
}

bool Card:: sameSuitAs(const Card& c) const{ //returns true if the 2 suits are equal
    return mySuit == c.mySuit;
}

int Card:: getRank() const{ //returns true if the 2 ranks are not equal
    return myRank;
}

string Card:: suitString(Suit s) const{
    string suit;
    switch(s){
        case spades: suit = "s";  break;      //switch statement for each Suit possibility
        case hearts: suit = "h";break;
        case diamonds: suit = "d";break;
        case clubs: suit = "c";break;
    }
    return suit;
}

string Card::rankString(int r) const {
    string rank;
    switch(r){                  //switch statement for each drank possibility
        case 1: rank = "A";break;
        case 2: rank = "2";break;
        case 3: rank = "3";break;
        case 4: rank = "4";break;
        case 5: rank = "5";break;
        case 6: rank = "6";break;
        case 7: rank = "7";break;
        case 8: rank = "8";break;
        case 9: rank = "9";break;
        case 10: rank = "10";break;
        case 11: rank = "J";break;
        case 12: rank = "Q";break;
        case 13: rank = "K";break;
    }
    return rank;
}

bool Card:: operator==(const Card& rhs) const{
    return myRank == rhs.myRank;                //returns true if the 2 ranks are equal
}

bool Card:: operator!=(const Card& rhs) const{
    return !(myRank == rhs.myRank);             //returns true if the 2 ranks are not equal
}

ostream& operator << (ostream& out, const Card& c){
    out << c.toString() << " ";                 //adds a space after the conversion to string for convenience
    return out;
}