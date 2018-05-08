#include <iostream>
#include <string>
#include <bits/unique_ptr.h>
#include "../utils/helpers.h"
#include "../Board/Board.h"
#include "../Player/AbstractPlayer.h"
#include "../Player/User.h"
#include "../Player/PlayerFactory.h"


#ifndef TIC_TAC_TOE_IMPROVED_GAMEMANAGES_H
#define TIC_TAC_TOE_IMPROVED_GAMEMANAGES_H

using std::pair;

class GameManager {
private:
    char signs_m[2] = {'X', 'O'};

    pair<AbstractPlayer *, AbstractPlayer *> players_m;

    int board_size_m;
    Board board_m;
    PlayerFactory factory = PlayerFactory();

    int choose_game_mode();

    void create_players(int mode);

    void exchange_players();

public:
    explicit GameManager(int board_size);

    void print_help() const;

    void play();
};


#endif
