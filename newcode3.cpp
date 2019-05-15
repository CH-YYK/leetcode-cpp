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
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][j] != '@') continue;
                currmin = min(currmin, bfs(i, j));
            }
        }
        return currmin;
    }
private:
    vector<vector<char>> graph;
    int N = 0;
    int bfs(int x, int y) {
        queue<pair<int, int>> Q;
        Q.push({x, y});
        int step = 0;
        while(!Q.empty()) {
            int size = Q.size();
            step++;
            while(size-- > 0) {
                pair<int, int> curr = Q.front();
                Q.pop();

                if(graph[curr.first][curr.second] == '*') return step;

                if(curr.first + 1 < N && graph[curr.first + 1][curr.second] != '#')
                    Q.push({curr.first + 1, curr.second});
                if(curr.first - 1 >= 0 && graph[curr.first - 1][curr.second] != '#') 
                    Q.push({curr.first - 1, curr.second});
                if(curr.second + 1 < N && graph[curr.first][curr.second + 1] != '#')
                    Q.push({curr.first, curr.second + 1});
                if(curr.second - 1 >= 0 && graph[curr.first][curr.second - 1] != '#')
                    Q.push({curr.first, curr.second - 1});
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

    int ans = Solution().minpath(map, n);
    cout << ans;
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