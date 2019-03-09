#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        num = n;
        board_ = vector<string>(n, string(n, '.'));
        diagup = vector<int>(2*n-1, 0);
        diagdown = vector<int>(2*n-1, 0);
        col_ = vector<int>(2*n-1, 0);

        // start from the first row
        placeQueen(0, n);
        return all;
    }
private:
    int num;
    vector<int> col_;
    vector<int> diagup;
    vector<int> diagdown;
    vector<string> board_;
    vector<vector<string>> all;

    void updateBoard(int x, int y, int val) {
        col_[x] = val;
        diagup[x+y] = val;
        diagdown[x-y+num-1] = val;
        board_[y][x] = val == 1 ? 'Q' : '.'; 
    }

    bool isAvailable(int x, int y) {
        return col_[x] || diagup[x+y] || diagdown[x-y+num-1];
    }

    void placeQueen(int y, int n) {
        if(y >= n){
            all.push_back(board_);
            return ;
        }
        for(int x = 0; x<num; x++){
            if(isAvailable(x, y)) continue;
            updateBoard(x, y, 1);
            placeQueen(y+1, n);
            updateBoard(x, y, 0);
        }
    }
};