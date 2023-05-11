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
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    	// Using DP
        // dp[i][j]:= maximum connecting lines for nums1[:i] and nums2[:j]
        // dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        // if nums1[i] == nums2[j]: dp[i][j] = dp[i-1][j-1] + 1
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));

        for(int i = 0; i < m; ++i) 
        	for(int j = 0; j < n; ++j) {
        		dp[i + 1][j + 1] = max(dp[i+1][j], dp[i][j+1]);
        		if(nums1[i] == nums2[j])
        			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
        	}
        return dp[m][n];
    }
};