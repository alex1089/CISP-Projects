// Aleksey Leshchuk
// Simple Card class, has two sides which are assigned in the constructor
// for use in 3 card guess simulation
// CISP440

#include <string>
#include <random>
#include <exception>
#include <iostream>

#ifndef CARD_CPP
#define CARD_CPP

// overflow on construct exception
class overflow_exception: public std::exception {
    public:
	const char* what() {
	    return "Length of front/back overflowed. (15char)";
	}
};
class Card {
    public:
	Card(const std::string& frt, const std::string& bk) {
	    if ( frt.length() > 15 || bk.length()>15 )	{	// if 
		throw overflow_exception();
	    } else {				// if both arguments are valid
		front=frt;
		back=bk;
	    }
	}
	// shuffles the side to be shown
	void shuffle() {
	    static std::default_random_engine gen(3);	    // random number engine
	    static std::uniform_int_distribution<int> distribution(0,1);	// uniform int distribution range [1,2]
	    int side = distribution(gen);

	    if (side == 1)  // if front
		face=&front;	// assign card to be shown 
	    else 
		face=&back;
	}
	
	// show one side of the card
	const std::string show() const {
	    return *face;	// return string data of face
	}
	
	// operator== for std::string T/F if opposite side matches
	bool operator== (const std::string& str) const {
	    if ( face == &front){	// if face is the front, return opposite
		if (!back.compare(str)){	    // if string are equal
		    //std::cout<<back<<" "<<str<<std::endl;

		    return true;
		} else {
		    return false;
		}
	    } else {
		if (!front.compare(str)) {
		    //std::cout<<front<<" "<<str<<std::endl;
		    return true;
		} else {
		    return false;
		}
	    }
	}
    private:
	std::string* face;	// pointer to the card to be shown
	std::string front;
	std::string back;
};

#endif
