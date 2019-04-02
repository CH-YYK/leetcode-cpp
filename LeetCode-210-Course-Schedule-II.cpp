#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph_ = vector<vector<int>> (numCourses);
        for(const auto &p : prerequisites) 
            graph_[p.second].push_back(p.first);

        visited = vector<int> (numCourses, 0);

        for(int i = 0; i < numCourses; i++)
            if(dfs(i)) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    vector<vector<int>> graph_;
    vector<int> visited;
    vector<int> ans;

    bool dfs(int currCourse) {
        if(visited[currCourse] == 1) return true;
        if(visited[currCourse] == 2) return false;
        
        visited[currCourse] = 1;
        
        for(const int i : graph_[currCourse]) 
            if(dfs(i)) return true;
        
        visited[currCourse] = 2;
        ans.push_back(currCourse);
        return false;
    }
};

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);    
    for(const auto& p : prerequisites)
      graph[p.second].push_back(p.first);
 
    // states: 0 = unkonwn, 1 == visiting, 2 = visited
    vector<int> v(numCourses, 0);
    vector<int> ans;
    
    for (int i = 0; i < numCourses; ++i)
      if (dfs(i, graph, v, ans)) return {};
 
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
private:
  bool dfs(int cur, vector<vector<int>>& graph, vector<int>& v, vector<int>& ans) {
    if (v[cur] == 1) return true;
    if (v[cur] == 2) return false;
 
    v[cur] = 1;
    
    for (const int t : graph[cur])
      if (dfs(t, graph, v, ans)) return true;
    
    v[cur] = 2;
    ans.push_back(cur);
 
    return false;
  }
};