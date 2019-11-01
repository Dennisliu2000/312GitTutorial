#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t(256);

    cout << t.getRemainingMemory() << endl;

    Song s1("Hail to the King", "Avenged Sevenfold", 25);
    int result = t.addSong(s1);
    cout << "add: "<<result<<endl;

    Song s2("Shepherd of Fire", "Avenged Sevenfold", 25);
    result = t.addSong(s2);
    cout<<"add: "<<result<<endl;

    Song s3("Enter Sandman", "Metallica", 25);
    result = t.addSong(s3);
    cout<<"add: "<<result<<endl;

    Song s4("Shepherd of Fire", "Avenged Sevenfold", 20);
    result = t.addSong(s4);
    cout<<"add: "<<result<<endl;

    Song s5("Bing Bing Bong", "I will not fit", 500);
    result = t.addSong(s5);
    cout<<"add: "<<result<<endl;

    t.showSongList();
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    t.shuffle();
    t.showSongList();
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    t.shuffle();
    t.showSongList();
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    t.sortSongList();
    t.showSongList();
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    cout<<"Remaining memory: "<< t.getRemainingMemory()<<endl;
    Song s6("Shepherd of Fire", "Avenged Sevenfold", 20);
    result = t.addSong(s6);
    cout<<"add: "<<result<<endl;
    t.sortSongList();

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    t.showSongList();

    result = t.removeSong(s6);
    cout<<"remove: "<< result<<endl;

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    t.showSongList();

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    t.clearMemory();
    result = t.getRemainingMemory();
    cout<<"Remaining Memory: "<<result<<endl;
    t.showSongList();
}