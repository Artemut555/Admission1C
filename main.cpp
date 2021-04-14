#include <iostream>
#include "Deck.h"
#include "Game.h"

int main() {
    std::cout << "Input array 8*9 where each i-string consists of card values in i-deck from lowest card to upper";
    std::vector<Deck> decks;
    for (int deck_ind = 0; deck_ind < 8; ++deck_ind) {
        std::vector<Card> deck;
        for (int card_ind = 0; card_ind < 9; ++card_ind) {
            int value;
            std::cin >> value;
            deck.emplace_back(value);
        }
        decks.emplace_back(deck);
    }

    Game game(decks);

    if (can_be_solved(game)) {
        std::cout << "Can be solved";
    } else {
        std::cout << "Can't be solved";
    }

    return 0;
}
