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
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(vector<int>& edge : edges) {
        	graph[edge[0]].push_back(edge[1]);
        	graph[edge[1]].push_back(edge[0]);
        }

		return max(dfs(graph, hasApple, -1, 0) - 2, 0);
	}
private:
	int dfs(vector<vector<int>>& graph, vector<bool>& hasApple, int prev, int curr) {
		// minimum time spent to collect all apples in the 
		// substree rooted by curr.
		int ans = 0;
		for(int nxt : graph[curr]) {
            if(nxt == prev) continue;
			int timeOnNxt = dfs(graph, hasApple, curr, nxt);
			if(timeOnNxt > 0)
				ans += timeOnNxt;
		}
		if(ans == 0)		
			return hasApple[curr] ? 2 : 0;
		return ans + 2;
	}
};