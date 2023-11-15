#include <iostream>
#include <algorithm>
#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck() {
    char suits[] = {'s', 'h', 'd', 'c'};
    int rank = 13;

    for(int i = 0; i < 4; ++i) {
        char suit = suits[i];

        while(rank >= 1) {
            theDeck.push_back(Card(suit, rank));

            --rank;
        }

        rank = 13;
    }
}

Card Deck::dealCard() {
    if(theDeck.empty()) {
        cout << "Deck is empty." << endl;
        
        exit(1);
    }

    Card bestCard = theDeck.back();

    dealtCards.push_back(bestCard);
    theDeck.pop_back();

    return bestCard;
}

void Deck::shuffleDeck() {
    unsigned int userSize = dealtCards.size();

    for(unsigned int i = 0; i < userSize; ++i) {
        theDeck.push_back(dealtCards[i]);
    }

    dealtCards.clear();

    random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const {
    return theDeck.size();
}
