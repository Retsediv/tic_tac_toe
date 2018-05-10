#include <iostream>
#include "PlayerFactory.h"
#include "User.h"
#include "EasyComputer.h"

using std::cin;
using std::cout;
using std::endl;

PlayerFactory::PlayerFactory() {}

AbstractPlayer *PlayerFactory::create(int mode, char sign) {
    switch (mode) {
        case 1: {
            string name = input_user_name();
            return new User(name, sign);
        }
        case 2: {
            return new EasyComputer(sign);
        }
//        case 3:
//            players_m.second = ComputerHard(signs_m[second_s_index]);
//            break;
        default:
            break;
    }
}

string PlayerFactory::input_user_name() {
    tui_->print_line("Enter your name: ");
    return tui_->get_input();
}
