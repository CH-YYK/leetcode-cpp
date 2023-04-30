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
    int minMaxGame(vector<int>& nums) {
		int n = nums.size();
		while(n > 1) {
			for(int i = 0; i < n; i += 2) {
				if((i / 2) & 1)
					nums[i / 2] = max(nums[i], nums[i+1]);
				else
					nums[i / 2] = min(nums[i], nums[i+1]);
			}
			n >>= 1;
		}
		return nums[0];
    }
};