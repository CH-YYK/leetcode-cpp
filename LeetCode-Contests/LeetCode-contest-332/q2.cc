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
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
    	sort(nums.begin(), nums.end());
    	int ans = 0;
    	for(int i = 0; i < nums.size(); ++i) {
    		// >= l - nj
    		auto l = upper_bound(nums.begin() + i + 1, nums.end(), lower - nums[i] - 1);
    		// > u - nj
    		auto h = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
			ans += (h - l);
    	}
    	return ans;
    }
};