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
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    	// assume we can enumerate all possibilities of subsequences
    	// vector is non hashable, use set to dedupe.
    	// Time: (2 ^ n * n * log(2^n))

    	int n = nums.size();
    	set<vector<int>> ans;
    	for(int i = 1; i < (1 << n); ++i) {
    		vector<int> sequence;
    		bool isNonDescending = __builtin_popcount(i) > 1;
    		int prev = -1;
    		for(int j = 0; j < n; ++j) {
    			if((i & (1 << j)) == 0) continue;
    			if(prev != -1 && nums[j] < nums[prev]) {
    				isNonDescending = false;
    				break;
    			}
    			prev = j;
    		}
    		if(!isNonDescending) continue;
    		for(int j = 0; j < n; ++j) {
    			if((i & (1 << j)) == 0) continue;
    			sequence.push_back(nums[j]);
    		}
    		ans.insert(sequence);
    	}
		return vector<vector<int>>(ans.begin(), ans.end());
    }
};