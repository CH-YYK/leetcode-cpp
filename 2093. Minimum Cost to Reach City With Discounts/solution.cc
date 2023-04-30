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
#include <array>

using namespace std;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        // at each node, we have two states: use discount and not use discount
        // use 2D-Dijkstra Algorithm
        // 
        // Why 2D, we may only can drop the state if, with equal discounts, the state has higher costs
        // 		so we need a 2D array to track the stats visited[N][D]
        // 
        // standard time complexity: O(N*D + (E*D)log(N*D))
        // 	1. The queue would be as large as N*D, so it take O(N*D) to enque and O(Log(N*D)) to deque
        //  2. The queue is dequed when the edge is to be traversed, and each edge can be possibly traversed
        //  3. O(N*D) + O((E*D) * log(N*D))
    	for(vector<int>& highway : highways) {
    		graph[highway[0]][highway[1]] = highway[2];
    		graph[highway[1]][highway[0]] = highway[2];
    	}

    	vector<vector<int>> visited(n, vector<int>(discounts + 1, INT_MAX));
    	priority_queue<array<int, 3>> q;  // max queue <-cost, discounts, node>
        q.push({0, discounts, 0});
        for(int i = 0; i <= discounts; ++i)
            visited[0][i] = 0;

    	int globalmin = INT_MAX;
    	while(!q.empty()) {
    		array<int, 3> curr = q.top();
    		int currnode = curr[2];
    		int currdisct = curr[1];
    		int currcosts = -curr[0];
       		
       		q.pop();
       		if(currnode == n - 1) {
       			if(currcosts < globalmin) 
	       			globalmin = currcosts;
	       		continue;
       		}

    		for(auto nxts : graph[currnode]) {
    			int nxtnode = nxts.first;
    			int cost = nxts.second;

    			if(currcosts + cost < visited[nxtnode][currdisct]) {
    				int nxtcosts = currcosts + cost;
    				if(nxtcosts <= globalmin) {
    					q.push({-nxtcosts, currdisct, nxtnode});
        				visited[nxtnode][currdisct] = nxtcosts;
    				}
    			}

    			if(currdisct == 0) continue;

    			if(currcosts + cost / 2 < visited[nxtnode][currdisct - 1]) {
    				int nxtcosts = currcosts + cost / 2;
    				if(nxtcosts <= globalmin) {
    					q.push({-nxtcosts, currdisct - 1, nxtnode});
                        visited[nxtnode][currdisct - 1] = nxtcosts;
    				}
    			}
    		}
    	}
     	return globalmin == INT_MAX ? -1 : globalmin;
    }
};

int main() {
    
}
