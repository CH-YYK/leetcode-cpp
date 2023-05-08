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
    	sort(nums.begin(), nums.end());
    	long ans = 0;
    	for(int i = 0; i < nums.size(); ++i) {
    		if(nums[i] * 2 > target) break;
    		auto maxid = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin() - 1;
    		// any subsequence will work for nums[i] and num[i+1:maxid]
    		ans += binpow_iter(2, maxid - i);
    	}
        return ans % kMod;
    }
private:
	int kMod = 1e9 + 7;
	int binpow_iter(long long a, long long n) {
		long long res = 1;
		while(n > 0) {
			if(n % 2) 
				res = res * a % kMod;
			a = a * a % kMod;
			n /= 2; // b >>= 1
		}
		return res % kMod;
	}
};