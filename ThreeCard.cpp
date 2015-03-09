// Aleksey Leshchuk
// 3 Card Guessing Game Simulation
// Simulates three cards. One that is black on both sides. One white on both side. And last, which is black on one side and white on the other.
// Uses 6 guessing techniques to simulate which would have highest odds of guessing the right color
// CISP440

#include <iostream>
#include <iomanip>	// cout/cin formatting
#include <random>
#include "Card.cpp"
#ifndef THREECARD_CPP
#define THREECARD_CPP

// enum for stat array for each guessing method
enum GuessResults { OPPOSITE, SAME, WHITE, BLACK, ALTERNATE, RANDOM};
class ThreeCard {
    public:
	ThreeCard(const int& X=10000){	    // run X simulations
	    // initialize data members
	    init();
	    // run simulation X times
	    simulate(X);
	    printResults();
	}
	~ThreeCard() {	//	destructor deallocates allocated Card objects
	    for (Card& i: deck_of_cards)
		delete i;
	}
	void printResults() const {
	    // TODO: print results of the simulation
	    std::cout<<"this is a test\n";
	}
    private:
	// simulate for x guess
	void simulate(const int& x) {
	    // TODO: simulate guess
	}
    
	// guess the opposite color
	bool guessOpposite(const Card & card) const {
	    // TODO: guess opposite color
	}
	// guess the same color
	bool guessSame(const Card & card) const {
	    // TODO: guess same color 
	}
	// Guesses always WHITE
	bool guessWhite( const Card& card) const {
	    // TODO: guess always white
	}
	// Guess always BLACK 
	bool guessBlack( const Card& card) const {
	    // TODO: guess black
	}
	// alternate guesses, BLACK/WHITE
	bool guessAlterante(const Card& card) const {
	    // TODO: alterante guesses
	}
	// guess randomly
	bool guessRandom(const Card& card) const {
	    // TODO: guess random color
	}
	// inititalize all stat variables
	void init() {
	    // allocate/initialize three cards 
	    deck_of_cards[0] = new Card("white","white");
	    deck_of_cards[1] = new Card("black","black");
	    deck_of_cards[2] = new Card("black","white");
	    // initalize stats array to 0s
	    for (int& i: stats)
		i=0;
	}
	Card *deck_of_cards[3];		    // array of Cards
	int stats[6];			    // stat array of correct guesses by each of the techniques
};
#endif	
