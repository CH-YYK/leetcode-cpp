#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
    // BFS version solution.
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '0') continue;
                bfs(grid, i, j);
                islands++;
            }
        }
        return islands;
    }
private:
    int m, n;
    int islands = 0;

    // bfs:: when a 1 is met, bfs to find all 1's that connect to current 1;
    //      flip 1 to 0 after visiting the point
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>>coords({{i, j}});
        while(!coords.empty()) {
            pair<int, int> curr = coords.front();
            coords.pop();
            auto vecs = directions(curr);
            for(auto &i : vecs) {
                if(!inbound(i.first, i.second)) continue;
                else if(grid[i.first][i.second] == '1'){
                    grid[i.first][i.second] = '0';
                    coords.push(i);
                }
            }
        }

    }

    // inbound:: check whether the current position (i, j) is in grid
    bool inbound(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    vector<pair<int, int>> directions(pair<int, int>& curr) {
        int i = curr.first, j = curr.second;
        return vector<pair<int,int>> ({{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}});
    }
};


class Solution2 {
    // recursive solution with BFS/DFS
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '0') continue;
                dfs(grid, i, j);
                islands++;
            }
        }
        return islands;
    }
private:
    int islands = 0;
    int m, n;
    // bfs:: when a 1 is met, bfs to find all 1's that connect to current 1;
    //      flip 1 to 0 after visiting the point
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(grid[i][j] == '1') {
            grid[i][j] = '0';
            if(i + 1 < grid.size()) dfs(grid, i+1, j);
            if(i - 1 >= 0) dfs(grid, i-1, j);
            if(j + 1 < grid[0].size()) dfs(grid, i, j + 1);
            if(j - 1 >= 0) dfs(grid, i, j-1);
        }
    }
};