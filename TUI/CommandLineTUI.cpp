#include <sstream>
#include "CommandLineTUI.h"

using std::string;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;

void CommandLineTUI::clear_screen() {
    cout << "\x1B[2J\x1B[H";
}

void CommandLineTUI::print_line(string line) {
    cout << line << endl;
}

void CommandLineTUI::print(std::string line) {
    cout << line;
}

void CommandLineTUI::print(Board board) {
    for (int i = 0; i < board.getSize(); ++i) {
        for (int j = 0; j < board.getSize(); ++j) {
            cout << board.getBoard()[i][j] << ((j != (board.getSize() - 1)) ? " | " : "");
        }
        cout << endl;
    }
}

string CommandLineTUI::get_input() {
    string line;
    getline(cin, line);
    return line;
}

int CommandLineTUI::select_from_choices(const string &title, const vector<std::string> &choices) {
    print_line(title);

    for (int i = 0; i < choices.size(); ++i) {
        print_line(std::to_string(i + 1) + ") " + choices[i]);
    }

    string line;
    int ans;
    while (true) {
        stringstream strm(get_input());
        strm >> ans;

        if (strm.fail() || ans < 1 || ans > choices.size()) {
            print_line("\"Please, try again and enter the correct value...\"");
            continue;
        }

        return ans;
    }
}
