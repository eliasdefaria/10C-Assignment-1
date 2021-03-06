#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"

using namespace std;

int main(){
   /* --STATEMENTS-- */
   srand((int)time(0));

   Player player;
   Player dealer(900);
   int gamecount = 1;

   //Initialize text log file
   ofstream fout;
   fout.open("gamelog.txt");

   while(player.get_money() > 0 && dealer.get_money() > 0){ //Ends game when player runs out of money
     fout << "----------------------------------------------\n\n";
     bool playerWin, invalidBet = true, validHit = true, dealerHit = true, tie = false;
     int bet;
     string playerResponse;
     fout << "Game Number: " << gamecount << "\t\t\t\t\tMoney Left: " << player.get_money() << endl;
     while(invalidBet){
       cout << "You have " << player.get_money() << ". Enter your bet: ";
       cin >> bet;

       if(bet <= player.get_money()){
         invalidBet = false;
       }

     }

     fout << "Bet: " << bet << endl;

     Hand playerHand, dealerHand; //Initializes new hands for player and dealer

     //Player card drawing
     while(validHit){
       cout << "\nYour cards: \n";
       for(int i = 0; i < playerHand.get_cards().size(); i++){
         cout << "\t" << playerHand.get_cards()[i].get_spanish_rank() << " of " << playerHand.get_cards()[i].get_spanish_suit() << endl;
       }

       if (playerHand.get_bust()){
         cout << "\nYou busted!\n" << endl;
         validHit = false;
       }
       else{
         cout << "\nYour total is " << playerHand.get_value() << ". Do you want another card? (y/n)";
         cin >> playerResponse;

         if((playerResponse == "y" || playerResponse == "Y" || playerResponse == "yes" || playerResponse == "Yes") && playerHand.get_value() <= 7.5){
           playerHand.hit();
         }
         else{
           validHit = false;
         }
       }
     }

     //Dealer card drawing
     while(dealerHit){
       cout << "\nDealer's cards: \n";
       for(int i = 0; i < dealerHand.get_cards().size(); i++){
         cout << "\t" << dealerHand.get_cards()[i].get_spanish_rank() << " of " << dealerHand.get_cards()[i].get_spanish_suit() << endl;
       }

       if (dealerHand.get_bust()){
         cout << "\nDealer busted!\n" << endl;
         dealerHit = false;
       }
       else{
         cout << "\nDealer's total is " << dealerHand.get_value() << "." << endl;
         if(dealerHand.get_value() <= 5.5){
           cout << "Dealer hits!\n" << endl;
           dealerHand.hit();
         }
         else{
           dealerHit = false;
         }
       }
     }

     //Comparisons to decide winner of game
     if (playerHand.get_bust() || dealerHand.get_bust()){
       if((playerHand.get_bust() && !dealerHand.get_bust()) || (playerHand.get_bust() && dealerHand.get_bust())){
         playerWin = false;
       }
       else if(!playerHand.get_bust() && dealerHand.get_bust()){
         playerWin = true;
       }

     }
    else{
      if(playerHand.get_value() > dealerHand.get_value()){
        playerWin = true;
      }
      else if(playerHand.get_value() < dealerHand.get_value()){
        playerWin = false;
      }
      else{
        tie = true;
      }
    }

    //Display winner change bet value accordingly
    if(playerWin && !tie){
      cout << "You won! Great job!\n" << endl;
      player.change_money(bet);
      dealer.change_money((-1*bet));
    }
    else if (!playerWin && !tie){
      cout << "Dealer wins!\n" << endl;
      dealer.change_money(bet);
      player.change_money((-1*bet));
    }
    else{
      cout << "It's a tie!\n" << endl;
    }


    /**********************************
          OUTPUT FOR GAMELOG.TXT
    ***********************************/
    fout << "\nYour cards: \n";
    for(int i = 0; i < playerHand.get_cards().size(); i++){
      fout << "\t" << playerHand.get_cards()[i].get_spanish_rank() << " of " << playerHand.get_cards()[i].get_spanish_suit() << endl;
    }
    fout << "\nYour total is " << playerHand.get_value() << endl << endl;
    fout << "\nDealer's cards: \n";
    for(int i = 0; i < dealerHand.get_cards().size(); i++){
      fout << "\t" << dealerHand.get_cards()[i].get_spanish_rank() << " of " << dealerHand.get_cards()[i].get_spanish_suit() << endl;
    }
    fout << "\nDealer's total is " << dealerHand.get_value() << "." << endl;
    //Incremements game count to keep track of how many games have been played
    gamecount++;
  }

  //Output when player or dealer loses
  if(player.get_money() > 0){
    cout << "You took all the dealers cash! Way to go, you beat the casino! \n\n Goodbye now! \n";
  }

  else{
    cout << "The casino took all your money! Come back with more cash to play again! \n\n Goodbye! \n";
  }
  fout.close();
  return 0;
}
