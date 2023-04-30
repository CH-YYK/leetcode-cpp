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
    int minMoves(vector<int>& nums, int k) {
    	// [0,6,7] -> [6,6,6] -> [5,6,7] = 7 - 2 = 5
    	// sum([6,6,6]) - sum([0,6,7])
    	vector<int> ones;
    	for(int i = 0; i < nums.size(); ++i)
    		if(nums[i] == 1) ones.push_back(i);
    	vector<long> presum(ones.size() + 1, 0);
    	for(int i = 0; i < ones.size(); ++i)
    		presum[i + 1] = presum[i] + ones[i];
    	int l = 0, ans = INT_MAX;
    	for(int r = k-1; r < ones.size(); ++r) {
    		int m = (l + r) / 2;
    		// m is not changed
    		long left = (m - l) * ones[m] - (presum[m] - presum[l]);
    		long right = (presum[r+1] - presum[m+1]) - (r - m) * ones[m];
    		// diff: 1 + 2 + .. l = l/2*(l+1)
    		// odd: (k-1)/2, even, k/2 - 1 ~= (k-1)/2;
    		int ld = (k - 1) / 2;
    		int rd = k - 1 - ld;
    		int cost = right + left - (ld + 1) * ld / 2 - (rd + 1) * rd / 2;
    		ans = min(ans, cost);
    		l++;
    	}
    	return ans;
    }
};