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
		// following the intuition
		// it's obviously that we are actually assign the stone to 
		// two frogs one by one
		//
		// there are actually only two paths (odd and even)
		int cost = 0, dest = stones.back();
		int prev = 0;
		for(int i = 2; i < stones.size() - 1; i += 2) {
			cost = max(cost, stones[i] - prev);
			prev = stones[i];
		}
		cost = max(cost, dest - prev);

		for(int i = 3; i < stones.size() - 1; i += 2) {
			cost = max(cost, stones[i] - prev);
			prev = stones[i];
		}
		cost = max(cost, dest - prev);
		return cost;
    }
};