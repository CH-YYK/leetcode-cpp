// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // simple bfs/dfs
        // topological sorting, access a node only if all inbounded nodes have been visited
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> visited(n + 1, 0);
    	auto dfs = [&](int curr, vector<int>& path){
    		if(curr == n-1) {
    			ans.push_back(path);
    			return;
    		}
    		for(int nxt : graph[curr]) {
    			if(visited[nxt]) continue;
    			// visited cache is for cycles, but can be avoided for DAG
    			// visited[nxt] = 1;
    			path.push_back(nxt);
    			dfs(nxt, path);
    			path.pop_back();
    			// visited[nxt] = 0;
    		}
    	};
    	vector<int> path;
    	dfs(0, path);
    	return ans;
    }
};