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

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find right most k, that nums[k] < nums[k+1]
        // 		nums[k:] should be rearranged to get the next greater
        // find a smallest nums[l] from nums[k:] that have nums[l] > nums[k]
        // 		(mostly nums[k+1:] is always desc)
        // swap nums[l] and nums[k] and sort asc nums[k+1:]
        int n = nums.size();
        int k = n - 2;
        while(k < n - 1 && k >= 0 && nums[k] >= nums[k+1])
        	--k;
        if(k < 0) {
        	// already max, back to min
        	reverse(nums.begin(), nums.end());
        	return;
        }
        int l = n - 1;
        auto it = lower_bound(nums.begin() + k + 1, nums.end(), nums[k], greater<int>());
        int l = it - nums.begin() - 1;
        swap(nums[k], nums[l]);
        // the segment has orginally desc, just reverse to make it ASC
        reverse(nums.begin() + k + 1, nums.end());
    }
};