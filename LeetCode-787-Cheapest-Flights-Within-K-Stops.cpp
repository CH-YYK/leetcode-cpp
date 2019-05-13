#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        graph = vector<vector<int>> (n, vector<int>(n, INT_MAX));
        for(auto route : flights) 
            graph[route[0]][route[1]] = route[2];
        
        queue<int> q({src});
        while(!q.empty() && K > -1) {
            int size = q.size();
            while(size-- > 0) {
                int curr = q.front(); q.pop();

                for(int next = 0; next < n; next++) {
                    if(graph[curr][next] == INT_MAX)  continue;
                    int hist_cost = src == curr ? 0 : graph[src][curr];
                    graph[src][next] = min(hist_cost + graph[curr][next], graph[src][next]);
                    q.push(next);
                }
            }
            K--;
        }
        return graph[src][dst] == INT_MAX ? -1 : graph[src][dst];
    }
private:
    vector<vector<int>> graph;
};

class Solution2 {
    // recursive with memoization
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        graph = vector<vector<int>> (n, vector<int>(n, -1));
        for(auto route : flights) 
            graph[route[0]][route[1]] = route[2];
        N = n;
        memo = vector<vector<vector<int>>>(K+1, vector<vector<int>>(n, vector<int>(n, -1)));
        
        return dfs(src, dst, K);
    }
private:
    vector<vector<int>> graph;
    vector<vector<vector<int>>> memo;
    int N;

    int dfs(int src, int dst, int K) {
        if(src == dst) return 0;
        if(K == -1) return -1;

        if(memo[K][src][dst] >= 0) return memo[K][src][dst];

        int max = INT_MAX;
        for(int i = 0; i < N; i++) {
            if(graph[src][i] == -1)  continue;
            int from_next = dfs(i, dst, K-1);
            max = from_next == -1 ? max : min(max, from_next + graph[src][i]);
        }
        
        memo[K][src][dst] = max < INT_MAX ? max : -1;
        return memo[K][src][dst];
    }
};

class Solution4 {
    // DP solution
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int N = n;
        vector<vector<int>>dp(K+2, vector<int>(n, INT_MAX));

        dp[0][src] = 0;
        for(int i = 1; i<=K+1; i++) {
            dp[i][src] = 0;
            for(const auto &x : flights) {
                if(dp[i-1][x[0]] == INT_MAX) continue;
                dp[i][x[1]] = min(dp[i][x[1]], dp[i-1][x[0]] + x[2]);
            }
        }
        return dp[K+1][dst] == INT_MAX ? -1 : dp[K+1][dst];
    }
};

class Solution3 {
    // DFS with prunning
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        graph = vector<vector<int>> (n, vector<int>(n, INT_MAX));
        for(auto route : flights) 
            graph[route[0]][route[1]] = route[2];
        N = n;
        
        vector<int> visited(n, 0);
        dfs(src, dst, K, 0, visited);
        return res == INT_MAX ? -1 : res;
    }
private:
    vector<vector<int>> graph;
    int res = INT_MAX;
    int N;

    void dfs(int s, int d, int k, int cost, vector<int> &visited) {
        if(s == d) {res = cost; return;}
        if(k == -1) return;
        visited[s] = 1;
        for(int i = 0; i < N; i++) {
            if(visited[i] == 1 || graph[s][i] == INT_MAX) continue;
            if(cost + graph[s][i] > res) continue;
            dfs(i, d, k-1, cost + graph[s][i], visited);
        }
        visited[s] = 0;
    }
};