// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minpath(vector<vector<char>>& map, int n) {
        int currmin = INT_MAX;
        N = n;
        graph = map;
        memo = vector<int> (n * n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] != '@') continue;
                int res = bfs(i, j);
                currmin = min(currmin, res);
                if(res == 13) cout << i << j << endl;
            }
        }
        return currmin;
    }
private:
    vector<vector<char>> graph;
    vector<int> memo;
    int N = 0;
    int bfs(int x, int y) {
        queue<pair<int, int>> Q;
        Q.push({x, y});
        int step = 0;
        while(!Q.empty()) {
            int size = Q.size();
            while(size-- > 0) {
                pair<int, int> curr = Q.front();
                Q.pop();
                if(memo[curr.first * N + curr.second] == 1) continue;

                cout << curr.first << curr.second << endl;
                if(graph[curr.first][curr.second] == '*') {
                    cout << "output:" << curr.first << curr.second << endl;
                    return step;}

                memo[curr.first*N + curr.second] = 1;

                if(curr.first + 1 < N && graph[curr.first + 1][curr.second] != '#') 
                    Q.push({curr.first + 1, curr.second});
                if(curr.first - 1 >= 0 && graph[curr.first - 1][curr.second] != '#') 
                    Q.push({curr.first - 1, curr.second});
                if(curr.second + 1 < N && graph[curr.first][curr.second + 1] != '#')
                    Q.push({curr.first, curr.second + 1});
                if(curr.second - 1 >= 0 && graph[curr.first][curr.second - 1] != '#')
                    Q.push({curr.first, curr.second - 1});
            step++;
            }
        }
        return INT_MAX;
    }
};

int main(){
    //freopen("1.in","r",stdin);
    int n = 0;
    cin >> n;
    vector<vector<char>> map(n, vector<char>(n, '.'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char x; scanf("%c",&x);
            if(x == '\n') continue;
            map[i][j] = x;
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }

    // int ans = Solution().minpath(map, n);
    // cout << ans;
    return 0;
};

/*
10
.@....##@.
......#...
...@..#...
###.......
....##..#.
...####...
@...##....
#####.....
..##*####.
#.........
*/