#ifndef DECK_H
#define DECK_H

class Deck{

    int deck [13];
    int numberofdecks;

public:

    Deck(int);
    void deal ( struct player*, int /*number of players*/ , int /*number of decks*/ , int* /*deck*/ );
    void reshuffle ( int /*number of decks*/ , int* /*deck*/ );
    void printdeck ( int* );
};




#endif // DECK_H
