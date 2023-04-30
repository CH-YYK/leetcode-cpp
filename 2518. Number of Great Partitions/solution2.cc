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
    	// 
    	// dp[i][k] = 1 if i == 0 || k == 0, i.e empty partition only
    	// total - dp[n][k-1] * 2: the *2 is to involve reversed versions
    	int n = nums.size();
    	int mod = 1e9 + 7;
    	long total = 1, sum = 2 * k;
    	vector<long> dp(k, 1);
    	for(int i = 0; i < n; ++i) {
    		for(int j = k - 1; j >= 1; --j) {
    			if(j >= nums[i])
    				dp[j] = (dp[j] + dp[j - nums[i]]) % mod; 
    		}
    		total = total * 2 % mod;
    		if(sum > 0) sum -= nums[i];
    	}
    	if(sum > 0) return 0;
    	return (total + mod - 2 * dp[k-1] % mod) % mod;
	}
};
