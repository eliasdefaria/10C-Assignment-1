#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main(){
   /* --STATEMENTS-- */
   srand((int)time(0));

   Player player;
   while(player.get_money() > 0){ //Ends game when player runs out of money
     int bet;
     bool invalidBet = true;

     while(invalidBet){
       cout << "How much would you like to bet? ";
       cin >> bet;

       if(bet <= player.get_money()){
         invalidBet = false;
       }

     }

     Hand playerHand, dealerHand; //Initializes new hands for player and dealer.
   }




/*
   cout << firstHand.get_value() << endl;
   firstHand.hit();
   cout << firstHand.get_value() << endl;
   if(firstHand.get_bust()){
     cout << "Game over!" << endl;
   }*/
   return 0;
}
