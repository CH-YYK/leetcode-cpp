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

// Kadane's Algorithms: get the maximum subarray sum
int getMaximumSubarraySumWithDP(vector<int>& nums) {
	// Dynamic programming	
	// dp[i]:= maximum suffix sum ended at nums[i]
	// dp[i] = max(dp[i-1], 0) + nums[i];	
	vector<int> dp(n, 0);
	for(int i = 0; i < n; ++i)
		dp[i] = max(dp[i-1], 0) + nums[i];
	return *max_element(dp.begin(), dp.end());
}

int kadaneAlgo(vector<int>& nums){
	int max_ = 0;
	int ans = INT_MIN;
	for(int num : nums) {
		max_ = max(max_, num) + num;
		ans = max(ans, max_);
	}
	return ans;
}