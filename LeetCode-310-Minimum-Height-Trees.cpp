#include <vector>
#include <iostream>
#include <limits.h>
#include <unordered_set>
using namespace std;

class Solution {
    // longest path
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        graph_ = vector<vector<int>>(n);
        for(const auto &p : edges)
            graph_[p.first].push_back(p.second), graph_[p.second].push_back(p.first);
        
        
        vector<int> res;
        for(int i = 0; i< n; i++)
            if(ans[i] == curMin) res.push_back(i);
        return res;
    }

private:
    unordered_set<int> visited;
    vector<vector<int>> graph_;
    vector<vector<int>> all_paths;

    void dfs(int cur, vector<int>& path, int N) {
        if(visited.size() == N) {
            all_paths.push_back(path);
            return;
        }
        if(visited.count(cur)) return;
        for(int i : graph_[cur]) {
            path.push_back(i);
            dfs(i, path, N);
            path.pop_back();
        }
        return;
    }
};

int main() {
    vector<pair<int, int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    int n = 4;
    vector<int> ans = Solution().findMinHeightTrees(n, edges);
    for(auto i : ans) cout << i << " ";
    return 0;
}