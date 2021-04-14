#pragma once
#ifndef INC_1C_PROJECT_DECK_H
#define INC_1C_PROJECT_DECK_H

#include <vector>
#include "Card.hpp"

class Deck {
public:
    Deck () = delete;

    Deck (const std::vector<Card>& cards);

    bool possible_to_fold () const;

    void fold ();

    bool possible_to_put (const Card& card) const;

    void put (const Card& card);

    // finds out if possible to move something from this deck to another
    bool possible_move_to (const Deck& another_deck) const;

    // can be proved if it is possible to move cards
    // from one deck to another then there is only one reasonable way
    // if another deck is empty then move as many as possible else
    // there is only one method
    void move (Deck& another_deck);

    bool empty () const;

    Card back () const;

    std::vector<Card> get_cards () const;
private:
    void open_last_card_ ();

    // finds the longest growing sequential open numbers from the end
    // returns length
    int find_most_grow_seq () const;

    //returns -1 if not any
    int find_last_pos(int val) const;

    std::vector<Card> deck_;
};
#endif //INC_1C_PROJECT_DECK_H

