#ifndef TIC_TAC_TOE_IMPROVED_PLAYERFACTORY_H
#define TIC_TAC_TOE_IMPROVED_PLAYERFACTORY_H


#include "AbstractPlayer.h"

class PlayerFactory {

public:
    PlayerFactory();

    AbstractPlayer *create(int mode, char sign);

private:
    string input_user_name();
};


#endif
