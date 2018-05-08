#ifndef TIC_TAC_TOE_IMPROVED_ABSTRACTPLAYER_H
#define TIC_TAC_TOE_IMPROVED_ABSTRACTPLAYER_H

#include <string>
#include "../Board/Board.h"

class AbstractPlayer {

private:
    std::string name_m;
    char sign_m;

public:
    AbstractPlayer(const std::string &name, char sign);

    AbstractPlayer();

    virtual pair<int, int> get_move(int board_size, Board &board);

    const std::string &getName() const;

    void setName(const std::string &name_m);

    char getSign() const;

    void setSign(char sign_m);
};


#endif