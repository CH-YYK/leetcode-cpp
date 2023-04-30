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
    int waysToReachTarget(int target, vector<vector<int>>& types) {
  		// 
  		// dp[i][k]:= number of ways for target k within types[:i] 
  		// dp[i][k] = dp[i][k - x*mark] + dp[i-1][k]
  		int n = types.size();
  		int mod = 1e9 + 7;
  		vector<vector<long>> dp(n + 1, vector<long>(target + 1, 0));
        dp[0][0] = 1;

  		for(int i = 0; i < n; ++i) {
  			int cnt = types[i][0];
  			int mark = types[i][1];
  			for(int k = target; k >= 0; --k) {
  				for(int j = 0; j <= cnt; ++j) {
  					if(k >= j * mark)
	  					dp[i + 1][k] = (dp[i + 1][k] + dp[i][k - j * mark]) % mod;
  				}
	  		}
  		}
  		return dp[n][target];
    }
};