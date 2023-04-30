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
    long long beautifulSubarrays(vector<int>& nums) {
        // a subarray is beautiful if all elements can be zeros
        // 
    	// If the kth bit of nums[i] and nums[j] are 1, they can be removed for both numbers.
    	// This is equivalent to (nums[i] ^ nums[j])
        // 
        // So a beautiful subarray means that the subarray's XOR is 0
        // 
        // Transform the problem to a 2-Sum, XOR[:i] -> cumulative XOR for nums[:i]
        //   that is, if XOR[i] == XOR[j]. then nums[j:i] is beautiful
    	int n = nums.size();
    	vector<int> prefix(n + 1, 0);
    	for(int i = 0; i < n; ++i)
    		prefix[i + 1] = prefix[i] ^ nums[i];
    	long long ans = 0;
    	unordered_map<int, int> mp;
    	for(int i = 0; i < prefix.size(); ++i) {
    		ans += mp[prefix[i]];
    		mp[prefix[i]]++;
    	}
    	return ans;
    }
};