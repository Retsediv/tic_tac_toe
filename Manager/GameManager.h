#ifndef TIC_TAC_TOE_IMPROVED_GAMEMANAGES_H
#define TIC_TAC_TOE_IMPROVED_GAMEMANAGES_H

#include <iostream>
#include <string>
#include "../Board/Board.h"
#include "../Player/AbstractPlayer.h"
#include "../Player/User.h"
#include "../TUI/BaseTUI.h"
#include "../Player/PlayerFactory.h"


class GameManager {
private:
    char signs_m[2] = {'X', 'O'};

    pair<AbstractPlayer *, AbstractPlayer *> players_m;

    int board_size_m;
    Board board_m;
    BaseTUI *tui_;

    PlayerFactory factory = PlayerFactory(tui_);

    int choose_game_mode();

    void create_players(int mode);

    void exchange_players();

public:
    explicit GameManager(int board_size, BaseTUI* tui) :
            board_size_m(board_size), board_m(Board(board_size)), tui_(tui)
    {};

    void print_help() const;

    void play();
};


#endif
