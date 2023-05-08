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
    int minIncrements(int n, vector<int>& cost) {
    	// There will only be one path sum after compute bottom-up to root
    	// each child should catch up with the other to make the path sum equal
    	// because the rest of the paths are same.
    	// 
    	// So, at each level, we'll have 
    	//   ans += abs(child1 - child2);
    	//   root += max(child1, child2);
    	// 
    	// n/2 is the first index of leaves
    	int ans = 0;
    	for(int i = n/2-1; i >= 0; --i) {
    		int l = 2 * i + 1, r = 2 * i + 2;
    		ans += abs(cost[l] - cost[r]);
    		cost[i] += max(cost[l], cost[r]);
    	}
    	return ans;
    }
};