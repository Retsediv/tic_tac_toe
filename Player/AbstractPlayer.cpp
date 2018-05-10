#include "AbstractPlayer.h"

using std::make_pair;
using std::string;
using std::pair;
using std::vector;

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