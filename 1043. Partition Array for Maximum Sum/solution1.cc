#include <vector>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // Dynamic programming: O(NK)
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            int maxval = arr[i];
            for (int j = i; j >= max(i + 1 - k, 0); --j) {
                maxval = max(maxval, arr[j]);
                dp[i + 1] = max(dp[i + 1], dp[j] + (i + 1 - j) * maxval);
            }
        }
        return dp[n];
    }
};
