#ifndef INC_1C_PROJECT_GAME_H
#define INC_1C_PROJECT_GAME_H

#include "Deck.h"

class Game {
public:
    Game () = delete;

    explicit Game (const std::vector<Deck>& decks);

    bool has_no_moves() const;

    std::vector<Deck> decks_;
};

bool can_be_solved(Game);

#endif //INC_1C_PROJECT_GAME_H
