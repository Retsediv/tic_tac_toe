#include <string>
#include "../Board/Board.h"

#ifndef TIC_TAC_TOE_IMPROVED_ABSTRACTPLAYER_H
#define TIC_TAC_TOE_IMPROVED_ABSTRACTPLAYER_H

using std::string;
using std::pair;
using std::vector;

class AbstractPlayer {

private:
    string name_m;
    char sign_m;

public:
    AbstractPlayer(const string &name, char sign);

    AbstractPlayer();

    virtual pair<int, int> get_move(int board_size, Board &board);

    const string &getName() const;

    void setName(const string &name_m);

    char getSign() const;

    void setSign(char sign_m);
};


#endif