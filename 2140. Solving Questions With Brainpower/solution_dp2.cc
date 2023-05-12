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
    	//
    	// The original problem looks like that the states are forward-dependent.
    	// So if we try looking backwards, we can make the problem "backward-dependent".
    	// And a basic DP pattern can be applied.
    	// 
        // If nums[i] is chosen, then nums[i + skip + 1] could be chosen. Let 
        // dp[i] := maximum points gained from question[i:].
        // dp[i] = max(p + dp[i+skip +1], dp[i+1])
    	//
        // Time complexity: O(N)
        int n = questions.size();

        // 0->skip, 1->pick, 2->offset
        long long dp[n];
        dp[n-1] = questions[n-1][0];

        for(int i = n - 2; i >= 0; --i) {
        	long long p = questions[i][0], step = questions[i][1];
        	dp[i] = dp[i + 1];
        	if(i + step + 1 < n)
        		p += dp[i + step + 1];
       		dp[i] = max(dp[i], p);
        }
        return dp[0];
    }
};