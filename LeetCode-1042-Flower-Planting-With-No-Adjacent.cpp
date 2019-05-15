#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        graph = vector<vector<int>>(N, vector<int>());
        for(auto path : paths) {
            graph[path[0]-1].push_back(path[1]-1);
            graph[path[1]-1].push_back(path[0]-1);
        }
        types = vector<int> (N, 0);

        for(int i = 0; i < N; i++) {
            vector<int> colors(5, 0);
            for(int j : graph[i]) 
                if(types[j] > 0) colors[types[j]] = 1;
            for(int c = 4; c > 0; c--) 
                if(!colors[c]) types[i] = c;
        }
        return types;
    }           
private:
    vector<vector<int>> graph;
    vector<int> types;
};

int main() {
    int N = 3;
    vector<vector<int>> paths = {{1,2}, {2, 3}, {3, 1}};
    auto ans = Solution().gardenNoAdj(N, paths);
    for(int i : ans) cout << i;
}