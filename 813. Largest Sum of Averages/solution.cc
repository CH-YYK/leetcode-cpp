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
    double largestSumOfAverages(vector<int>& nums, int k) {
        // partition the array into k non-overlapping subarrays
        // the score is the sum of their averages
        // use DP
        // 
        // DP state transition:
        // dp[i][k] := maximum score to partition nums[:i] into k partitions.
        // dp[i][k] = max(dp[j][k-1] + sum(nums[j:i]) / (i - j)); for all j,k
        // 
        // Initialize the DP states:
        // dp[0][0] = 0
        // dp[i][1] = sum(nums[:i]) / i, i >= 1
    	// complexity: time: O(K*N^2), space: O(N^K)

		int n = nums.size();

		// use prefixSum to optimize computing subarray average
        // sum(nums[j:i]) = (presum[i] - presum[j]) / (i - j), i > 0, 0 <= j < i
		vector<double> prefixSum(n + 1, 0);
		for(int i = 0; i < n; ++i)
			prefixSum[i + 1] = prefixSum[i] + nums[i];

		// prepare dp
		vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0));
        for(int i = 0; i < n; ++i)
            dp[i + 1][1] = prefixSum[i + 1] / (i + 1);
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < i; ++j) {
				for(int z = 2; z <= min(i, k); ++z) {
                    dp[i][z] = max(dp[i][z], 
                                   dp[j][z-1] + 1.0 * (prefixSum[i] - prefixSum[j]) / (i - j));
				}
			}
		}
		return dp[n][k];
    }
};
int main() {
    
}
