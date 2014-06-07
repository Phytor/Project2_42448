//Stephen Anderson
//17a Project 2

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

#include "player.h"
#include "deck.h"

int getplayers();
void getnames( player* , int );


int main(){

    int numberofplayers = getplayers();

    player * players = new player [ numberofplayers ];




system ("PAUSE");
return 0;
}

int getplayers(){

    bool correct = false;
    int number;

    while ( !correct ){

        cout << endl << endl << "How many players would you like to play with? ( 0 - 2 )" << endl;
        cin >> number;
            if ( number < 0 || number > 2 ){
                cout << endl << endl << "That is not an acceptable number." << endl;
                correct = false;
            }
            else correct = true;
    }
    return number;
}

void getnames( player* players , int numberofplayers ){



}


