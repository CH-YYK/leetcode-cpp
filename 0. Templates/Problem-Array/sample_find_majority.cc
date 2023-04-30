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

// the Boyer-Moore Voting algorithms: 
// 		Find the majority element if the majority has >= n/2
int findMajority(vector<int>& nums) {
	// The voting strategy: 
	// 	 Given a target, change nums to +1 if nums[i] == target
	//		and -1 if nums[i] != target
	// 
	// For a suffix of nums, `suf`
	// 	treat suf[0] as the target and apply the strategy

	// Imagine that we partition the nums to non-overlapping subarrays.
	// 	each subarray applies the strategy for subarray_i[0] 
	//  iff voting result for subarray_{i} is 0, the subarray_{i+1} is opened
	// 
	// proof: for each slice, slice[0] is the majority or one of the majorities
	// 	The overall majority is more than n/2, which means more than sum of others
	// 	So the it must dominated in one of the slices, i.e the last slice as our 
	// 	rule defined.
	int cnt = 0, target = -1;
	for(int num : nums) {
		if(cnt == 0) target = num;
		cnt += (num == target) ? 1 : -1;
	}
	return cnt > 0 ? target : -1;
}
