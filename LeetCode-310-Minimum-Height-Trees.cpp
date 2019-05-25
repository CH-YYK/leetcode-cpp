#include <vector>
#include <iostream>
#include <limits.h>
#include <unordered_set>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
    // longest path
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        N = n;
        graph = vector<vector<int>>(n);
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(N, INT_MAX);
        vector<int> res;
        for(int i = 0; i < N; i++) {
            ans[i] = bfs(i);
            while(!res.empty() && ans[res.back()] > ans[i]) res.pop_back();
            if(!res.empty() && ans[res.back()] < ans[i]) continue;
            res.push_back(i);
        }
        return res;
    }
private:
    vector<vector<int>> graph;
    int N;
    int bfs(int curr) {
        queue<int> Q({curr});
        vector<int> visited(N, 0);
        int steps = -1;
        while(!Q.empty()){
            steps++;
            int size = Q.size();
            while(size-- > 0) {
                int cur = Q.front();
                Q.pop();
                visited[cur] = 1;
                for(int i : graph[cur]) {
                    if(visited[i]) continue;
                    Q.push(i);
                }
            }
        }
        return steps;
    }
};

class Solution2 {
    // longest path
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) return {0};
        graph = vector<unordered_set<int>>(n);
        for(auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;
        for(int i = 0; i < n; i++) 
            if(graph[i].size() == 1) leaves.push_back(i);
        
        while(n > 2) {
            n -= leaves.size();
            vector<int> newleaves;
            for(int i : leaves) {
                int j = *graph[i].begin();
                graph[j].erase(i);
                if(graph[j].size() == 1) newleaves.push_back(j);
            }
            leaves = newleaves;
        }
        return leaves;
    }
private:
    vector<unordered_set<int>> graph;
};




int main() {
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    int n = 4;
    vector<int> ans = Solution().findMinHeightTrees(n, edges);
    for(auto i : ans) cout << i << " ";
    return 0;
}