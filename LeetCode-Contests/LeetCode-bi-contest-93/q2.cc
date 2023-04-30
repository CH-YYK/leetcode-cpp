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
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
    	int n = vals.size();
    	vector<vector<pair<int,int>>> graph(n); // <val, idx>
    	for(vector<int>& edge : edges) {
    		graph[edge[0]].emplace_back(vals[edge[1]], edge[1]);
    		graph[edge[1]].emplace_back(vals[edge[0]], edge[0]);
    	}
    	int ans = INT_MIN;
    	for(int i = 0; i < n; ++i) {
    		sort(graph[i].begin(), graph[i].end(), greater<pair<int,int>>());
    		int sum = vals[i];
    		ans = max(ans, sum);
    		for(int j = 0; j < min(k, (int)graph[i].size()); ++j) {    			
    			sum += graph[i][j].first;
	    		ans = max(ans, sum);
    		}

    	}
    	return ans;
    }
};