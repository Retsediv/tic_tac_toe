#ifndef TIC_TAC_TOE_IMPROVED_NCURSESTUI_H
#define TIC_TAC_TOE_IMPROVED_NCURSESTUI_H

#include "BaseTUI.h"
#include "ncurses.h"

class NcursesTUI : public BaseTUI {
private:
public:
    NcursesTUI() {
        initscr(); // enter ncurses displaying
//        getch();                     // Ожидание нажатия какой-либо клавиши пользователем
    };

    ~NcursesTUI() {
        endwin(); // exit from ncurses displaying. required!!!
    };

    void clear_screen() override;

    void print_line(std::string line) override;

    void print(std::string line) override;

    void print(Board board) override;

    std::string get_input() override;

    int select_from_choices(const std::string &title, const vector<std::string> &choices) override;
};


#endif
