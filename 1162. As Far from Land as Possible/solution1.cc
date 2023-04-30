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
    int maxDistance(vector<vector<int>>& grid) {
		// using DP
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
		int ans = 0;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(grid[i][j] == 1) {
					dp[i][j] = 0;
					continue;
				}
				int dist = INT_MAX - 1;
				if(i > 0)
					dist = min(dist, dp[i-1][j]);
				if(j > 0)
					dist = min(dist, dp[i][j-1]);
				if(dist != INT_MAX) {
                    dp[i][j] = dist + 1;
                }
            }
		}
		for(int i = m-1; i >= 0; --i) {
			for(int j = n - 1; j >= 0; --j) {
				if(grid[i][j] == 1) continue;
				int dist = INT_MAX - 1;
				if(i < m - 1)
					dist = min(dist, dp[i+1][j]);
				if(j < n - 1)
					dist = min(dist, dp[i][j+1]);
                
				if(dist != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dist + 1);
					ans = max(ans, dp[i][j]);
                }
			}
		}
		return ans == 0 || ans == INT_MAX ? -1 : ans;
    }
};