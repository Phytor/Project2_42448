#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "deck.h"

Deck::Deck(){

    srand (time(NULL));

    bool correct = false;

    while ( !correct ){

        cout << endl << endl << "How many decks would you like to play with? (1 - 5)" << endl;
        cin >> numberofdecks;

        if ( numberofdecks > 5 || numberofdecks < 1 ){

            cout << endl << "That is not an acceptable number.";

        }

        else correct = true;
    }

    for ( int i = 0; i < 13; ++i ){
        deck [i] = 4 * numberofdecks;
    }

}

void Deck::deal ( player* players, int* dealerhand , int numberofplayers ){

    int card;
    bool cardexists = true;
    int cardcount = 0;
    bool first = true;

    for ( int i = 0; i < numberofplayers; ++i ){

        for ( int e = 0; e < 5; ++e ){

            if( players[i].hand[e] != 0) first = false;

        }

    }
    if( first ){

        for( int i = 0; i < numberofplayers; ++i ){

            for(int e = 0; e < 2; ++e){

                cardexists = false;
                while( !cardexists){

                    card = rand() % ( 13 - 1 ) + 1;
                    if( deck [card] > 0 ){

                        players[i].hand[e] = card;
                        cardexists = true;

                    }

                    for( int j = 0; j < 13; ++j){

                        cardcount += deck [j];

                    }

                    //if( cardcount < 10 ) shuffle( deck, numofdecks);

                }

                deck[card] -= 1;

            }

        }
    }

    for(int e = 0; e < 2; ++e){

            cardexists = false;
            while( !cardexists){

                card = rand() % ( 13 - 1 ) + 1;
                if( deck [card] > 0 ){

                    dealerhand[e] = card;
                    cardexists = true;
                    cout << endl << dealerhand[e];

                }

                for( int j = 0; j < 13; ++j){

                    cardcount += deck [j];

                }

            }

            deck[card] -= 1;


    }


    if ( !first ){

        for( int i = 0; i < numberofplayers; ++i ){

            for(int e = 0; e < 5; ++e){

                if ( players[i].hand[e] == 0 ){

                    cardexists = false;
                    while( !cardexists){

                        card = rand() % ( 13 - 1 ) + 1;

                        if( deck[card] > 0 ){

                            players[i].hand[e] = card;
                            cardexists = true;
                        }
                        for( int j = 0; j < 13; ++j){
                            cardcount += deck[j];
                        }
                        //if( cardcount < 10 ) shuffle( deck, numofdecks);
                    }
                    deck[card] -= 1;
                    //display( players, number);
                    return;
                }
            }
        }
    }
}

void Deck::hit ( player* players, int* dealerhand, int i ){

    int card;
    int cardcount;
    bool cardexists;

    if ( i > -1 ){

        for ( int j = 0; j < 5; ++j ){

            if ( players[i].hand[j] == 0 ){

                cardexists = false;
                while( !cardexists){


                    card = rand() % ( 13 - 1 ) + 1;

                    if( deck[card] > 0 ){

                        players[i].hand[j] = card;
                        cardexists = true;
                    }
                    for( int k = 0; k < 13; ++k){
                        cardcount += deck[k];
                    }
                    //if( cardcount < 10 ) shuffle( deck, numofdecks );
                }
                deck[card] -= 1;
                //display( players, number);
                return;

            }

        }

    }

    else if ( i == -1 ){

        for ( int j = 0; j < 4; ++j ){

            if ( dealerhand[j] == 0 ){

                cardexists = false;
                while( !cardexists){

                    card = rand() % ( 13 - 1 ) + 1;

                    if( deck[card] > 0 ){

                        dealerhand[j] = card;
                        cardexists = true;
                    }
                    for( int k = 0; k < 13; ++k){
                        cardcount += deck[k];
                    }
                    if( cardcount < 10 ) shuffle();
                }
                deck[card] -= 1;
                //display( players, number);
                return;

            }

        }

    }

}

void Deck::shuffle (){

    for ( int i = 0; i < 13; ++i ){

        deck[i] = 4 * numberofdecks;

    }

}


