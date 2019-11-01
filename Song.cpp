#include <cstdlib>
#include <iostream>
#include <Song.h>
#include <string>
using namespace std;

Song::Song(){       //default constructor not needed
    title = "";
    artist = "";
    size = 0;
}

Song::Song(string _title, string _artist, int _size) {
    title = _title;
    artist = _artist;
    size = _size;
}

string Song::getArtist() const{
    return artist;
}

int Song::getSize() const{
    return size;
}

string Song::getTitle() const{
    return title;
}

void Song::setTitle(string newTitle){
    title = newTitle;
}

void Song::setArtist(string newArtist) {
    artist = newArtist;
}

void Song::setSize(int newSize) {
    size = newSize;
}

bool Song::operator==(Song const &s){
    if(artist.compare(s.getArtist()) == 0 && title.compare(s.getTitle())==0 && size==s.getSize())
        return true;
    return false;
}

bool Song::operator<(Song const &s){
    if(artist.compare(s.getArtist()) < 0)
        return true;
    else if (artist.compare(s.getArtist()) > 0) //if the current song is greater than the passed song in any field, it is automatically false
        return false;
    else if(title.compare(s.getTitle()) < 0)
        return true;
    else if (title.compare(s.getTitle()) > 0)
        return false;
    else if(size < s.getSize())
        return true;
    else if(size > s.getSize())
        return false;

    return false;                               //this returns false if the two songs are equal
}

bool Song::operator>(Song const &s) {
    if(artist.compare(s.getArtist()) > 0)
        return true;
    else if(title.compare(s.getTitle()) > 0)
        return true;
    else if(size > s.getSize())
        return true;

    return false;
}

void Song::swap(Song &s){                       //swaps the information of the 2 songs
    string tempTitle = this->getTitle();
    string tempArtist = this->getArtist();
    int tempSize = this->getSize();
    this->setTitle(s.getTitle());
    this->setArtist(s.getArtist());
    this->setSize(s.getSize());
    s.setTitle(tempTitle);
    s.setArtist(tempArtist);
    s.setSize(tempSize);
}