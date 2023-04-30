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
    int maxJump(vector<int>& stones) {
		// Some intuition
		// 1. What we are actually looking for is two non-overlapping paths
		// 2. Every stone should be used or a larger jump will be needed 
		// 
		// Suppose there are two frogs, assign the stones[i] to either of them
		// to make the maximal one step minimized

		// assume frog0 is always left to frog1
    	int frog0 = 0, frog1 = stones[1];
    	int cost = 0;
    	for(int i = 2; i < stones.size() - 1; ++i) {
    		cost = max(cost, stones[i] - frog0);
    		frog0 = stones[i];
    		swap(frog0, frog1);
    	}
    	return max(cost, max(stones.back() - frog0, stones.back() - frog1));
    }
};