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
    long long mostPoints(vector<vector<int>>& questions) {
        // Using DP
        // dp[i] := maximum points earned from questions[:i]
        // 
        // For each i, and 	p,step = questions[i]
        //	  1. solve question[i] -> dp[i+1 + step + 1] = max(dp[i+1] + p);
        //    2. skip question[i] -> dp[i+1] = dp[i]
        //    3. pass forward offset
        // 
        // offset: picking nums[i] won't impact decisions on nums[(i + step + 1):]
        // 	  so dp[i+1 + step + 1] >= dp[i+1] + points
        int n = questions.size();

        // 0->skip, 1->pick, 2->offset
    	vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));

    	for(int i = 0; i < n; ++i) {    		
    		int p = questions[i][0];
    		int nxt = i + 1 + questions[i][1] + 1;
    		// in-case offset is not written
            dp[i + 1][2] = max(dp[i][2], dp[i+1][2]);

    		// skip, can have i-1 picked/skipped or directly from offset
    		dp[i + 1][0] = max(dp[i + 1][2], max(dp[i][0], dp[i][1]));

    		// solve, increment from the offset
    		dp[i + 1][1] = dp[i + 1][2] + p;

    		// noimpact to dp[nxt][:]
            if(nxt <= n) dp[nxt][2] = max(dp[i+1][1], dp[nxt][2]);
    	}
    	return max(dp[n][0], dp[n][1]);
    }
};