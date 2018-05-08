#include <vector>

#ifndef TIC_TAC_TOE_IMPROVED_BOARD_H
#define TIC_TAC_TOE_IMPROVED_BOARD_H

using std::vector;
using std::pair;

class Board {
public:
    explicit Board(int size);

    void put_mark(pair<int, int> coord, char sign);

    bool check_win() const;

    void print() const;

private:
    int size_m;
    vector<vector<char>> board_m;

    bool check_coord(pair<int, int> coord);
};


#endif
