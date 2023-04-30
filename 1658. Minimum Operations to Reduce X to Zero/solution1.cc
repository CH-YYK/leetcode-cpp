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
    int minOperations(vector<int>& nums, int x) {
		// min operations to make x to 0
		// substrings from left/right to sum to x
		// find the longest substring that have total - x 
		int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
		int l = 0, maxlen = -1, cumsum = 0;
		for(int r = 0; r < nums.size(); ++r) {
			cumsum += nums[r];
			// l can be r because this subarray can be empty
			while(l <= r && cumsum > sum - x) {
				cumsum -= nums[l++];
			}
			if(cumsum == sum - x)
				maxlen = max(maxlen, r - l + 1);
		}
		return n - maxlen > n ? -1 : n - maxlen;
    }
};