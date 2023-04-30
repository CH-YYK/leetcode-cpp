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
    int singleNonDuplicate(vector<int>& nums) {
    	// numbers are double except one
    	// binary search -> choose which side to go next, here
    	//  we always choose the side with the odd size
    	// 
    	// if(nums[m] == nums[m+1]) examine whether nums(m, r) is odd-sized.
    	// if(nums[m] == nums[m-1]) examine whether nums(l, r) is odd-sized.
    	int l = 0, r = nums.size() - 1;
    	while(l < r) {
    		int m = (l + r) / 2;
    		if(nums[m] == nums[m + 1]) {
    			if((r - m + 1) % 2 == 0)
    				r = m - 1;
    			else 
    				l = m + 2;
    		} else if(nums[m] == nums[m - 1]) {
    			if((m - l + 1) % 2 == 0)
    				l = m + 1;
    			else 
    				r = m - 2;
    		} else return nums[m];
    	}
    	return nums[l];
    }
};