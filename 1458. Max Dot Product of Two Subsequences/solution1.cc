#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // sub1 from nums1 * sub2 from nums2
        // using dp
        // dp[i][j] -> max dot product from a1[:i] * a2[:j]
        // dp[i+1][j] = max(dp[i][k] + a1[i] * a2[k] for k <= j)
        // dp[i][j+1] = max(dp[k][j] + a1[k] * a2[j] for k <= i)
        // dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j], dp[i][j] + a1[i] * a2[j])
        // 
        // dp[0][0] = 0, dp[i][0] = 0, dp[0][j] = 0,dp[1][1] = a1[0] * a2[0]
        // 
        // the DP part cannot cover the case that there must be 1 pair from two 
        // arrays to compute the dot product.
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        } 
        int m = nums1.size(), n = nums2.size();
        memo = vector<vector<int>>(m, vector<int>(n, INT_MIN));
        return dfs(0, 0, nums1, nums2);
    }
private:
    vector<vector<int>> memo;
    int dfs(int i, int j, vector<int>& a1, vector<int>& a2) {
        // top-down dp, dfs(...) -> max dot product for a1[i:] & a2[j:]
        if(i == a1.size() || j == a2.size())
            return 0;
        if(memo[i][j] > INT_MIN)
            return memo[i][j];
        int curr = a1[i] * a2[j];
        // use curr or not
        int use_curr = curr + dfs(i + 1, j + 1, a1, a2);
        memo[i][j] = max(use_curr, max(dfs(i + 1, j, a1, a2), dfs(i, j + 1, a1, a2)));
        return memo[i][j];
    }
};