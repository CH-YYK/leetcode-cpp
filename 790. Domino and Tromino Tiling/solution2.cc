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
    int numTilings(int n) {
    	// dp[i][state]: number of ways to fill grid[:i]
    	// state: 
    	// 		1. 0: only fill 0th
    	// 		2. 1: only fill 1st
    	//		3. 2: must fill both
    	int mod = 1e9 + 7;
    	long a2 = 1;
    	// initial state
    	long b0 = 0, b1 = 0, b2 = 1;

    	for(int i = 1; i < n; ++i) {
    		long c0 = b1, c1 = b0, c2 = b0 + b1 + b2;
    		if(i >= 1) {
    			c0 = (c0 + a2) % mod;
    			c1 = (c1 + a2) % mod;
    			c2 = (c2 + a2) % mod;
    		}
    		a2 = b2;
    		b0 = c0, b1 = c1, b2 = c2;    		
    	}
    	return b2;
    }
};