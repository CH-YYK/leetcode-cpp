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
    int maxNumOfMarkedIndices(vector<int>& nums) {
    	// biparty
    	// an n-size array only have at most n/2 pairs
    	// so let's split the array into two groups, lefthalf and righthalf
    	// 
    	// why we don't care about in-group pairs?
    	// 	 e.g. if a1 and b1 are both in left half
    	// 	 suppose (a1, a2) and (b1, b2) both valid
    	// 	 1. if (a1, b1) work, then (a1, a2) must work. 
    	//	 2. since (a2, b2) is less possiblly valid, if it's not
    	//		- (a1, b1) is worse
    	// 		- they are equal
    	// 	 3. if (b1, b2) is invalid, (a2, b2) must be invalid
    	//		- (a1, b1) is equal to (a2, b2)
    	//		- but a2 is less possibly to be paired than b1
    	//     
    	int n = nums.size();
    	int l = 0, h = n / 2;
    	int ans = 0;
    	sort(nums.begin(), nums.end());
    	while(l < n/2 && h < n) {
    		if(nums[l] * 2 <= nums[r]) 
    			ans += 2, l++, h++;
    		else
    			h++;
    	}
    	return ans;
    }
};