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
   //while(player.get_money() > 0){ //Ends game when player runs out of money
     bool playerWin, dealerWin;
     int bet;
     bool invalidBet = true;

     while(invalidBet){
       cout << "How much would you like to bet? ";
       cin >> bet;

       if(bet <= player.get_money()){
         invalidBet = false;
       }

     }

     Hand playerHand, dealerHand; //Initializes new hands for player and dealer
     cout << "Your cards: \n\t" << playerHand.get_card(1).get_spanish_rank() << " of " << playerHand.get_card(1).get_spanish_suit();

     /*
     if (playerHand.get_bust() || dealerHand().get_bust()){
       if((playerHand.get_bust() && !dealerHand.get_bust()) || (playerHand.get_bust() && dealerHand.get_bust()){
         playerWin = false;
         dealerWin = true;
       }
       else if(!playerHand.get_bust() && dealerHand.get_bust()){
         playerWin = true;
         dealerWin = false;
       }
       else{

       }
     }
   }*/




/*
   cout << firstHand.get_value() << endl;
   firstHand.hit();
   cout << firstHand.get_value() << endl;
   if(firstHand.get_bust()){
     cout << "Game over!" << endl;
   }*/
   return 0;
}
