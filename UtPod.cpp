#include <cstdlib>
#include <iostream>
#include <UtPod.h>
#include <string>
using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
    srand(time(0));
}

UtPod::UtPod(int size){
    if(size>MAX_MEMORY || size<= 0) //if the input is not acceptable, set memSize to max
        memSize = MAX_MEMORY;
    else
        memSize = size;

    srand(time(0));
    songs = NULL;
}

int UtPod::addSong(Song const &s) {
    if(s.getSize() > this->getRemainingMemory())    //if there is not enough memory, unsuccessful
        return NO_MEMORY;
    SongNode *temp = new SongNode;      //creates a tmp node; copies over info; adds to the head of the linked list
    temp->s.setTitle(s.getTitle());
    temp->s.setArtist(s.getArtist());
    temp->s.setSize(s.getSize());
    temp->next = songs;
    songs = temp;
    return SUCCESS;
}

int UtPod::removeSong(Song const &s) {
    SongNode *temp = songs;
    SongNode *prev = songs;
    if(temp->s == s){                 //if the desired song is at the start, delete it and return
        songs = songs->next;
        return SUCCESS;
    }
    while(temp != NULL){
        if(temp->s==s){
            prev->next = temp->next; //prev node points to the next of current node; current node is skipped
            delete(temp);
            return SUCCESS;
        }
        prev = temp;
        temp = temp->next;
    }
    return NOT_FOUND;
}

void UtPod::shuffle() {
    int len = this->length();
    if(len<2)       //if there are less than 2 songs, dont do anything
        return;
    for(int x=0; x<(2*len); x++){       //shuffles twice as many songs there are
        int rand1 = rand()%len;
        int rand2 = rand()%len;
        SongNode *node1 = this->nodeAt(rand1);
        SongNode *node2 = this->nodeAt(rand2);
        node1->s.swap(node2->s);
    }
}

void UtPod::showSongList() {
    SongNode *temp = songs;
    while(temp != NULL){            //iterates through linked list and prints out each node's song info
        cout << temp->s.getTitle()+", " << temp->s.getArtist()+", " << temp->s.getSize() << endl;
        temp = temp->next;
    }
}

void UtPod::sortSongList() {
    int len = this->length();
    if(len<2)
        return;
    for(SongNode *outer = songs; outer != NULL; outer = outer->next){ //insertion sort
        for(SongNode *inner = outer->next; inner != NULL; inner = inner -> next){
            if(inner->s < outer->s){
                inner->s.swap(outer->s);
            }
        }
    }
}

void UtPod::clearMemory() {
    SongNode *current = songs;
    while(current != NULL){         //iterates through the linked list and deletes all song nodes
        SongNode *del = current;
        current = current->next;
        delete del;
    }
    songs = NULL;
}

int UtPod::getRemainingMemory() {
    int taken = 0;
    SongNode *temp = songs;
    while(temp != NULL){            //iterates through the linked list and adds up the memory of each song
        taken += temp->s.getSize();
        temp = temp->next;
    }
    return memSize-taken;           //returns the remaining memory
}

UtPod::~UtPod(){
    clearMemory();  //clears memory then deletes songs pointer
    delete(songs);
}

UtPod::SongNode* UtPod::nodeAt(int i){
    SongNode* check = songs;
    int j = 0;

    while(check!=NULL) {
        if(j==i){              //if we have reached our desired index, return the node at the index
            return check;
        }
        check = check->next;   //move to check the next node
        j++;
    }
    return NULL;
}

int UtPod::length(){    //counts the number of song nodes in the list
    int len = 0;
    SongNode* index = songs;
    while(index!=NULL)
    {
        index=index->next;
        len++;
    }
    return len;
}