#include <sstream>
#include "GameManager.h"
#include "../Board/FieldInUseException.cpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::stringstream;

GameManager::GameManager(int board_size) : board_size_m(board_size), board_m(Board(board_size)) {}

void GameManager::print_help() const {
    cout << "Hello in our Tic-Tac-Toe game." << endl;
}

int GameManager::choose_game_mode() {
    cout << "Select your game mode:" << endl;
    cout << "1) Game with friend" << endl;
    cout << "2) Game with computer(simple)" << endl;
    cout << "3) Game with computer(hard)" << endl;

    string line;
    int mode;
    while (true) {
        getline(cin, line);
        stringstream strm(line);

        strm >> mode;

        if (strm.fail() || mode < 1 || mode > 4) {
            cout << "Please, try again and enter the correct value..." << endl;
            continue;
        }

        return mode;
    }
}

void GameManager::create_players(int mode) {
    int rand_s_index = rand_int_range(0, 1);
    int second_s_index = (rand_s_index == 0) ? 1 : 0;


    players_m.first = factory.create(1, signs_m[rand_s_index]);
//    cout << "Created: " << (*players_m.first).getName() << endl;

    players_m.second = factory.create(mode, signs_m[second_s_index]);

    if (rand_s_index != 0) {
        exchange_players();
    }
}

void GameManager::exchange_players() {
    AbstractPlayer *tmp = players_m.second;
    players_m.second = players_m.first;
    players_m.first = tmp;
}


void GameManager::play() {
    print_help();
    create_players(choose_game_mode());

    size_t steps = 0;
    while (steps < (board_size_m * board_size_m)) {
        board_m.print();
        cout << (*players_m.first).getName() << ", it's your turn!" << endl;

        while (true) {
            try {
                pair<int, int> move = (*players_m.first).get_move(board_size_m, board_m);

                board_m.put_mark(std::make_pair(move.first - 1, move.second - 1), (*players_m.first).getSign());

                break;
            } catch (const FieldInUseException &e) {
                cout << e.what();
                cout << "Try again!!!" << endl;
            }
        }

        if (board_m.check_win()) {
            cout << "Congratulations!!!! " << (*players_m.first).getName() << " won!" << endl;
            board_m.print();
            break;
        }

        exchange_players();
        steps += 1;
    }
}


