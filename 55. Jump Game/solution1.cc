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
    bool canJump(vector<int>& nums) {
		// nums[i]:= maximum jump
		// find a path that can reach last index
		//  an index can be reached iff it's in the "jump range"
		// dp[i]:= maximum jump range from nums[:i]
		// dp[i + 1] = max(d[i] - 1, nums[i]) if dp[i] >= 1: can reach nums[i]
		// dimension reduction
		int n = nums.size();
		vector<int> dp(n + 1, 0);
		// initialize from first index
		dp[0] = 1;
		for(int i = 0; i < n; ++i)
			if(dp[i] >= 1)
				dp[i + 1] = max(dp[i] - 1, nums[i]);
			else return false;
		return true;
    }
};