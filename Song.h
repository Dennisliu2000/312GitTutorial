//
// Created by denni on 10/26/2019.
//

#ifndef SONG_H
#define SONG_H

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Song{
private:
        string title;
        string artist;
        int size;

public:
        Song(); // default constructor
        Song(string _title, string _artist, int _size);// constructor with all parameters
        string getTitle() const; //returns song title
        string getArtist() const; //returns the artist name
        int getSize() const; //returns the size of the song
        void setTitle(string newTitle); //sets the name of the song
        void setArtist(string newArtist); //sets the artist
        void setSize(int newSize); //sets the size of the song
        bool operator ==(Song const &s); //overloads ==
        bool operator <(Song const &s); //overloads <
        bool operator >(Song const &s); //overloads >
        void swap(Song &s);
};



#endif //UNTITLED2_SONG_H
