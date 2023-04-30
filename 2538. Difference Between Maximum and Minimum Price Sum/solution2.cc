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
	typedef long long ll;
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
		// cost = max price sum - root value
		// for each node, the cost can be computed with
		// 		1. max price sum from the parent
		//  	2. max price sums from children
		//		3. the role of parent and children could be swapped
		// two dfs's, root is fixed to be 0
    	// 		1. get all maximum price sum from children for each node
    	//		2. bring the max price sum of "other" children to each node
    	//			to compute the max price sTum from the parent
    	graph = vector<vector<int>>(n);
    	for(vector<int>& edge : edges) {
    		graph[edge[0]].push_back(edge[1]);
    		graph[edge[1]].push_back(edge[0]);
    	}
    	dfs(price, -1, 0);
    	return ans;
    }
private:
	vector<vector<int>> graph;
	ll ans = 0;
	pair<ll,ll> dfs(vector<int>& price, int parent, int curr) {
		// return <max path, max path except leaf>
		ll currmax1 = price[curr], currmax2 = 0;
		for(int nxt : graph[curr]) {
			if(nxt == parent) continue;
			auto [max1, max2] = dfs(price, curr, nxt);
			ans = max(ans, currmax1 + max2);
			ans = max(ans, currmax2 + max1);
			currmax1 = max(currmax1, max1 + price[curr]);
			currmax2 = max(currmax2, max2 + price[curr]);
		}
		return {currmax1, currmax2};
	}
};