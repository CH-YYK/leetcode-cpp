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
    int minAbsDifference(vector<int>& nums, int goal) {
    	// using DFS 
    	// The nums.size() is 40 which is a really awkward number. It exactly exceeds the
    	//  limitations of using a bitmask. Let's try dividing the big nums into two parts 
    	// and run dfs individually. This step may take O(2*2^20). 
    	//
    	// After getting all possible subsequence sums for each, run binary search for each
    	// number to get a pair whose sum is closes to goal. This step may take O(klogk) with k = 2^20
    	// 
    	//  Overall its, O(22*2^20)	nealy 2*10^7
    	this->goal = goal;
    	int n = nums.size();
    	vector<int> left;
    	vector<int> right;
    	for(int i = 0; i < n; ++i)
    		if(i < n/2) left.push_back(nums[i]);
    		else right.push_back(nums[i]);

    	// process left and process right
		vector<int> leftresults, rightresults;
    	dfs(left, 0, 0, leftresults);
    	dfs(right, 0, 0, rightresults);

    	// sort rightresults so that we can enumerate elements in leftresults
    	// to search from rightresults.
    	sort(rightresults.begin(), rightresults.end());
    	int ans = INT_MAX;
    	for(int num : leftresults) {
    		int res = goal - num;
    		// find the value closest to res in right
    		auto it = lower_bound(rightresults.begin(), rightresults.end(), res);
            if(it != rightresults.end())
    		    ans = min(ans, abs(*it + num - goal));
    		if(it != rightresults.begin()) 
    			ans = min(ans, abs(*prev(it) + num - goal));
    	}
    	return ans;
    }
private:
	int goal;
	void dfs(vector<int>& nums, int i, int sum, vector<int>& outputs) {
		if(i == nums.size()) {
			outputs.push_back(sum);
			return;
		}
		dfs(nums, i + 1, sum + nums[i], outputs);
		dfs(nums, i + 1, sum, outputs);
	}
};