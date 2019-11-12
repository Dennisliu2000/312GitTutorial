// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
bool gameOver(Player &player, Player &other);
void checkCards(Player &player);
void playerAsks(Player &player, Player &other, Deck &deck);

const string fileName = "gofish_results.txt";
ofstream out;
bool switchPlayer = true;


int main( )
{
    int numCards = 7;

    Player p1("Kenneth");
    Player p2("Dennis");
    Player *players[2] = {&p1,&p2};

    Deck d;  //create a deck of cards

    d.shuffle();
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);


    int player = 0;
    out.open("gofish_results.txt");
    do{
        out<<players[player]->getName()<<"'s turn"<<endl;
        checkCards(*players[0]);
        checkCards(*players[1]);

        out<< players[0]->getName() <<"'s Hand:";   //print player 1's hand
        out<< players[0]->showHand() <<endl;

        out<< players[1]->getName() <<"'s Hand:";   //print player 2's hand
        out<< players[1]->showHand() <<endl;

        out<<"Cards in Deck: "<<d.size()<<endl;
        out<<endl;

        if(players[player]->getHandSize()==0){
            if(d.size()!=0){
                players[player]->addCard(d.dealCard());
            }
            switchPlayer = true;
        }
        else{
            playerAsks(*players[player], *players[(player+1)%2], d);
        }
        if (switchPlayer) {
            if (player == 0)
                player = 1;
            else
                player = 0;
        }

    }while(!gameOver(*players[player], *players[(player+1)%2]));

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    out<<"Game Over"<<endl;
    if (players[0]->getBookSize()>players[1]->getBookSize())
        out<<players[0]->getName()<<" Won!"<<endl;
    else
        out<<players[1]->getName()<<" Won!"<<endl;

    out.close();

    return EXIT_SUCCESS;
}

void playerAsks(Player &player, Player &other, Deck &deck){
    Card c = player.chooseCardFromHand();
    out<<player.getName()<<" asks: Do you have a "<< c.rankString(c.getRank()) <<"?"<<endl;
    out<<other.getName()<< " says: ";

    if(other.sameRankInHand(c)){

        switchPlayer = false;
        Card t = other.cardWithSameRankInHand(c);   //get the card from the other person's hand
        other.removeCardFromHand(t);   //transfer the card
        player.addCard(t);

        out<<"Yes, I have a "<< c.rankString(c.getRank())<<endl;
        out<<"Transferred the "<<t.toString()<<endl;
    }
    else{
        switchPlayer = true;
        Card card = deck.dealCard();   //transfer a new card from the deck and give it to the player
        player.addCard(card);

        out<<"Go Fish!"<<endl;
        out<<player.getName()<< " drew "<<card.toString() << endl;
    }
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

bool gameOver(Player &player, Player &other){  //is the game over?
    return !((player.getBookSize()+other.getBookSize())<26);
}

void checkCards(Player &player){
    Card a;
    Card b;
    while (player.checkHandForPair(a,b)) {

        player.bookCards(a, b);
        out << player.getName() << " booked " << a << b << endl;
    }
}


