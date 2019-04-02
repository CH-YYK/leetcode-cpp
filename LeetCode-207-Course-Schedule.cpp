#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    // Topological sorting, degree, dfs
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph_ = vector<vector<int>>(numCourses);
        for(const auto &i : prerequisites) {
            graph_[i.first].push_back(i.second);
        }

        // o: unknown, 1: visiting, 2: visited
        visited = vector<int>(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            if(dfs(i)) return false;
        }
        return true;
    }
private:
    vector<vector<int>> graph_;
    vector<int> visited;

    bool dfs(int currCourse) {
        if(visited[currCourse] == 1) return true;
        if(visited[currCourse] == 2) return false;
        
        visited[currCourse] = 1;
        for(const auto &i : graph_[currCourse]) 
            if(dfs(i)) return true;
        visited[currCourse] = 2;
        return false;
    }
};