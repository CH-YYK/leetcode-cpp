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
    long long kSum(vector<int>& nums, int k) {
		// construct a sequence for first k largest elements
		// the 1st largest S1 is the sum of all positives

    	// k <= 2000, dfs for exactly k steps?
    	// 
    	// in a dfs, 
    	//   for each positive, we may have sum -= nums[i] or do nothing
    	//   for each negative, we may have sum += nums[i] or do nothing
    	// 
    	// however, dfs can riskily go too deep to overflow
    	// 
    	// in an iterative way, have index pointed to the newly modified element
    	//   for each positive, we may have (reverse subtracting nums[i] or not reverse)
    	// 						sum -= nums[i+1], sum += nums[i]
    	// 						sum -= nums[i+1]
    	//   for each negative, we may have (reverse adding nums[i] or not reverse) 
    	//						sum += nums[i+1], sum -= nums[i]
    	// 						sum += nums[i+1]
    	//
    	// in general, it will always be
    	// 						sum -= abs(nums[i+1]), optionally sum += abs(nums[i])
    	//	
    	sort(nums.begin(), nums.end(), [](int a, int b) {return abs(a) < abs(b);});
    	long long ans = accumulate(nums.begin(), nums.end(), 0LL, [](long long sum, int n) {return sum + max(0, n);});
    	// maxheap
    	priority_queue<pair<long long, int>> pq;
    	pq.push({ans - abs(nums[0]), 0});

    	// --k: 
    	// range [k, 2], 
    	// steps k-1;

    	// k--:
    	// range [k, 1]
    	// steps k
    	while(--k) {
    		auto [sum, i] = pq.top();
    		pq.pop();
    		if(i + 1 < nums.size()) {
    			pq.push({sum - abs(nums[i+1]), i + 1});
    			pq.push({sum - abs(nums[i+1]) + abs(nums[i]), i + 1});
    		}
    		ans = sum;
    	}
    	return ans;
    }
};