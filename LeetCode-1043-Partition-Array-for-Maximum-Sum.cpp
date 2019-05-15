#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N, 0);
        int currmax = 0;
        for(int i = 0; i < N; i++) {
            if(i < K) {
                currmax = max(currmax, A[i]);
                dp[i] = (i+1) * currmax;
            }else{
                currmax = 0;
                for(int k = 1; k < K; k++) {
                    currmax = max(currmax, A[i-k+1]);
                    dp[i] = max(dp[i], dp[i-k] + currmax * k);
                }
            }
        }
        return dp.back();
    }
};