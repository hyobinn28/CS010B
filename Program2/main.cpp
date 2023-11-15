#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Deck.h"
#include "Card.h"

using namespace std;

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand) {
    for(unsigned int i = 0; i < hand.size(); ++i) {
        for(unsigned int j = i + 1; j < hand.size(); ++j) {
            if(hand[i].getRank() == hand[j].getRank()) {
                return true;
            }
        }
    }

    return false;           //when there is no pair
}

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &out, const vector<Card> &hand) {
    for(unsigned int i = 0; i < hand.size(); ++i) {
        out << hand[i];

        if(i < hand.size() - 1) {
            out << ", ";
        }
    }

    return out;
}

int main() {
    srand(2222);

    ofstream output;
    string choice;
    string filename;

    int countCards = 0;
    int countSimul = 0;
    int countPairs = 0;

    Deck decks;
    vector<Card> hand;

    cout << "Do you want to output all hands to a file? (Yes/No) "; 
    cin >> choice;

    bool userChoice = (choice == "Yes" || choice == "yes");

    if(userChoice) {
        cout << "Enter name of output file: ";
        cin >> filename;
        output.open(filename);

        if(!output.is_open()) {
            cout << "Error opening" << endl;

            return 1;
        }
    }

    cout << "Enter number of cards per hand: ";
    cin >> countCards;

    cout << "Enter number of deals(simulations): ";
    cin >> countSimul;

    for(int i = 0; i < countSimul; ++i) {
        decks.shuffleDeck();
        hand.clear();

        for(int j = 0; j < countCards; ++j) {
            hand.push_back(decks.dealCard());
        }

        if(hasPair(hand)) {
            ++countPairs;

            if(output) {
                output << "Found Pair!! ";
            }
        }
        else if(output) {
            output << "             ";
        }
        if(output) {
            output << hand << endl;
        }
    }

    double percentage = (static_cast<double>(countPairs)/countSimul) * 100;

    if(userChoice) {
        output.close();
    }

    cout << "Chances of receiving a pair in a hand of " << countCards << " cards is: " << percentage << "%" << endl;

    return 0;
}