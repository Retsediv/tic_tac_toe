#ifndef TIC_TAC_TOE_IMPROVED_BASETUI_H
#define TIC_TAC_TOE_IMPROVED_BASETUI_H

#include <string>
#include <sstream>
#include "../Board/Board.h"

class BaseTUI {
private:
public:
    virtual void clear_screen() = 0;

    virtual void print_line(std::string line) = 0;

    virtual void print(std::string line) = 0;

    virtual void print(Board board) = 0;

    virtual std::string get_input() = 0;

    int select_from_choices(const std::string &title, const vector<std::string> &choices){
        print_line(title);

        for (int i = 0; i < choices.size(); ++i) {
            print_line(std::to_string(i + 1) + ") " + choices[i]);
        }

        std::string line;
        int ans;
        while (true) {
            std::stringstream strm(get_input());
            strm >> ans;

            if (strm.fail() || ans < 1 || ans > choices.size()) {
                print_line("\"Please, try again and enter the correct value...\"");
                continue;
            }

            return ans;
        }
    };
};


#endif
