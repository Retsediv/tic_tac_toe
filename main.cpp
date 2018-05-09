#include <sstream>
#include "Manager/GameManager.h"
#include "TUI/CommandLineTUI.h"
#include "TUI/NcursesTUI.h"

int main() {
    BaseTUI *t;
    BaseTUI *cmd = new CommandLineTUI();

    cmd->clear_screen();
    vector<string> ch{"CommandLine", "Ncurses"};
    int mode = cmd->select_from_choices("Select your GUI(TUI)", ch);

    switch (mode) {
        case 1: {
            t = cmd;
        }
            break;
        case 2: {
            t = new NcursesTUI{};
        }
            break;
        default: {
            break;
        }
    }

    GameManager game{3, t};
    game.play();

    return 0;
}