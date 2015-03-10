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
	ThreeCard(const int& X=10000):
	    white("white"),
	    black("black")
	{	    // run X simulations
	    char exitvar;
	    // initialize data members
	    init();
	    // run simulation X times
	    simulate(X);
	    printResults();
	    std::cout<<"By Aleksey Leshchuk. PRESS ANY ENTER TO QUIT... ";
	    std::cin.get(exitvar);
	}
	~ThreeCard() {	//	destructor deallocates allocated Card objects
	    for (Card* i: deck_of_cards)
		delete i;
	}
	void printResults() const {
	    // TODO: print results of the simulation
	    for (int i=0;i<6;i++){
		switch (i) {
		    case 0:
			std::cout<<"OPPOSITE COLOR: ";
			break;
		    case 1:
			std::cout<<"SAME COLOR: ";
			break;
		    case 2:
			std::cout<<"WHITE: ";
			break;
		    case 3:
			std::cout<<"BLACK: ";
			break;
		    case 4:
			std::cout<<"ALTERNATE COLOR: ";
			break;
		    case 5:
			std::cout<<"RANDOM COLOR: ";
			break;
		}
	    std::cout<<std::endl<<std::setw(22)<<static_cast<double>(stats[i])/10000*100<<"%"<<std::endl;
	    }
	}
    private:
	// simulate for x guess
	void simulate(const int& x) {
	    // TODO: simulate guess
	    std::uniform_int_distribution<int> distr(0,2); // distribut random in range of [0,2] for random card choice
	    std::default_random_engine gen(2);		    // random number engine
	    int shuffle;				    // random card picked

	    for (int i=0; i<x ; i++) { // run x guess
		shuffle = distr(gen);	    // choose a random card
		deck_of_cards[shuffle]->shuffle();	// shuffle the side to be displayed for guess
		if (guessOpposite(deck_of_cards[shuffle]))   // if guessed correctly
		    stats[OPPOSITE]++;		    // increment stat for correct guess
		if (guessSame(deck_of_cards[shuffle]))
		    stats[SAME]++;
		if (guessWhite(deck_of_cards[shuffle]))
		    stats[WHITE]++;
		if (guessBlack(deck_of_cards[shuffle]))
		    stats[BLACK]++;
		if (guessAlterante(deck_of_cards[shuffle]))
		    stats[ALTERNATE]++;
		if (guessRandom(deck_of_cards[shuffle]))
		    stats[RANDOM]++;
	    }
	    

	}
    
	// guess the opposite color
	bool guessOpposite(const Card * card) const {
	    if (card->show().compare(black) == 0)
		return *card == white;
	    else
		return *card == black;
	}

	// guess the same color
	bool guessSame(const Card * card) const {
	    if (card->show().compare(black) == 0)
		return *card == black;
	    else 
		return *card == white;
	}

	// Guesses always WHITE
	bool guessWhite( const Card* card) const {
	    return *card == white;
	}

	// Guess always BLACK 
	bool guessBlack( const Card* card) const {
	    return *card == black;
	}
	// alternate guesses, BLACK/WHITE
	bool guessAlterante(const Card* card) const {
	    static int last_color = 0;	    // tracks color of the last guessed color, 0 white, 1 black
	    if (last_color == 0){
		last_color = 1;
		return *card == white;
	    } else {
		last_color = 0;
		return *card == black;
	    }
	}
	// guess randomly
	bool guessRandom(const Card* card) const {
	    static std::uniform_int_distribution<int> distr(0,1);
	    static std::default_random_engine gen(5);
	    int rand=distr(gen);
	    if (rand == 1)
		return *card == black;
	    else 
		return *card == white;
	}
	// inititalize all stat variables
	void init() {
	    // allocate/initialize three cards 
	    deck_of_cards[0] = new Card("white","white");
	    deck_of_cards[1] = new Card("black","black");
	    deck_of_cards[2] = new Card("white","black");
	    // initalize stats array to 0s
	    for (int& i: stats)
		i=0;
	}
	Card *deck_of_cards[3];		    // array of Cards
	int stats[6];			    // stat array of correct guesses by each of the techniques
	const std::string white;
	const std::string black;
};
#endif	
