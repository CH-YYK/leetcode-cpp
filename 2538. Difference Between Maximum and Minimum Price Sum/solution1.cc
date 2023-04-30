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
    	graph = vector<unordered_map<int,ll>>(n);
    	for(vector<int>& edge : edges) {
    		graph[edge[0]][edge[1]] = 0;
    		graph[edge[1]][edge[0]] = 0;
    	}
    	costs = vector<ll>(n, 0l);
    	childrens = vector<pair<ll,ll>>(n, make_pair(0, 0));
    	findChildrenSum(price, -1, 0);
    	provideParentSum(price, -1, 0, 0);
    	return *max_element(costs.begin(), costs.end());
    }
private:
	vector<unordered_map<int, ll>> graph;
	vector<pair<ll,ll>> childrens; // <max, second_max>
	vector<ll> costs;
	int findChildrenSum(vector<int>& price, int parent, int curr) {
		for(auto [nxt, _] : graph[curr]) {
			if(nxt == parent) continue;		
			int sum = findChildrenSum(price, curr, nxt);
			graph[curr][nxt] = sum;
			if(sum > childrens[curr].first) {
				childrens[curr].second = childrens[curr].first;
				childrens[curr].first = sum;
			} else if(sum > childrens[curr].second)
				childrens[curr].second = sum;
		}
		return childrens[curr].first + price[curr];
	}

	void provideParentSum(vector<int>& price, int parent, int curr, ll parentSum) {
		costs[curr] = max(childrens[curr].first, parentSum);
		for(auto [nxt, sum] : graph[curr]) {
			if(nxt == parent) continue;
			if(sum == childrens[curr].first)
				provideParentSum(price, curr, nxt, 
					max(childrens[curr].second, parentSum) + price[curr]);
			else
				provideParentSum(price, curr, nxt, 
					max(childrens[curr].first, parentSum) + price[curr]);
		}		
	}
};