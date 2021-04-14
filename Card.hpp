#ifndef INC_1C_PROJECT_CARD_H
#define INC_1C_PROJECT_CARD_H

#include <cassert>

class Card {
public:
    // ace - 14
    // king - 13
    // queen - 12
    // jack - 11
    // numbers are numbers
    Card () = delete;

    explicit Card (int number) : number(number) {
        assert(number >= 6);
    }

    void open() {
        is_opened = true;
    }

    int get_value() const {
        return number;
    }

    bool opened() const {
        return is_opened;
    }
private:
    bool is_opened = false;
    const int number;
};
#endif //INC_1C_PROJECT_CARD_H



