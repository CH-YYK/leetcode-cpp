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
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // dp[i][j] := max value of coins from piles[:i] with j coins
        // evaluation
        // k = 1, piles[:1] -> 1 from 1 pile
        // k = 2, piles[:1] -> 2 from 1 pile
        // k = 2, piles[:2] -> x from pile[0] & (2-x) from pile[1], x in [0,2]
        // ...
        // k = j, piles[:i] -> z from pile[i-1] & (j-k) from pile[:i-1], z in [0,j]
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for(int i = 0; i < n; ++i) {
        	for(int j = 1; j <= k; ++j) {
        		int sum = 0;
        		for(int z = 0; z <= min(j, (int)piles[i].size()); ++z) {
        			// z elements from piles[i], while (j + 1 - z) from piles[:i]
                    if(z > 0)
        			  sum += piles[i][z-1];
        			dp[i+1][j] = max(dp[i+1][j], dp[i][j - z] + sum);
        		}
        	}
        }
        return dp[n][k];
    }
};