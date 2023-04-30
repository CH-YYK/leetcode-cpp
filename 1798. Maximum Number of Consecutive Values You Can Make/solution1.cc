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
    int getMaximumConsecutive(vector<int>& coins) {
		// 0-1 knapsack
    	// initialize: target = 1
    	//  1. if coin > target: then target cannot be make
    	//  2. if coin <= target: then values in [target, target + coin) can be made
    	// 		because [target - coin (>=0), target) has been made
    	// 
    	sort(coins.begin(), coins.end());
		int ans = 1; 
		for(int c : coins) {
			if(c > ans) break;
			ans += c;
		}
		return ans;
    }
};