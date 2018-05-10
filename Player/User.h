#ifndef TIC_TAC_TOE_IMPROVED_USER_H
#define TIC_TAC_TOE_IMPROVED_USER_H

#include "AbstractPlayer.h"
#include "../TUI/BaseTUI.h"

class User : public AbstractPlayer {
public:
    User(const std::string &name, char sign);

    pair<int, int> get_move(int board_size, Board &board, BaseTUI* tui_) override;
};

#endif
