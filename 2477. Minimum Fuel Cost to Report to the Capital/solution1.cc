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
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
		// using dfs to get the size of subtree
		// Given a subtree, cost of liter per step is (size(subtree) + seats - 1 / seats)
		int n = roads.size() + 1;
		num = seats;
		graph = vector<vector<int>>(n);
		for(vector<int>& road : roads) {
			graph[road[0]].push_back(road[1]);
			graph[road[1]].push_back(road[0]);
		}
		int res = 0;
		for(int nxt : graph[0]) {
			res += dfs(nxt, 0).second;
		}
		return res;
    }
private:
	vector<vector<int>> graph;
	int num = 0;
	pair<int, int> dfs(int curr, int prev) {
		int size = 1, liter = 0;
		for(int nxt : graph[curr]) {
			if(nxt == prev) continue;
			auto [s, l] = dfs(nxt, curr);
			size += s;
			liter += l;
		}
		return {size, liter + (size + num - 1) / 2};
	}
};