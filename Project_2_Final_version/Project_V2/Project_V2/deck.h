#ifndef DECK_H
#define DECK_H

#include "player.h"

class Deck{

    int deck [13];
    int numberofdecks;

public:

    Deck ();
    void deal ( player*, int* , int /*number of players*/ );
    void reshuffle ( int /*number of decks*/ , int* /*deck*/ );
    void printdeck ( int* );
    void hit ( player* , int* , int );
    void shuffle ();

};




#endif // DECK_H
