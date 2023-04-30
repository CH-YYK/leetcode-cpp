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
    int longestPath(vector<int>& parent, string s) {
		// dfs starting from 0
		int n = s.size();
		graph = vector<vector<int>>(n);
		for(int i = 1; i < n; ++i) {
			graph[parent[i]].push_back(i);
		}
		int res = dfs(s, 0);
		return max(res, max_);
    }
private:
	int max_ = 0;
	vector<vector<int>> graph;
	int dfs(const string& s, int curr) {
		int first = 0, second = 0;
		for(int nxt : graph[curr]) {
			int len = dfs(s, nxt);
			if(s[curr] == s[nxt]) continue;
			if(len > first) {
				second = first;
				first = len;
			} else if(len > second)
				second = len;
		}
		if(first + second + 1 > max_)
			max_ = first + second + 1;
		return 1 + max(first, second);
	}
};