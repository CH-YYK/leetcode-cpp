#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        memo = board;
        m = board.size();
        if(m == 0) return;
        n = board[0].size();
        if(n == 0) return;
        for(int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++) {
                if(memo[i][j] != 'O') continue;
                bfs(board, i, j);
            }
        }
    }
private:
    vector<vector<char>> memo;
    int m, n;

    void bfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> history({{i, j}});
        queue<pair<int, int>> cache({{i, j}});

        bool border = false;
        while(!cache.empty()) {
            pair<int, int> curr = cache.front();
            cache.pop();
            if(memo[curr.first][curr.second] != 'O') 
                continue;
            if(curr.first == 0 || curr.second == 0 || curr.first == m-1 || curr.second == n-1) {
                border = true;
                continue;
            }
            memo[curr.first][curr.second] = 'c';
            
            history.push(curr);

            cache.push({curr.first+1, curr.second});
            cache.push({curr.first-1, curr.second});
            cache.push({curr.first, curr.second - 1});
            cache.push({curr.first, curr.second + 1});
        }

        if(border) return;
        while(!history.empty()) {
            pair<int, int> curr = history.front();
            history.pop();
            memo[curr.first][curr.second] = 'X';
            board[curr.first][curr.second] = 'X';
        }
        return;
    }
};
