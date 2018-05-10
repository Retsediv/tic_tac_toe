#include <sstream>
#include "GameManager.h"
#include "../utils/helpers.h"
#include "../Board/FieldInUseException.cpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::stringstream;

void GameManager::print_help() const {
    tui_->print_line("Hello in our Tic-Tac-Toe game.");
}

int GameManager::choose_game_mode() {
    vector<string> answ{"Game with friend", "Game with computer(simple)", "Game with computer(hard)"};
    return tui_->select_from_choices("Select your game mode:", answ);
}

void GameManager::create_players(int mode) {
    int rand_s_index = get_random_number(0, 1);
    int second_s_index = (rand_s_index == 0) ? 1 : 0;

    players_m.first = factory.create(1, signs_m[rand_s_index]);
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
    tui_->clear_screen();

    print_help();
    create_players(choose_game_mode());

    size_t steps = 0;
    while (steps < (board_size_m * board_size_m)) {
        tui_->clear_screen();

//        board_m.print();
        tui_->print(board_m);
        tui_->print_line(players_m.first->getName() + ", it's your turn!");

        while (true) {
            try {
                pair<int, int> move = players_m.first->get_move(board_size_m, board_m, tui_);
                board_m.put_mark(std::make_pair(move.first - 1, move.second - 1), players_m.first->getSign());
                break;
            } catch (const FieldInUseException &e) {
                tui_->print_line(e.what());
                tui_->print_line("Incorrect coordinates. Try again!!!");
            }
        }

        if (board_m.check_win()) {
            tui_->print_line("Congratulations!!!! " + players_m.first->getName() + " won!");
            board_m.print();
            return;
        }

        exchange_players();
        steps += 1;
    }


    tui_->print_line("!!! DRAW !!!");
}


