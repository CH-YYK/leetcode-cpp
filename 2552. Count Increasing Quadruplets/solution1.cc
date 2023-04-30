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
    long long countQuadruplets(vector<int>& nums) {
		// find i,j,k,l where nums[i] < nums[k] < nums[j] < nums[l]
		// for any (j,k) nums[k] < nums[j]
		// 	the # of Quadruplets is 
		// 		num(val < nums[k] for i < j) * num(val > nums[j] for l > k)
		// let dp[i][val]: number of nums[j] < val for j < i
		// dp[i][val] := dp[i-1][val] + nums[i] < val
		int maxVal = *max_element(nums.begin(), nums.end());
		int n = nums.size();
		vector<vector<long long>> dp(n + 1, 
			vector<long long>(maxVal + 2, 0));

		for(int i = 0; i < n; ++i) {
			for(int val = 1; val <= maxVal + 1; ++val) {
				dp[i + 1][val] = (nums[i] < val) + dp[i][val];
			}
		}
		// O(N^2)
		long long ans = 0;
		// nums[i] < nums[k] < nums[j] < nums[l]
		for(int j = 1; j < n - 2; ++j) {
			for(int k = j + 1; k < n - 1; ++k) {
				if(nums[k] >= nums[j]) continue;
				// num(< nums[k]) * num(>nums[j])
				// num(<nums[k]) * (n - k - 1 - num(<=nums[j]))
				ans += dp[j][nums[k]] * (n - k - 1 - 
					(dp[n][nums[j] + 1] - dp[k+1][nums[j] + 1]));
			}
		}
		return ans;
	}
};