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
    int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		vector<int> prefixSum(2 * n + 1, 0);
		for(int i = 0; i < 2 * n; ++i) {
			int idx = i % n;
			prefixSum[i + 1] = prefixSum[i] + nums[idx];
		}

		deque<int> dq;
		dq.push_back(0);
		int l = 0, ans = INT_MIN;
		for(int r = 0; r < 2 * n; ++r) {			
			if(r + 1 - l > n) {
				if(dq.front() < ++l)
					dq.pop_front();
			}
			ans = max(ans, prefixSum[r + 1] - prefixSum[dq.front()]);
			while(!dq.empty() && prefixSum[dq.back()] >= prefixSum[r + 1])
				dq.pop_back();
			dq.push_back(r + 1);
		}
		return ans;
    }
};