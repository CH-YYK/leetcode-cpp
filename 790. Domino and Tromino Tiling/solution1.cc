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
    	vector<vector<long>> dp(n + 1, vector<long>(3, 0));
    	dp[0][2] = 1;
    	// initial state
    	for(int i = 0; i < n; ++i) {
    		dp[i + 1][0] = dp[i][1];
    		dp[i + 1][1] = dp[i][0];
    		dp[i + 1][2] = dp[i][1] + dp[i][0] + dp[i][2];
    		if(i >= 1) {
    			dp[i + 1][0] = (dp[i + 1][0] + dp[i-1][2]) % mod;
    			dp[i + 1][1] = (dp[i + 1][1] + dp[i-1][2]) % mod;
    			dp[i + 1][2] = (dp[i + 1][2] + dp[i-1][2]) % mod;
    		}
    	}
    	return dp[n][2];
    }
};