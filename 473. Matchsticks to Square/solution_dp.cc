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
    bool makesquare(vector<int>& matchsticks) {
    	// Partition the matchsticks into 4 groups with each of them equal to the side
    	// 
    	// Using dp. pick 1 number per round to form a side and start a new side after 
    	//		the last one complete. This is a feasible way because there are at most 
    	// 		15 numbers so we can track the usage of each number by using a bitmap.
    	// 		
    	//	 	It's just like we are re-arranging matchsticks to be evenly distributed in
    	//	 	4 groups.
    	// 		
    	//		Use `memo` to keep track of <state, formed_side> to avoid redundant calculations
    	//      Each <state, formed_side>:true means that using the numbers represented by `state` can form
    	// 		build `formed_side` and ultimately can give 4 sides.
    	int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    	sidelen = total / 4;
    	if(4 * sidelen < total) return false;
    	return dp(matchsticks, 0, 0, sidelen);
    }
private:
	int sidelen = 0;
	map<pair<int,int>, bool> memo;
	bool dp(vector<int>& ms, int formed, int state, int side) {
		if(formed == 4) return true;
		if(side == 0)
			return dp(ms, formed + 1, state, sidelen);

		if(memo.count({state, formed}))
			return memo[{state, formed}];
		// pick a number to form the side
		for(int i = 0; i < ms.size(); ++i) {
			if(state & (1 << i)) continue;
			if(ms[i] <= side) {
				side -= ms[i];
				if(dp(ms, formed, state | (1 << i), side))
					return memo[{state, formed}] = true;
				side += ms[i];
			}
		}
		return memo[{state, formed}] = false;
	}
};