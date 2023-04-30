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

// 0-1 knapsack problem
// Given an array, nums[i]>0, find number of subsets with sum equal to target
int solve(vector<int>& nums, int target) {
	// dp[i][k]:= number of subsets with sum k created by nums[:i]
	// dp[i][k] = dp[i-1][k - nums[i-1]] + dp[i-1][k]
	// 
	// space decomposition
	// dp[k] = dp[k - nums[i-1]] + dp[k]
	int n = nums.size();
	vector<int> dp(target + 1, 0);
	dp[0] = 1;

	for(int i = 0; i < n; ++i) {
		for(int j = target; j >= 0; --j) {
			dp[j] = dp[j - nums[i]] + dp[j];
		}
	}
	return dp[target];
}