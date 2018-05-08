#ifndef TIC_TAC_TOE_IMPROVED_EASYCOMPUTER_H
#define TIC_TAC_TOE_IMPROVED_EASYCOMPUTER_H

#include "AbstractPlayer.h"

const string defaultEasyComputerName = "Bob";

class EasyComputer : public AbstractPlayer {
public:
    explicit EasyComputer(char sign);

    pair<int, int> get_move(int board_size, Board &board) override;
};

#endif
