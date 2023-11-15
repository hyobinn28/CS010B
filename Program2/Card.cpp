#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

Card::Card() {
    suit = 'c';
    rank = 2;
}

Card::Card(char suitInput, int rankInput) {
    suitInput = tolower(suitInput);

    if(suitInput == 'c' || suitInput == 'd' || suitInput == 'h' || suitInput == 's') {
        suit = suitInput;
    }
    else {
        suit = 'c';
    }

    if(rankInput > 13 || rankInput < 1) {
        rank = 2;
    }
    else {
        rank = rankInput;
    }
}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

ostream &operator<<(ostream& out, const Card& rhs) {
    string full;
    string ranking;

    if(rhs.rank == 1) {
        out << "Ace";
    }
    else if(rhs.rank == 11) {
        out << "Jack";
    }
    else if(rhs.rank == 12) {
        out << "Queen";
    }else if(rhs.rank == 13) {
        out << "King";
    }
    else {
        out << rhs.rank;
    }

    if(rhs.suit == 'c') {
        full = "Clubs";
    }
    else if (rhs.suit == 'd') {
        full = "Diamonds";
    }
    else if (rhs.suit == 'h') {
        full = "Hearts";
    }
    else if (rhs.suit == 's') {
        full = "Spades";
    }

    out << " of " << full;

    return out;
}
