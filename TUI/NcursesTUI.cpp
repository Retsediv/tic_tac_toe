#include "NcursesTUI.h"

#include <sstream>

using std::string;
using std::stringstream;

void NcursesTUI::clear_screen() {
    clear();
    refresh();
}

void NcursesTUI::print_line(string line) {
    printw(line.c_str());
    printw("\n");
    refresh();
}

void NcursesTUI::print(string line) {
    printw(line.c_str());
    refresh();
}

void NcursesTUI::print(Board board) {

}

string NcursesTUI::get_input() {
    string input;

    // let the terminal do the line editing
    nocbreak();
    echo();

    // draw input field
    WINDOW *inputwin = newwin(3, xMax - 24, yMax - 3, 12);
    box(inputwin, 12, 0);

    wrefresh(inputwin);

    // this reads from buffer after <ENTER>, not "raw"
    // so any backspacing etc. has already been taken care of

    // move window's cursor
    wmove(inputwin, 1, 1);
    refresh();

    int ch = wgetch(inputwin);

    while (ch != '\n') {
        input.push_back(ch);
        ch = wgetch(inputwin);
    }

    return input;
}