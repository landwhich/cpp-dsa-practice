#include <set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::set<char> row;
        std::set<char> col;
        std::set<char> box;
        for (int i = 0; i < 81; i++){
            if (i%9 == 0 && i!=0) {col.clear(); row.clear(); box.clear();}
            //col
            if (board[i%9][i/9] != '.'){
                if (!col.insert(board[i%9][i/9]).second)
                return false;
            }
            //row
            if (board[i/9][i%9] != '.'){
                if (!row.insert(board[i/9][i%9]).second)
                return false;
            }
            //box
            if (board[(i/3)%9][(i%3)+((i/27)*3)] != '.'){
                if (!box.insert(board[(i/3)%9][(i%3)+((i/27)*3)]).second)
                return false;
            }
        }
        return true;
    }
};