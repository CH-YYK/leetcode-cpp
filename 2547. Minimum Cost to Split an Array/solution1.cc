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
    int minCost(vector<int>& nums, int k) {
		// partition the nums and minimized the sum of importance values
		// the k is like a Sunk cost of each split
		// dp[i] := minimized cost to split nums[:i]
		// dp[i] = min(dp[j] + (k + trimmed(nums[j:i])))
		// DP would take O(N^2) but trimmed(..) would take an extra N
		//
		// compute trimmed on the fly
		// trimmed(nums[j:i]) := i - j - singleValues(nums[j:i])
		// 1. we can cumulate singleValues of nums[j:i] by moving j from i to 0
		// 2. singleValues(nums[j:i]) = singleValues(nums[j+1:i]) 
		// 		* -1 if freq[nums[j]] == 1
		//	 	* +1 if freq[nums[j]] == 0
		// 		* +0 if freq[nums[j]] > 1
		int n = nums.size();
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for(int i = 0; i < n; ++i) {
			vector<int> freq(n, 0);
			int singles = 0;
			for(int j = i; j >= 0; --j) {
				if(freq[nums[j]] == 0)
					singles++;
				else if(freq[nums[j]] == 1) 
					singles--;
				dp[i + 1] = min(dp[i+1], dp[j] + (k + i + 1 - j - singles));`
				freq[nums[j]]++;
			}
		}
		return dp[n];
	}	
};