#include <iostream>
using namespace std;

#include "deck.h"


Deck::Deck( int decks ){

    numberofdecks = decks;

    for ( int i = 0; i < 13; ++i ){
        deck [i] = 4 * decks;
    }

    for ( int j = 0; j < 13; ++j){

        cout << deck [j] << endl;

    }


}

