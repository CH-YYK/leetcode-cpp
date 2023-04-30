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
    int squareFreeSubsets(vector<int>& nums) {
		// 01 knapsack
		// dp[i][k] := number of subsets that have product k for nums[:i]
		// dp[i][k] = dp[i-1][k / nums[i-1]] + dp[i-1][k]
		// 
		// Since the product, k, can be as larget as 30 ^ 1000, need to find another way for compaction
		// Because each number is under 30, and rule of decomposition, each number can be projected to 
		// 	{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}
		// 		e.g. 3 -> 0100000000
		//			 4 -> 2000000000
		// 
		// After we project all numbers to these prime factors, a subset can also be projected to these primes
		// 	by summation. e.g. {3,4} -> 2100000000
		// If a subset of nums is "square-free", then all elements in the projection should be 1 or 0.
		// Let's use binary numbers to represent the projections -> k = memo <= 2^10
		// 
		// dp[i][k] := number of subsets that have product projection k for nums[:i]
		// dp[i][k] = dp[i-1][k - nums[i-1]] + dp[i-1][k] iff nums[i-1]'s projection only have 0,1
		vector<long> dp(1 << 10, 0);
		int maxState = (1 << 10) - 1;
		int mod = 1e9 + 7;
		dp[0] = 1;
		for(int i = 0; i < nums.size(); ++i) {
			int currState = getProjectionState(nums[i]);
			if(currState == -1) continue;
			for(int j = maxState; j >= currState; j--) {
				// different from direct subtraction, use subtraction only when 
				// 	every digit in j is >= that in currState, like 1111 - 0110
				// 	i.e. (j & currState) == currState
				if((j & currState) == currState)
					dp[j] = (dp[j] + dp[j - currState]) % mod;
			}
		}
		return accumulate(dp.begin(), dp.end(), -1l) % mod;
    }
private:
	vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
	int getProjectionState(int num) {
		int state = 0;
		for(int i = 0; i < primes.size(); ++i) {
			int cnt = 0;
			while(num % primes[i] == 0) {
				num /= primes[i];
				cnt++;
			}
			if(cnt > 1) return -1;
			state |= (cnt << i);
		}
		return state;
	}
};