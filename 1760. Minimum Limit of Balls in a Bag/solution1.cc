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

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
		// binary search: min(max)
		// If there is 1 operation, divided evenly, eg 9=4+5
		// If there is 2 operation, 9=6+3=3+3+3
		// 
		// Given `nums` and target `penalty`
		// resolve: find the `penalty` that cost as much as `maxOperations`
		// 	to make
		// Time: O(Nlog(2^32)) = O(32N) = O(N)
		ios_base::sync_with_stdio(0); 
		cin.tie(NULL);
		if(nums.empty()) return 0;
    	function<int(int&,int&)> op = [](int& num, int& p) {
    		// 9,3 -> 2
    		// 9,4 -> 2
    		// 8,4 -> 1
    		return (num - 1) / p;
    	};

		int l = 1, r = 1e9;
		while(l < r) {
			int m = l + (r - l) / 2;
			int ops = 0;
			for(int num : nums) 
				ops += op(num, m);
			// high penalty -> low ops
			if(ops <= maxOperations)
				r = m;
			else 
				l = m + 1;
		}
		return l;
    }
};

