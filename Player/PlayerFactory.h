#ifndef TIC_TAC_TOE_IMPROVED_PLAYERFACTORY_H
#define TIC_TAC_TOE_IMPROVED_PLAYERFACTORY_H

#include "AbstractPlayer.h"
#include "../TUI/BaseTUI.h"

using std::string;


class PlayerFactory {

public:
    PlayerFactory();

    explicit PlayerFactory(BaseTUI *tui): tui_(tui){};

    AbstractPlayer *create(int mode, char sign);

private:
    string input_user_name();
    BaseTUI *tui_;
};


#endif
