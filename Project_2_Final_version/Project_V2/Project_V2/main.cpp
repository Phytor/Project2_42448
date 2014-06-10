//Stephen Anderson
//17a Project 2

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

#include "player.h"

#include "deck.h"

void rules();
int getplayers ();
void getnames( player* , int );
void getbets ( player* , int );
void printbets ( player* , int );
void display ( player* , player , int );
void showHandTop ( player* , player, int );
void showHandMid ( player* , player, int );
void showHandBot ( player* , player, int );
void clearscreen ();
void choice ( player*, player, int , Deck );
int acechoice ();


int main(){

    srand (time(NULL));

    cout << "         _     _  _______  ___      ______  _______  __   __  _______  " << endl
         << "        | | _ | ||       ||   |    |      ||       ||  |_|  ||       |" << endl
         << "        | || || ||    ___||   |    |      ||   _   ||       ||    ___| " << endl
         << "        |       ||   |___ |   |    |      ||  | |  ||       ||   |" << endl
         << "        |       ||    ___||   |___ |     _||  |_|  ||       ||    ___| " << endl
         << "        |   _   ||   |___ |       ||    |_ |       || ||_|| ||   | " << endl
         << "        |__| |__||_______||_______||______||_______||_|   |_||_______| " << endl << endl
         << "                              _______  _______ " << endl
         << "                             |       ||       | " << endl
         << "                             |_     _||   _   | " << endl
         << "                               |   |  |  | |  | " << endl
         << "                               |   |  |  |_|  | " << endl
         << "                               |   |  |       | " << endl
         << "                               |___|  |_______| " << endl << endl
         << " _______  ___      _______  ______  ___   _      ___  _______  ______  ___   _  "
         << "|  _    ||   |    |   _   ||      ||   | | |    |   ||   _   ||      ||   | | | "
         << "| |_|   ||   |    |  |_|  ||      ||   |_| |    |   ||  |_|  ||      ||   |_| | "
         << "|       ||   |    |       ||      ||      _|    |   ||       ||      ||      _| "
         << "|  _   | |   |___ |       ||     _||     |_  ___|   ||       ||     _||     |_  "
         << "| |_|   ||       ||   _   ||    |_ |    _  ||       ||   _   ||    |_ |    _  | "
         << "|_______||_______||__| |__||______||___| |_||_______||__| |__||______||___| |_| " << endl;

    rules();

    Deck Thedeck;

    char endchoice;

    bool again = true;

    bool correct;

    int numberofplayers = getplayers();

    player * players = new player [ numberofplayers ];

    player dealer;

    getnames ( players, numberofplayers );

    while ( again ){

        getbets ( players, numberofplayers );

        clearscreen ();

        for ( int i = 0; i < numberofplayers; ++i ){

            for ( int j = 0; j < 5; ++j ){

                players[i].hand[j] = 0;

            }

        }

        for ( int i = 0; i < 5; ++i ){

            dealer.hand[i] = 0;

        }

        Thedeck.deal ( players, dealer.hand , numberofplayers );

        display ( players, dealer, numberofplayers );

        printbets ( players, numberofplayers );

        choice ( players, dealer, numberofplayers , Thedeck );

        if ( players[0].bet > 0 ){

            cout << endl << endl << "Would you like to play again? (Y or N)" << endl;
            cin >> endchoice;

            if( endchoice == 'Y' || endchoice == 'y' ) again = true;
            else if ( endchoice == 'N' || endchoice == 'n' ) again = false;
            else{

                cout << endl << "That is not an acceptable answer.";
                correct = false;

            }

        }

        else if ( players[0].bet <= 0 ){

            cout << endl << endl << "You ran out of money! Game over!";
            again = false;

        }

        else if ( players[1].bet <= 0 ){

            player * playerscopy = new player [ numberofplayers ];

            for ( int i = 0; i < numberofplayers; ++i ){

                playerscopy[i] = players[i];

            }

            numberofplayers -= 1;
            delete [] players;

            player * players = new player [ numberofplayers ];
            players[0] = playerscopy[0];
            players[1] = playerscopy[2];

            delete [] playerscopy;

        }

        else if ( players[2].bet <= 0 ){

            player * playerscopy = new player [ numberofplayers ];

            for ( int i = 0; i < numberofplayers; ++i ){

                playerscopy[i] = players[i];

            }

            numberofplayers -= 1;
            delete [] players;

            player * players = new player [ numberofplayers ];
            players[0] = playerscopy[0];
            players[1] = playerscopy[1];

            delete [] playerscopy;

        }

        if ( numberofplayers == 0 ) again = false;

    }






system ("PAUSE");
return 0;
}

void rules(){

    bool correct = false;
    char choice;

    while ( !correct ){

        cout << endl << "Would you like to read the rules of this game? (Y or N)" << endl;
        cin >> choice;

        if ( choice == 'Y' || choice == 'y' ){

            cout << endl << endl << "This is Blackjack. To start, you and the others at your table will" << endl
                 << "place bets. Everyone at the table will be dealt a starting hand of 2 cards," << endl
                 << "one face up and the other face down. You add the total values of these cards up." << endl
                 << "You then get to decide whether or not to 'hit' (get dealt another card) " << endl
                 << "or 'stay' (accept the total of your cards) to try and get as close to 21 " << endl
                 << "as possible without going over. If it is your first choice on whether to hit" << endl
                 << "or stay you may also choose to 'double down', where your bet will double and" << endl
                 << "you will hit one card and be forced to stand after. " << endl << endl <<
                    "If you get close to 21 than the dealer, you win! If you get " << endl <<
                    "exactly 21 and the dealer doesn't, you win twice your bet." << endl <<
                    "If you and the dealer tie, you are refunded your bet. " << endl <<
                    "If the dealer gets closer to 21 or if you go over 21 you lose your bet." << endl << endl <<
                    "Aces can be worth either 1 or 11, and all face cards are worth 10. The dealer" << endl <<
                    "must hit if his cards are worth less than 17. Now get winning!" << endl;

            return;

        }

        else if ( choice == 'N' || choice == 'n' ) return;

        else{

            cout << endl << "That is not an acceptable responce.";

        }

    }

}

int getplayers(){

    bool correct = false;
    int number;

    while ( !correct ){

        cout << endl << endl << "How many players would you like to play with? ( 1 or 2 )" << endl;
        cin >> number;


            if ( number < 1 || number > 2 ){
                cout << endl << endl << "That is not an acceptable number." << endl;
                correct = false;
            }
            else correct = true;
    }
    return number + 1;
}

void getnames( player* players , int numberofplayers ){

    bool correct;

    cout << endl << endl << "Please enter the name of each other player.\nAll names must be shorter than 10 characters and not contain spaces." << endl;

    for ( int i = 0; i < numberofplayers; ++i ){

        correct = false;

        do{

            if ( i == 0 ){

                cout << "Your name: ";
                cin >> players [i].name;

            }

            else{

                cout << "Player " << i + 1 << ": ";
                cin >> players [i].name;

            }

            if( players[i].name.length() > 10){
                cout << endl << endl << "That name is too long." << endl;

            }

            else{

                cout << endl;
                players [i].money = 100;
                correct = true;

            }


        }while ( !correct );

    }

}

void getbets ( player *players, int numberofplayers ){

    bool correct = false;

    while ( !correct ){

        cout << endl << endl << "You have $" << players[0].money << " to bet." << endl;
        cout << "How much would you like to bet? (Please enter a whole number) " << endl << "$";
        cin >> players[0].bet;

        if ( players[0].bet > players[0].money || players[0].bet < 0 ){

            cout << endl << "You can't bet that much.";

        }

        else correct = true;

    }

    for(int i = 1; i < numberofplayers; ++i){

        float percent;

        if(players[i].money <= 30){

            percent = ( rand() % (100 - 25) + 25 );
            percent /= 100;
            players [i].bet = players[i].money * percent;

        }

        else if(players[i].money > 30){

            percent = ( rand() % (75 - 25) + 25 );
            percent /= 100;
            players[i].bet = players[i].money * percent;

        }

    }

}

void printbets(player *players, int numberofplayers ){

    for( int i = 0; i < numberofplayers; ++i){

        cout << players[i].name << ": money = $" << players[i].money << ", bet = $" << players[i].bet << endl;


    }
}

void display( player * players, player dealer , int number ){
    clearscreen();
    if( number == 1 ){
        cout << endl << endl << "          ____________________                    ____________________";
        cout << endl <<         "         |                    |                  |                    |";
        cout << endl <<         "         |                    |                  |                    |";
        cout << endl <<         "         |                    |                  |                    |";
        cout << endl <<         "         |                    |      DEALER      |                    |";
        cout << endl <<         "         |                    |";
        showHandTop ( players, dealer, -1 );
        cout << "|                    |";
        cout << endl <<         "         |                    |                  |                    |";
        cout << endl <<         "         |                    |                  |                    |";
        cout << endl <<         "          \\                    \\                /                    /";
        cout << endl <<         "           \\                    \\              /                    /";
        cout << endl <<         "            \\                    \\            /                    /";
        cout << endl <<         "             \\                    \\          /                    /";
        cout << endl <<         "              \\                    \\________/                    /";
        cout << endl <<         "               \\                    " << players[0].name;
        for( int i = 0; i < 10 - players[0].name.length(); ++i) cout << " ";
        cout << "                  / ";
        cout << endl <<         "                \\                    ";
        showHandTop( players, dealer, 0 );
        cout << "      /";
        cout << endl <<         "                 \\                   ";
        showHandMid( players, dealer, 0 );
        cout << "     /";
        cout << endl <<         "                  \\                  ";
        showHandBot( players, dealer, 0 );
        cout << "    /";
        cout << endl <<         "                   \\________________________________________/" << endl;
    }

    else if( number == 2 ){
        cout << endl << endl << "          ____________________                    ____________________";
        cout << endl <<         "         |                    |                  |                    |";
        cout << endl <<         "         |        " << players[1].name;
        for( int i = 0; i < 10 - players[1].name.length(); ++i) cout << " ";
        cout << "  |                  |                    |";
        cout << endl <<         "         |";
        showHandTop( players, dealer, 1 );
        cout << "|                  |                    |";
        cout << endl <<         "         |";
        showHandMid( players, dealer, 1 );
        cout << "|      DEALER      |                    |";
        cout << endl <<         "         |";
        showHandBot( players, dealer, 1 );
        cout << "|";
        showHandTop ( players, dealer, -1 );
        cout << "  |                    |";
        cout << endl <<         "         |                    |";
        showHandMid( players, dealer, -1 );
        cout << "  |                    |";
        cout << endl <<         "         |                    |";
        showHandBot( players, dealer, -1 );
        cout << "  |                    |";
        cout << endl <<         "          \\                    \\                /                    /";
        cout << endl <<         "           \\                    \\              /                    /";
        cout << endl <<         "            \\                    \\            /                    /";
        cout << endl <<         "             \\                    \\          /                    /";
        cout << endl <<         "              \\                    \\________/                    /";
        cout << endl <<         "               \\                    " << players[0].name;
        for( int i = 0; i < 10 - players[0].name.length(); ++i) cout << " ";
        cout << "                  / ";
        cout << endl <<         "                \\                    ";
        showHandTop( players, dealer, 0 );
        cout << "      /";
        cout << endl <<         "                 \\                   ";
        showHandMid( players, dealer, 0);
        cout << "     /";
        cout << endl <<         "                  \\                  ";
        showHandBot( players, dealer, 0);
        cout << "    /";
        cout << endl <<         "                   \\________________________________________/" << endl;
    }

    else if( number == 3 ){
        cout << endl << endl << "          ____________________                    ____________________";
        cout << endl <<         "         |                    |                  |                    |";
        cout << endl <<         "         |     " << players[1].name;
        for( int i = 0; i < 10 - players[1].name.length(); ++i) cout << " ";
        cout <<                 "     |                  |     " << players[2].name;
        for( int i = 0; i < 10 - players[2].name.length(); ++i) cout << " ";
        cout <<                 "     |";
        cout << endl <<         "         |";
        showHandTop( players, dealer, 1 );
        cout << "|                  |";
        showHandTop( players, dealer, 2 );
        cout << "|";
        cout << endl <<         "         |";
        showHandMid( players, dealer,  1 );
        cout << "|      DEALER      |";
        showHandMid( players, dealer, 2 );
        cout << "|";
        cout << endl <<         "         |";
        showHandBot( players, dealer, 1 );
        cout << "|";
        showHandTop( players, dealer, -1 );
        cout << "  |";
        showHandBot( players, dealer, 2 );
        cout << "|";
        cout << endl <<         "         |                    |";
        showHandMid( players, dealer, -1 );
        cout << "  |                    |";
        cout << endl <<         "         |                    |";
        showHandBot( players, dealer, -1 );
        cout << "  |                    |";
        cout << endl <<         "          \\                    \\                /                    /";
        cout << endl <<         "           \\                    \\              /                    /";
        cout << endl <<         "            \\                    \\            /                    /";
        cout << endl <<         "             \\                    \\          /                    /";
        cout << endl <<         "              \\                    \\________/                    /";
        cout << endl <<         "               \\                    " << players[0].name;
        for( int i = 0; i < 10 - players[0].name.length(); ++i) cout << " ";
        cout << "                  / ";
        cout << endl <<         "                \\                    ";
        showHandTop( players, dealer, 0 );
        cout << "      /";
        cout << endl <<         "                 \\                   ";
        showHandMid( players, dealer, 0);
        cout << "     /";
        cout << endl <<         "                  \\                  ";
        showHandBot( players, dealer, 0);
        cout << "    /";
        cout << endl <<         "                   \\________________________________________/" << endl;
    }

}

void showHandTop(player *players, player dealer,  int n){
    int handcount = 0;

    if ( n > -1 ){
        for( int i = 0; i < 5; ++i ){
            if( players[n].hand[i] > 0 ) handcount += 1;
        }
        for( int i = 1; i <= 5; ++i ){
            if( i <= handcount  ) cout << " __ ";
        }
        for( int i = 0; i < 5 - handcount; ++i ){
            cout << "    ";
        }
    }

    else if ( n == -1 ){

        for( int i = 0; i < 4; ++i ){

            if( dealer.hand[i] > 0 ) handcount += 1;

        }

        for( int i = 1; i <= 4; ++i ){

            if( i <= handcount  ) cout << " __ ";

        }

        for( int i = 0; i < 4 - handcount; ++i ){

            cout << "    ";
        }

    }

}

void showHandMid(player *players, player dealer, int n){

    int handcount = 0;

    if ( n > -1 ){
        for( int i = 0; i < 5; ++i ){
            if( players[n].hand[i] > 0 ) handcount += 1;
        }
        for( int i = 0; i < 5; ++i ){
            if( n == 0 ){
                if( i <= handcount - 1 ){
                        cout << "|";
                        if( players[n].hand[i] < 10 && players[n].hand[i] > 1 ) cout << " " << players[n].hand[i] << "|";

                        else if( players[n].hand[i] == 1 ) cout << " A|";
                        else if( players[n].hand[i] == 10 ) cout << "10|";
                        else if( players[n].hand[i] == 11 ) cout << " J|";
                        else if( players[n].hand[i] == 12 ) cout << " Q|";
                        else if( players[n].hand[i] == 13 ) cout << " K|";
                    }
                }
            else{
                if( i <= handcount - 1 && i == 0 ) cout << "|  |";
                else if( i <= handcount - 1 && i != 0 ){
                        cout << "|";
                        if( players[n].hand[i] < 10 && players[n].hand[i] > 1 ) cout << " " << players[n].hand[i] << "|";

                        else if( players[n].hand[i] == 1 ) cout << " A|";
                        else if( players[n].hand[i] == 10 ) cout << "10|";
                        else if( players[n].hand[i] == 11 ) cout << " J|";
                        else if( players[n].hand[i] == 12 ) cout << " Q|";
                        else if( players[n].hand[i] == 13 ) cout << " K|";
                }
            }
        }
        for( int i = 0; i < 5 - handcount; ++i ){
            cout << "    ";
        }
    }

    else if ( n == -1 ){

        for( int i = 0; i < 4; ++i ){
            if( dealer.hand[i] > 0 ) handcount += 1;
        }
        for( int i = 0; i < 4; ++i ){
            if( n == 0 ){
                if( i <= handcount - 1 ){
                        cout << "|";
                        if( dealer.hand[i] < 10 && dealer.hand[i] > 1 ) cout << " " << dealer.hand[i] << "|";

                        else if( dealer.hand[i] == 1 ) cout << " A|";
                        else if( dealer.hand[i] == 10 ) cout << "10|";
                        else if( dealer.hand[i] == 11 ) cout << " J|";
                        else if( dealer.hand[i] == 12 ) cout << " Q|";
                        else if( dealer.hand[i] == 13 ) cout << " K|";
                    }
                }
            else{
                if( i <= handcount - 1 && i == 0 ) cout << "|  |";
                else if( i <= handcount - 1 && i != 0 ){
                        cout << "|";
                        if(dealer.hand[i] < 10 && dealer.hand[i] > 1 ) cout << " " << dealer.hand[i] << "|";

                        else if( dealer.hand[i] == 1 ) cout << " A|";
                        else if( dealer.hand[i] == 10 ) cout << "10|";
                        else if( dealer.hand[i] == 11 ) cout << " J|";
                        else if( dealer.hand[i] == 12 ) cout << " Q|";
                        else if( dealer.hand[i] == 13 ) cout << " K|";
                }
            }
        }
        for( int i = 0; i < 4 - handcount; ++i ){
            cout << "    ";
        }
    }

}


void showHandBot(player *players, player dealer,  int n){
    int handcount = 0;

    if ( n > -1 ){
        for( int i = 0; i < 5; ++i ){
            if( players[n].hand[i] > 0 ) handcount += 1;
        }
        for( int i = 1; i <= 5; ++i ){
            if( i <= handcount  ) cout << "|__|";
        }
        for( int i = 0; i < 5 - handcount; ++i ){
            cout << "    ";
        }
    }

    else if ( n == -1 ){

        for( int i = 0; i < 4; ++i ){
            if( dealer.hand[i] > 0 ) handcount += 1;
        }
        for( int i = 1; i <= 4; ++i ){
            if( i <= handcount  ) cout << "|__|";
        }
        for( int i = 0; i < 4 - handcount; ++i ){
            cout << "    ";
        }

    }

}

void clearscreen(){
    for(int i = 0; i < 25; ++i) cout << endl;
}

void choice ( player *players , player dealer, int numberofplayers , Deck Thedeck ){

    bool correct = false;

    char choice;

    bool choiceok = false;

    for ( int i = 0; i < numberofplayers; ++i ){

         players[i].handtotal = 0;

        for ( int j = 0; j < 5; ++j ){

            if ( players [i].hand [j] > 10 ) players[i].handtotal += 10;

            else if ( players [i].hand [j] > 1 && players [i].hand [j] < 11 )  players[i].handtotal += players [i].hand[j];

            else if ( players [i].hand [j] == 1 ){

                if ( i == 0 ) players[i].handtotal += acechoice();

                else{

                    if ( players[i].handtotal <= 10 && players[i].handtotal >= 8 ) players[i].handtotal += 11;
                    else players[i].handtotal += 1;

                }


            }

        }

        if ( players[i].handtotal < 21 && i == 0 ){

            if ( i == 0 ){

                correct = false;

                bool firstchoice;

                while ( !correct ){

                    if ( players [i].hand[2] == 0
                      && players [i].hand[3] == 0
                      && players [i].hand[4] == 0){

                        firstchoice = true;

                    }

                    else firstchoice = false;

                    if ( firstchoice && players[i].bet * 2 <= players[i].money ){

                        cout << endl << endl << "Would you like to hit, stand or double down?\n( Enter either H, S, or D respectively to make your choice) " << endl;

                        cin >> choice;

                        if ( choice != 'H' && choice != 'h' &&
                             choice != 'S' && choice != 's' &&
                             choice != 'D' && choice != 'd' ){

                            cout << endl << endl << "That is not an acceptable choice.";

                            correct = false;

                        }

                    }

                    else if ( !firstchoice ){

                        cout << endl << endl << "Would you like to hit or stand?\n( Enter either H or S respectively to make your choice) " << endl;

                        cin >> choice;

                        if ( choice != 'H' && choice != 'h' &&
                             choice != 'S' && choice != 's' ){

                            cout << endl << endl << "That is not an acceptable choice.";

                            correct = false;

                        }

                    }

                    if ( choice == 'H' || choice == 'h' ){

                        Thedeck.hit ( players, dealer.hand , i );

                        for ( int e = 0; e < 5; ++e ){

                            if ( players [i].hand[e] == 0 ){

                                if ( players [i].hand [e-1] > 10 ) players[i].handtotal += 10;

                                else if ( players [i].hand [e-1] == 1 ) players[i].handtotal += acechoice ();

                                else players[i].handtotal += players [i].hand [e-1];

                                e += 5;

                            }

                        if ( players[i].handtotal >= 21 || players [i]. hand[4] != 0 ) correct = true;

                        }

                        display ( players , dealer,  numberofplayers );

                    }

                    else if ( choice == 'D' || choice == 'd' ){

                        Thedeck.hit ( players, dealer.hand , i );

                        for ( int e = 0; e < 5; ++e ){

                            if ( players [i].hand[e] == 0 ){

                                if ( players [i].hand [e-1] > 10 ) players[i].handtotal += 10;

                                else if ( players [i].hand [e-1] == 1 ) players[i].handtotal += acechoice ();

                                else players[i].handtotal += players [i].hand [e-1];

                                e += 5;

                            }

                        }

                        players [i].bet *= 2;
                        correct = true;


                    }



                    else if ( choice == 'S' || choice == 's' ){

                        correct = true;

                    }

                }

            }

        }

        else if ( players[i].handtotal < 21 && i == 1 ){

            correct = false;

            while ( !correct ){

                if ( players[i].handtotal <= 17 ){

                    Thedeck.hit ( players, dealer.hand , i );

                    for ( int e = 0; e < 5; ++e ){

                        if ( players [i].hand[e] == 0 ){

                            if ( players [i].hand [e-1] > 10 ) players[i].handtotal += 10;

                            else if ( players [i].hand [e-1] == 1 ){

                                if ( players[i].handtotal <= 10 && players[i].handtotal >= 8 ) players[i].handtotal += 11;
                                else players[i].handtotal += 1;

                            }

                            else players[i].handtotal += players [i].hand [e-1];

                            e += 5;

                        }

                    }

                }

                else correct = true;

            }

            display ( players , dealer, numberofplayers );

        }

        else if ( players[i].handtotal < 21 && i == 2 ){

            correct = false;

            while ( !correct ){

                if ( players[i].handtotal <= 17 ){

                    Thedeck.hit ( players, dealer.hand , i );

                    for ( int e = 0; e < 5; ++e ){

                        if ( players [i].hand[e] == 0 ){

                            if ( players [i].hand [e-1] > 10 ) players[i].handtotal += 10;

                            else if ( players [i].hand [e-1] == 1 ){

                                if ( players[i].handtotal <= 10 && players[i].handtotal >= 8 ) players[i].handtotal += 11;
                                else players[i].handtotal += 1;

                            }

                            else players[i].handtotal += players [i].hand [e-1];

                            e += 5;

                        }

                    }

                }

                else correct = true;

            }

            display ( players , dealer, numberofplayers );

        }

    }


    dealer.handtotal = 0;

    for ( int j = 0; j < 4; ++j ){

        if ( dealer.hand [j] > 10 ) dealer.handtotal += 10;

        else if ( dealer.hand [j] > 1 &&dealer.hand [j] < 11 ) dealer.handtotal += dealer.hand[j];

        else if (dealer.hand [j] == 1 ){

                if ( dealer.handtotal <= 10 && dealer.handtotal >= 8 ) dealer.handtotal += 11;
                else dealer.handtotal += 1;

        }
        cout << endl << dealer.handtotal;
    }

    if ( dealer.handtotal < 21 ){

        correct = false;

        while ( !correct ){

            if ( dealer.handtotal < 17 ){

                cout << endl << "WORKING";
                cout << endl << dealer.handtotal;

                Thedeck.hit ( players, dealer.hand , -1 );

                for ( int e = 0; e < 4; ++e ){

                    if ( dealer.hand[e] == 0 ){

                        if ( dealer.hand [e-1] > 10 ) dealer.handtotal += 10;

                        else if ( dealer.hand [e-1] == 1 ){

                            if ( dealer.handtotal <= 10 && dealer.handtotal >= 8 ) dealer.handtotal += 11;
                            else dealer.handtotal += 1;

                        }

                        else dealer.handtotal += dealer.hand [e-1];

                        e += 5;

                    }

                    if ( dealer.hand[e] != 0 ) correct = true;

                }

            }

            else correct = true;

        }

        display ( players , dealer, numberofplayers );
        cout << endl << "The dealers hand totals" << dealer.handtotal;

    }

    for( int i = 0; i < numberofplayers; ++i ){

        if ( i == 0 ){

            if ( players[i].handtotal > dealer.handtotal && players[i].handtotal < 21 ){

                cout << endl << endl << "You beat the dealer! You win $" << players[i].bet;
                players[i].money += players[i].bet;

            }

            else if ( players[i].handtotal > dealer.handtotal && players[i].handtotal == 21 ){

                cout << endl << endl << "You beat the dealer with Blackjack! You win 2x your bet!\nYou win $" << players[i].bet * 2;
                players[i].money += ( players[i].bet * 2 );

            }

            else if ( players[i].handtotal < dealer.handtotal && dealer.handtotal <= 21 ){

                cout << endl << endl << "You didn't beat the dealer. You lose $" << players[i].bet;
                players[i].money -= players[i].bet;

            }

            else if (  players[i].handtotal == dealer.handtotal && dealer.handtotal <= 21 ){

                cout << endl << endl << "You tied with the dealer. You will be refunded your bet.";

            }

            else if ( players[i].handtotal > 21 ){

                cout << endl << endl << "You bust! You lose $" << players[i].bet;
                players[i].money -= players[i].bet;

            }

        }

        else{

            if ( players[i].handtotal > dealer.handtotal && players[i].handtotal < 21 ){

                players[i].money += players[i].bet;

            }

            else if ( players[i].handtotal > dealer.handtotal && players[i].handtotal == 21 ){

                players[i].money += ( players[i].bet * 2 );

            }

            else if ( players[i].handtotal < dealer.handtotal && dealer.handtotal <= 21 ){

                players[i].money -= players[i].bet;

            }

            else if (  players[i].handtotal == dealer.handtotal && dealer.handtotal <= 21 ){

            }

            else if ( players[i].handtotal > 21 ){

                players[i].money -= players[i].bet;

            }

        }

    }

}

int acechoice (){

    int choice;
    bool correct = false;

    while ( !correct ){

        cout << endl << "Would you like your Ace to be worth 1 or 11?" << endl;

        cin >> choice;

        if ( choice != 11 && choice != 1 ) {

            cout << endl << "That is not an acceptable answer.";
            correct = false;

        }

        else correct = true;

    }

    return choice;

}
