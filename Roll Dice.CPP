#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>


int rollDice() {
    return rand() % 6 + 1; // Generates a random number between 1 and 6
}

void main() {
clrscr();
    srand(time(0)); // Seed the random number generator

    int playerMoney = 100; // Initial amount of money for the player

    cout << "Welcome to the Dice Rolling Game!" << endl;

    while (playerMoney > 0) {
	cout << "You have $" << playerMoney << ". \nEnter your bet amount(0 to quit): ";
	int bet;
	cin >> bet;

	// Quit the game if the player enters 0 as the bet
	if (bet == 0) {
	    break;
	}

	// Check if the bet is valid
	if (bet > playerMoney) {
	    cout << "You don't have enough money to place that bet. Try again." << endl;
	    continue;
	}

	int dice1 = rollDice();
	int dice2 = rollDice();
	int sum = dice1 + dice2;

	cout << "You rolled a " << dice1 << " and a " << dice2 << ". The sum is " << sum << "." << endl;

	// Win conditions
	if (sum == 7 || sum == 11) {
	    cout << "Congratulations! You win $" << bet << "!" << endl;
	    playerMoney += bet;
	} else {
	    cout << "Sorry, you lose $" << bet << "." << endl;
	    playerMoney -= bet;
	}

	cout << endl;
    }

    cout << "Thank you for playing! You ended the game with $" << playerMoney << "." << endl;

    getch();
}