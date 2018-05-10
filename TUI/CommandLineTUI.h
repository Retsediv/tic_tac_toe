#ifndef TIC_TAC_TOE_IMPROVED_COMMANDLINETUI_H
#define TIC_TAC_TOE_IMPROVED_COMMANDLINETUI_H

#include <iostream>
#include <string>
#include <vector>
#include "BaseTUI.h"

class CommandLineTUI : public BaseTUI {
private:
public:
    CommandLineTUI() = default;

    void clear_screen() override;

    void print_line(std::string line) override;

    void print(std::string line) override;

    void print(Board board) override;

    std::string get_input() override;
};


#endif
