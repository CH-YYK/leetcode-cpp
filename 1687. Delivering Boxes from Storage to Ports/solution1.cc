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

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
  		// this is not greedy, we don't always load as much as we can for the ship e.g
    	// each [ports] is a partition of ports that the ship is going to deliver
  		// - [1 1 1], [2 2 2 2], -> 2 + 2 = 4
  		// - [1 1 1 2], [2 2 2] -> 3 + 2 = 5
  		// - [1 1 1 2 2 2 2] -> 3
  		// Load same ports as much as possible, load mixed ports only when the ship is large enough
  		// 
  		// Knapsack problem: partition the boxes such that each partition can be loaded under maxBoxes and maxWeight
  		// return the minimum cost (trip) each partition would take
  		// The cost (trips) can be computed by 1 + (# of port changes) + 1
  		// 									   go  						 return
    	// dp[i] := minimum trips for boxes[:i]
    	// dp[i] = min_j(dp[j] + cost(boxes[j : i])) where boxes[j:i] can be loaded, 
    	// 			i.e i-j <= maxBoxes and Weights(boxes[j:i]) <= maxWeight
    	// dp[0] = 0;

    	// O(NK) := N: boxes.size() and K, maxBoxes

    	int n = boxes.size();

    	vector<int> dp(n + 1, INT_MAX);
    	dp[0] = 0;

    	for(int i = 1; i <= n; ++i) {
    		int weight = 0;
    		int changeports = 1;
    		for(int j = i - 1; j >= 0; --j) {
                weight += boxes[j][1];
    			if(j < i - 1 && boxes[j][0] != boxes[j+1][0])
    				changeports++;
    			if(i - j <= maxBoxes && weight <= maxWeight)
    				dp[i] = min(dp[i], dp[j] + changeports + 1);
                else break;
    		}
    	}
    	return dp[n];
    }
};

int main() {
    
}
