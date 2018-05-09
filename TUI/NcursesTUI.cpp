#include "NcursesTUI.h"

void NcursesTUI::clear_screen() {
    clear();
    refresh();
}

void NcursesTUI::print_line(std::string line) {
    printw(line.c_str());
    printw("\n");
    refresh();
}

void NcursesTUI::print(std::string line) {
    printw(line.c_str());
    refresh();
}

void NcursesTUI::print(Board board) {

}

std::string NcursesTUI::get_input() {
    return std::__cxx11::string();
}

int NcursesTUI::select_from_choices(const std::string &title, const vector<std::string> &choices) {
    return 0;
}