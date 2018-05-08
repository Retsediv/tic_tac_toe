#include "EasyComputer.h"
#include "../utils/helpers.h"

using std::make_pair;

EasyComputer::EasyComputer(char sign) : AbstractPlayer(defaultEasyComputerName , sign) {}

pair<int, int> EasyComputer::get_move(int board_size, Board &board) {
    return make_pair(get_random_number(1, board_size + 1), get_random_number(1, board_size + 1));
}
