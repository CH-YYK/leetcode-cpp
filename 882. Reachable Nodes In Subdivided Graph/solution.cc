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

using namespace std;


class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    	// Dijkatra algorithm
    	// maxMoves limited the distance from destination and source
    	// for each node, we only need to consider the state with maxMoves
    	// because that can potentially reach more other nodes
    	// 
    	// for every edge, the counted nodes consisted of nodes from one side (a)
    	// and nodes from the other (b), which is min(a + b, edge_i)
		vector<unordered_map<int, int>> graph(n);
		for(vector<int>& edge : edges) {
			graph[edge[0]][edge[1]] = edge[2];
			graph[edge[1]][edge[0]] = edge[2];
		}

		// Dijkastra
		// keep the largest maxMoves at each node
		priority_queue<pair<int, int>> pq; // maxqueue<move, node>
		pq.emplace(maxMoves, 0);
		vector<int> moves(n, -1);
		moves[0] = maxMoves;

		while(!pq.empty()) {
			int currMoves = pq.top().first;
			int currNode = pq.top().second;

            pq.pop();
			for(auto nxt : graph[currNode]) {
				int nxtMoves = currMoves - (nxt.second + 1);				
				if(nxtMoves <= moves[nxt.first])
					continue;
				moves[nxt.first] = nxtMoves;
				pq.emplace(nxtMoves, nxt.first);
			}
		}

		int res = 0;
		for(int currMoves : moves)
			res += (currMoves >= 0);
		for(vector<int>& edge : edges) {
			int a = moves[edge[0]] > 0 ? moves[edge[0]] : 0;
			int b = moves[edge[1]] > 0 ? moves[edge[1]] : 0;
			res += min(a + b, edge[2]);
		}
		return res;
    }
};

int main() {
    
}
