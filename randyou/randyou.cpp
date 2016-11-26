// randyou.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void introdScr();
void casWelcome();
void tryAgain();
void introSrc_2();

class casino
{

public:        void setUserName()
{
	cout << "Enter your name : ";
	cin >> userName;
}

			   string getName()
			   {
				   return userName;
			   }

			   void setBet()
			   {
				   cout << "Enter Deposit amount to play : $";
				   cin >> bet;
			   }

			   int getBet()
			   {
				   return bet;
			   }

			   void setMoneyToBet()
			   {
				   cin >> moneyToBet;
			   }

			   int getMoneyToBet()
			   {
				   return moneyToBet;
			   }
			   void setNumberIn()
			   {
				   cin >> numberIn;
			   }
			   int getNumberIn()
			   {
				   return numberIn;
			   }

			   void guessingGame() 
			   {	
				   int randomNumber = rand() % 10 + 1;
				   cout << "Guess your number to bet between 1 to 10 :";
				   cin >> guess;
				   
				   //int win = 1;
				   //int lose = 2;

				   int quantityWonLost = moneyToBet * 10;

				   if (guess == randomNumber) 
				   {
					   cout << "Congrat you won this time!! You won: $" << quantityWonLost << endl;
					//   return win;
					   cout << "The winning number was: " << randomNumber << endl;
					   bet = bet + quantityWonLost;
					   cout << "\n" << userName << ", you have: $" << bet << endl;
				   }
				   else
				   {
					   cout << "Bad luck this time!! You lost: $" << moneyToBet << endl;
					   cout << "The winning number was: " << randomNumber << endl;
					   bet = bet - moneyToBet;
					   cout <<"\n"  << userName << ", you have: $" << bet << endl;
					   
					  // return lose;
				   }
			   }

private:
	string userName;
	int bet = 0;
	int moneyToBet = 0;
	int numberIn = 0;
	int guess = 0;
};

casino Game;

int main()
{	
	casWelcome();


	if (Game.getBet()>0)
	{
		introdScr();
	}
	else
	{
		cout << "Error try again later" << endl;
	}

	return 0;
}

//welcome screen
void casWelcome()
{
	for (int i = 0; i <= 83; i++)
	{
		cout << "-";
	}
	cout << "" << endl;
	cout << "" << endl;
	cout << "           CASINO GAME " << endl;
	cout << "" << endl;
	cout << "" << endl;

	for (int i = 0; i <= 83; i++)
	{
		cout << "-";
	}
	Game.setUserName();
	cout << "" << endl;
	cout << "" << endl;
	Game.setBet();
}

//this is the main menu screen
void introdScr()
{
	for (int i = 0; i <= 83; i++)
	{
		cout << "-";
	}

	cout << "               RULES OF THE GAME" << endl;

	for (int i = 0; i <= 83; i++)
	{
		cout << "-";
	}

	cout << "" << endl;
	cout << "1. Choose any number between 1 to 10" << endl;
	cout << "2. If you win you will get 10 times of money you bet" << endl;
	cout << "3. If you bet on wrong number you will lose your betting amount" << endl;
	cout << "" << endl;
	for (int j = 0; j <= 83; j++)
	{
		cout << "-";
	}
	cout << "" << endl;
	cout << "" << endl;

	cout << "Your current balance is: $ " << Game.getBet() << endl;
	cout << Game.getName() << ", enter money to bet : $";
	Game.setMoneyToBet();

	if (Game.getMoneyToBet() > Game.getBet()) 
	{
		cout << "Not enough credit" << endl;
		cout << Game.getName() << ", enter money to bet : $";
		Game.setMoneyToBet();
	}
	else 
	{
		Game.guessingGame();
	}
	 
	tryAgain();
	
}

void tryAgain() 
{
	string yesNo;

	cout << "Do you wish to continue?(y/n) : ";
	cin >> yesNo;

	if ((yesNo == "y") || (yesNo == "Y"))
	{
		introSrc_2();
		tryAgain();
	}
	else
	{
		cout << "Thanks for playing!" << endl;
		cout << Game.getName() << ", you left with:" << Game.getBet() << endl;
	}

}

void introSrc_2() 
{
	cout << "Your current balance is: $ " << Game.getBet() << endl;
	cout << Game.getName() << ", enter money to bet : $";
	Game.setMoneyToBet();

	if (Game.getMoneyToBet() > Game.getBet())
	{
		cout << "Not enough credit" << endl;
		cout << Game.getName() << ", enter money to bet : $";
		Game.setMoneyToBet();
	}
	else
	{
		Game.guessingGame();
	}
}