#include <iostream>
#include "User.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::vector;


User::User(const string &name, char sign) : AbstractPlayer(name, sign) {}

pair<int, int> User::get_move(int board_size, Board &board) {
    cout << "Enter your choice(11, 21, and so on...)" << endl;

    string line;
    pair<int, int> coord;
    while (true) {
        cin >> line;

        if (line.length() != 2) {
            cout << "Please, try again and enter the value in correct format..." << endl;
            continue;
        }

        coord = std::make_pair(line[0] - '0', line[1] - '0');

        return coord;
    }
}