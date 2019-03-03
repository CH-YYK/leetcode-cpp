// The classic knapsack problem with O(nW) runtime and O(nW) space 
// or O(nW) runtime and O(W) space

#include <vector>
#include <string>
#include <algorithms>

using namespace std;

class Solution {
    int knapsack(vector<int>& values, vector<int>& weights, int n, int W) {
        // O(nW) in time and O(nW) in space 
        // (Top-down here but bottom-up will also be okay

        // Define the matrix of DP[i][j] which refer to max values formed by
        // items prior to ith (0, 1, 2, 3, ... i-1) where total weights under j
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= W; j++) {

                // skip [i-1]th item 
                dp[i][j] = dp[i-1][j];
                if(weights[i-1] <= j){
                    
                    // include [i-1]th item and pick the max value
                    dp[i][j] = max(dp[i-1][j], values[i-1]+dp[i-1][j-weights[i-1]]);
                }
            }
        }
        return dp[n][W];
    }
}


class Solution2 {
    int knapsack(vector<int>& values, vector<int>& weights, int n, int W) {
        // O(nW) in time and O(W) in space
        // Define the vector of DP[j] where the total weights are under j
        vector<int> dp(W+1, 0);
        for(int i=1; i <= n; i++) {
            for(int j=W; j>=weights[i]; j--){
                dp[j] = max(dp[j], values[i-1] + dp[j-weights[i-1]]);
            }
        }
        // bottom-up only, since the transmission operation started from top to down.
        // as the "bottom" values are unknown
        return dp[W];
    }
}