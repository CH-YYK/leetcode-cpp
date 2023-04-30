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
    int subarraysDivByK(vector<int>& nums, int k) {
		// sum of subarrays div by k
		// prefixsum[i + 1] - prefixsum[j] = sum(nums(j,i))
		// if sum(nums(j,i)) % k == 0
		// prefixsum[i+1] === prefixsum[j] mod k
		int n = nums.size();
		vector<int> prefixSum(n + 1, 0);
		for(int i = 0; i < n; ++i)
			prefixSum[i + 1] = prefixSum[i] + nums[i];
		for(int i = 0; i < n; ++i)
			// offset the 
			prefixSum[i + 1] = (k + prefixSum[i + 1] % k) % k;
		unordered_map<int,int> mp;
		int ans = 0;
		for(int i = 0; i < prefixSum.size(); ++i) {
			ans += mp[prefixSum[i]];
			mp[prefixSum[i]]++;
		}
		return ans;
    }
};