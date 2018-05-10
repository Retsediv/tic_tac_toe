#ifndef TIC_TAC_TOE_IMPROVED_NCURSESTUI_H
#define TIC_TAC_TOE_IMPROVED_NCURSESTUI_H

#include "BaseTUI.h"
#include "ncurses.h"

class NcursesTUI : public BaseTUI {
private:
    int yMax, xMax;
public:
    NcursesTUI() {
        initscr(); // enter ncurses displaying
        noecho();
        cbreak();

        getmaxyx(stdscr, yMax, xMax);
    };

    ~NcursesTUI() {
        getch();  // wait for pressing any key
        endwin(); // exit from ncurses displaying. required!!!
    };

    void clear_screen() override;

    void print_line(std::string line) override;

    void print(std::string line) override;

    void print(Board board) override;

    std::string get_input() override;
};


#endif
