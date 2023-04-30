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
    long long countGood(vector<int>& nums, int k) {
		// sliding window
		// window: hashmap: <num, cnt>
		// sum(cnt*(cnt+1)/2) >= k
    	int l = 0, total = 0, n = nums.size();
    	long long ans = 0;
    	unordered_map<int,int> mp;
    	for(int r = 0; r < nums.size(); ++r) {
    		total += mp[nums[r]];
    		mp[nums[r]]++;
    		while(total >= k) {
    			// [l,r] already satisfy
    			// so all the rest subarrays can satisfy
    			ans += n - r;
    			total -= --mp[nums[l++]];
    		}
    	}
    	return ans;
    }
};