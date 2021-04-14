#include "Deck.h"
const int highest_card = 14;
const int lowest_card = 6;
const int full_deck_size = 9;

Deck::Deck (const std::vector<Card>& cards) : deck_(cards) {
    assert(cards.size() == 9);
    open_last_card_();
}

bool Deck::possible_to_fold () const {
    return find_most_grow_seq() == full_deck_size;
}

void Deck::fold () {
    assert(possible_to_fold());
    for (int cnt = 0; cnt < full_deck_size; ++cnt) {
        deck_.pop_back();
    }

    if (!deck_.empty()) {
        deck_.back().open();
    }
}

bool Deck::possible_to_put (const Card& card) const {
    if (deck_.empty())
        return true;

    return deck_.back().get_value() - 1 == card.get_value();
}

void Deck::put (const Card& card) {
    assert(possible_to_put(card));
    deck_.push_back(card);
}

// finds out if possible to move something from this deck to another
bool Deck::possible_move_to (const Deck& another_deck) const {
    if (empty())
        return false;

    if (another_deck.empty())
        return true;

    Card last_card = another_deck.back();
    int to_move = last_card.get_value() - 1;
    int wanted_pos = find_last_pos(to_move);
    if (wanted_pos == -1)
        return false;


    int seq_started_pos = deck_.size() - find_most_grow_seq();
    if (seq_started_pos > wanted_pos)
        return false;

    return wanted_pos - seq_started_pos < another_deck.find_most_grow_seq();
}

void Deck::move (Deck& another_deck) {
    int wanted_pos;
    if (another_deck.empty()) {
        int len = find_most_grow_seq();
        wanted_pos = deck_.size() - len;
    } else {
        wanted_pos = find_last_pos(another_deck.back().get_value() - 1);
    }

    std::vector<Card> to_move;
    while (deck_.size() != wanted_pos) {
        to_move.push_back(deck_.back());
        deck_.pop_back();
    }

    while (!to_move.empty()) {
        another_deck.put(to_move.back());
        to_move.pop_back();
    }

    open_last_card_();
}

bool Deck::empty () const {
    return deck_.empty();
}

Card Deck::back () const {
    return deck_.back();
}

std::vector<Card> Deck::get_cards () const {
    return deck_;
}

void Deck::open_last_card_ () {
    if (!deck_.empty()) {
        deck_.back().open();
    }
}

int Deck::find_most_grow_seq () const {
    if (deck_.empty())
        return 0;

    int seq_len = 1;
    for (int pos = deck_.size() - 2; pos >= 0; --pos) {
        if (deck_[pos].get_value() != deck_[pos + 1].get_value() + 1)
            break;

        if (!deck_[pos].opened())
            break;

        ++seq_len;
    }
    return seq_len;
}

int Deck::find_last_pos(int val) const {
    int pos = -1;
    for (int i = 0; i < deck_.size(); ++i) {
        if (deck_[i].get_value() == val && deck_[i].opened())
            pos = i;
    }

    return pos;
}
