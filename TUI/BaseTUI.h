#ifndef TIC_TAC_TOE_IMPROVED_BASETUI_H
#define TIC_TAC_TOE_IMPROVED_BASETUI_H

#include <string>
#include "../Board/Board.h"

class BaseTUI {
private:
public:
    virtual void clear_screen() = 0;

    virtual void print_line(std::string line) = 0;

    virtual void print(std::string line) = 0;

    virtual void print(Board board) = 0;

    virtual std::string get_input() = 0;

    virtual int select_from_choices(const std::string &title, const vector<std::string> &choices) = 0;
};


#endif
