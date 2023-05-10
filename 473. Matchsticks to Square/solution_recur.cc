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
    	// Using dfs, each ms[i] can be possibly placed into one of the 4 groups (buckets)
    	// Return true if the 4 groups have equal sum.
    	// 
    	// Early pruning: 
    	// 		Reduce some steps by not adding numbers to a bucket
    	// 		Adding to bucket happens when adding ms[i] won't make bucket sum exceed the side
    	// 		Sort decreasingly to add large numbers firstly as small numbers could result in 
    	// 		lots of redundant steps for "adding" and "popping".
    	int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    	int side = total / 4;
    	if(4 * side < total) return false;
    	sort(matchsticks.begin(), matchsticks.end(), greater<int>());
    	vector<int> sums(4, 0);
    	return dfs(matchsticks, 0, side, sums);
    }
private:
	bool dfs(vector<int>& ms, int i, int side, vector<int>& sums) {
		if(i == ms.size()) 
			return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3];

		for(int k = 0; k < 4; ++k) {
			if(sums[k] + ms[i] <= side) {
				sums[k] += ms[i];
				if(dfs(ms, i + 1, side, sums))
					return true;
				sums[k] -= ms[i];
			}
		}
		return false;
	}
};