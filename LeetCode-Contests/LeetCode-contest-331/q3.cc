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
    int minCapability(vector<int>& nums, int k) {
		// min cap
		// at least k houses
		// no adjacent 
		// given cap, maximum houses that can be robbed? (dp)
		int l = 0, r = *max_element(nums.begin(), nums.end());
		while(l < r) {
			int m = l + (r - l) / 2;
			int cnt = maxHouses(nums, m);
			if(cnt >= k)  // decrease cap, decrease cnt
				r = m;
			else l = m + 1;
		}
		return l;
    }
private:
	int maxHouses(vector<int>& nums, int cap) {
		// 0: not rob, 1: rob
		int a = 0, b = 0;
		if(nums[0] <= cap) b = 1;
		int ans = 0;
		for(int i = 1; i < nums.size(); ++i) {
			int a1, b1;
			a1 = max(a, b);
			b1 = a + (nums[i] <= cap);
			a = a1, b = b1;
		}
		return max(a, b);
	}
};