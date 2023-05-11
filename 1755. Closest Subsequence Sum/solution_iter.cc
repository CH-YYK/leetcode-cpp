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
	int minAbsDifference(vector<int>& nums, int goal) {
		// iterative version
		// We only use DFS to construct the sums of subsequences, which can also be performed
		// in an iterative way. An iterative way could be beneficial to space.
		vector<int> left, right;
		int n = nums.size();
		for(int i = 0; i < n; ++i) {
			if(i < n / 2) left.push_back(nums[i]);
			else right.push_back(nums[i]);
		}
        // suppose both left and right give 0
		int ans = abs(goal);
		vector<int> lresults{0}, rresults{0};

		// iterative way to get sum of all subsequences (excluding 0)
		for(int num : left) {
			int size = lresults.size();
			for(int i = 0; i < size; ++i) {
                int sum = lresults[i] + num;
   				// assume the right sum give 0
				ans = min(ans, abs(sum - goal));
				lresults.push_back(sum);
			}
		}
		sort(lresults.begin(), lresults.end());

		for(int num : right) {
			int size = rresults.size();
			for(int i = 0; i < size; ++i) {
				int sum = rresults[i] + num;
				auto it = lower_bound(begin(lresults), end(lresults), goal - sum);
				if(it != lresults.end())
					ans = min(ans, abs(*it + sum - goal));
				if(it != lresults.begin())
					ans = min(ans, abs(*prev(it) + sum - goal));
                rresults.push_back(sum);
			}
		}
		return ans;
	}
};