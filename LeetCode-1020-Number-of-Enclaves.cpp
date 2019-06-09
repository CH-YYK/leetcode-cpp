#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        m = A.size();
        n = A[0].size();

        int sum = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(A[i][j] == 1)
                    sum += bfs(A, i, j);
            }
        }
        return sum;
    }
private:
    int m, n;

    int bfs(vector<vector<int>> &graph, int i, int j) {
        int step = 0;
        if(i == 0 || i == m-1 || j == 0 || j == n-1) 
            step = -1;
        queue<pair<int, int>> Q({{i, j}});
        while(!Q.empty()){
            int size = Q.size();
            while(size-- > 0) {
                auto curr = Q.front();
                Q.pop();

                if(graph[curr.first][curr.second] < 1) continue;

                graph[curr.first][curr.second] = -1;

                if(curr.first == 0 || curr.first == m - 1) step = -1;
                if(curr.second == 0 || curr.second == n - 1) step = -1;

                if(step != -1) step++;

                if(curr.first-1 >= 0 && graph[curr.first-1][curr.second] == 1) 
                    Q.push({curr.first - 1, curr.second});
                if(curr.first + 1 < m && graph[curr.first+1][curr.second] == 1) 
                    Q.push({curr.first + 1, curr.second});
                if(curr.second - 1 >= 0 && graph[curr.first][curr.second - 1] == 1) 
                    Q.push({curr.first, curr.second-1});
                if(curr.second + 1 < n && graph[curr.first][curr.second + 1] == 1) 
                    Q.push({curr.first, curr.second+1});
            }
        }
        return step == -1 ? 0:step;
    }
};