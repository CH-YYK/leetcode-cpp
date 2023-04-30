// Hello, <> is a CPP leetcode snippet.

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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		// if current category is 0 mark another 1 using DFS
		// if already have category, return false
		// coloring + dfs
    	vector<int> categories(n, -1);
    	graph = vector<vector<int>>(n);
    	for(vector<int>& edge : dislikes) {
    		graph[edge[0] - 1].push_back(edge[1] - 1);
    		graph[edge[1] - 1].push_back(edge[0] - 1);
    	}
    	bool ans = true;
    	for(int i = 0; i < n; ++i) {
    		if(categories[i] != -1)
    			continue;
    		categories[i] = 0;
    		ans &= dfs(categories, i);
    	}
    	return ans;
    }
private:
	vector<vector<int>> graph;
	bool dfs(vector<int>& categories, int curr) {
		int nxtCategory = categories[curr] ^ 1;
		bool ans = true;
		for(int nxt : graph[curr]) {
			if(categories[nxt] == -1) {
				categories[nxt] = nxtCategory;
				ans &= dfs(categories, nxt);
			} else if(categories[nxt] != nxtCategory) {
				return false;
			}
		}
		return ans;
	}
};