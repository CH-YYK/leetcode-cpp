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
    long long findTheArrayConcVal(vector<int>& nums) {
		int n = nums.size();
		int l = 0, r = n - 1;
		long long ans = 0;
		while(l <= r) {
			if(l == r) return ans + nums[l];
			int base = 1;
			while(base <= nums[r])
				base *= 10;
			ans += nums[l++] * base + nums[r--];
		}
		return ans;
    }
};