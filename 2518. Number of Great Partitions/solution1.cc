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
    int countPartitions(vector<int>& nums, int k) {
    	// break nums into two partitions with each sum >= k
    	// find ways to partition with sum < k
    	// regular knapsack problem
    	// dp[i][k] := number of ways to partition nums[:i] under k
    	// dp[i][k] = dp[i-1][k-nums[i-1]] + dp[i-1][k]
    	// total - dp[n][k-1] * 2: the *2 is to involve reversed versions
    	int n = nums.size();
    	vector<vector<long>> dp(n +1, vector<long>(k, 1));
    	for(int i = 0; i < n; ++i) {
    		for(int j = 0; j < k-1; ++j) {
    			dp[i+1][j+1] = dp[i][j + 1];
    			if(j + 1 >= nums[i])
    				dp[i+1][j+1] = dp[i+1][j+1] + dp[i][j+1-nums[i]];
    		}
    	}
    	long total = 1 << n;
    	return (total - 2 * dp[n][k - 1]);
	}
};