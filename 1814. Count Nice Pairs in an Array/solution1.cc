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
    int countNicePairs(vector<int>& nums) {
    	// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
    	// transform
    	// nums[i] - nums[j] == rev(nums[i])-rev(nums[j]);
    	// nums[i] - rev(nums[i]) = nums[j] - rev(nums[j])
    	// 2Sum
    	unordered_map<int,int> mp;
    	int mod = 1e9 + 7;
    	int ans = 0;
    	for(int num : nums) {
    		long revnum = 0;
    		long numcpy = num;
    		while(num) {
    			revnum = 10 * revnum + num % 10;
    			num /= 10;
    		}
    		long diff = numcpy - revnum;
    		ans = (ans + mp[diff]) % mod;
    		mp[diff] = (mp[diff] + 1) % mod;
    	}
    	return ans;
    }
};