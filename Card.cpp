// Aleksey Leshchuk
// Simple Card class, has two sides which are assigned in the constructor
// for use in 3 card guess simulation
// CISP440

#include <string>
#include <random>
#include <exception>

#ifndef
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
	Card(const std::String& frt, const std::String& bk) {
	    if ( frt.length() > 15 || bk.length()>15 )	{	// if 
		throw overflow_exception();
	    } else {				// if both arguments are valid
		front=frt;
		back=bk;
	    }
	}
	// shuffles the side to be shown
	void shuffle() {
	    std::default_random_engine gen;	    // random number engine
	    std::uniform_int_distribution<int> distribution(1,2);	// uniform int distribution range [1,2]
	    int side = distribution(gen);

	    if (side == 1)  // if front
		face=&front;	// assign card to be shown 
	    else
		face=&back;
	}
	// show one side of the card
	const char* show() const {
	    return face->cstring.data();	// return char* data of face
	}
	// oprator== for char*
	bool operator== (const char* cstring) const {
	    if ( face->data() == cstring )	// if data() in face == cstring
		return true;
	    else
		return false;
	}
	// operator== for std::String
	bool operator== (const std::String& string) const {
	    if ( &face == string )	    // if objects are equal
		return true;
	    else 
		return false;
	}
    private:
	std::String* face;	// pointer to the card to be shown
	std::String front;
	std::String back;
};

#endif
