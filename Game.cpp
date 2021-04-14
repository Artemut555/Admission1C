#include "Game.h"
#include "iostream"

const int place_cnt = 8;

Game::Game (const std::vector<Deck>& decks) : decks_(decks) {
    assert(decks.size() == 8);
};

bool Game::has_no_moves() const {
    for (int i = 0; i < place_cnt; ++i) {
        if (decks_[i].possible_to_fold())
            return false;
    }

    for (int i = 0; i < place_cnt; ++i) {
        for (int j = 0; j < place_cnt; ++j) {
            if (i == j) {
                continue;
            }

            if (decks_[i].possible_move_to(decks_[j])) {
                return false;
            }
        }
    }
    return true;
}

bool can_be_solved(Game game) {
    return !game.has_no_moves();
}


