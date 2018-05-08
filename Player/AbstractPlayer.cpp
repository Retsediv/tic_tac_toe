#include "AbstractPlayer.h"

using std::make_pair;

AbstractPlayer::AbstractPlayer(const string &name, char sign) {
    name_m = name;
    sign_m = sign;
}

const string &AbstractPlayer::getName() const {
    return name_m;
}

void AbstractPlayer::setName(const string &name) {
    name_m = name;
}

char AbstractPlayer::getSign() const {
    return sign_m;
}

void AbstractPlayer::setSign(char sign) {
    sign_m = sign;
}

pair<int, int> AbstractPlayer::get_move(int board_size, Board &board) {};

AbstractPlayer::AbstractPlayer() {
    string default_name = "Default username";
    char default_sign = 'X';
    AbstractPlayer(default_name, default_sign);
}
