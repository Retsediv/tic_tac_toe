#include "EasyComputer.h"
#include "../utils/helpers.h"

using std::make_pair;

EasyComputer::EasyComputer(char sign) : AbstractPlayer(defaultEasyComputerName , sign) {}

pair<int, int> EasyComputer::get_move(int board_size, Board &board) {
    return make_pair(rand_int_range(1, board_size + 1), rand_int_range(1, board_size + 1));
}
