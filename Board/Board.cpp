#include "Board.h"
#include "FieldInUseException.cpp"

Board::Board(int s) {
    size_m = s;

    board_m.resize(size_m);
    for (int i = 0; i < board_m.size(); ++i) {
        for (int j = 0; j < size_m; ++j) {
            board_m[i].push_back(' ');
        }
    }
}

void Board::put_mark(pair<int, int> coord, char sign) {
    if (check_coord(coord)) {
        board_m[coord.first][coord.second] = sign;
    } else {
        throw FieldInUseException(coord.first, coord.second);
    }
}

bool Board::check_win() const {
//    TODO: complete check winner algorithm
//    bool diagLTRHasWinner = true;
//    bool diagRTLHasWinner = true;
//    for (int j = 1; j < size_m; j++) {
//        bool columHasWinner = true;
//        bool rowHasWinner = true;
//        for (int i = 0; i < size_m; i++) {
//            columHasWinner = columHasWinner && (board_m[i][j] == board_m[i][j - 1]);
//            rowHasWinner = rowHasWinner && (board_m[j][i] == board_m[j - 1][i]);
//        }
//        if ((rowHasWinner && board_m[j][0] != -1) || (columHasWinner && board_m[0][j] != -1)) {
//            return true;
//        }
//        diagLTRHasWinner = diagLTRHasWinner && (board_m[j][j] == board_m[j - 1][j - 1]);
//        diagRTLHasWinner = diagLTRHasWinner && (board_m[size_m - j][j] == board_m[size_m - j + 1][j - 1]);
//    }
//    return (diagRTLHasWinner && board_m[0][0] != -1) || (diagLTRHasWinner && board_m[size_m - 1][0] != -1);

    for (int i = 0; i < size_m; ++i) {
        if ((board_m[i][0] == 'X' || board_m[i][0] == 'O') && board_m[i][0] == board_m[i][1] &&
            board_m[i][1] == board_m[i][2])
            return true;

        if ((board_m[0][i] == 'X' || board_m[0][i] == 'O') && board_m[0][i] == board_m[1][i] &&
            board_m[1][i] == board_m[2][i])
            return true;
    }

    return ((board_m[0][0] == 'X' || board_m[0][0] == 'O') && board_m[0][0] == board_m[1][1] &&
            board_m[1][1] == board_m[2][2]) ||
           (board_m[0][2] == 'X' || board_m[0][2] == 'O') && board_m[0][2] == board_m[1][1] &&
           board_m[1][1] == board_m[2][0];

}

bool Board::check_coord(pair<int, int> coord) {
    if (0 <= coord.first && coord.first < size_m && 0 <= coord.second && coord.second < size_m)
        return board_m[coord.first][coord.second] == ' ';

    return false;
}

void Board::print() const {
    for (int i = 0; i < size_m; ++i) {
        for (int j = 0; j < size_m; ++j) {
            std::cout << board_m[i][j] << ((j != (size_m - 1)) ? " | " : "");
        }
        std::cout << endl;
    }
}
