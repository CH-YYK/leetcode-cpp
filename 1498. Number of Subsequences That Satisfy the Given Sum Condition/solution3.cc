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
    int numSubseq(vector<int>& nums, int target) {
    	// sort and enumerate every pair of [min, max]
    	// construct subsequences based each pair.
    	// Use two pointer per step to find min and max
    	// Precalculate the powers of 2.
    	int n = nums.size();
    	int kMod = 1e9 + 7;
    	sort(nums.begin(), nums.end());
    	vector<long> powsers(n + 1, 1);
    	for(int i = 1; i <= n; ++i) 
    		powsers[i] = powsers[i-1] * 2 % kMod;

        long ans = 0;
    	int l = 0, r = n - 1;
    	while(l < n && nums[l] * 2 <= target) {
    		while(nums[l] + nums[r] > target)
    			r--;
    		// construct subsequence with nums[l] and any numbers in [l+1, r];
    		ans += powsers[r - l];
            l++;
    	}
        return ans % kMod;
    }
};