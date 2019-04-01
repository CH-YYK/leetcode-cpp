#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
    // DP solution, O(N^2) in time, and O(N^2) in space
    // Set a matrix, dp, that is n * n where dp[i][j] indicate the length of 
    // fibonacci sequence from A[i] - A[j], minimum is 2 (invalid)

    // for every k > j, test whether A[k] - A[j] in A and A[i] < A[j] 
    //          if True: A[j][k] = A[i][j] + 1
    //          if False: continue
    // 

    // optim: hashmap to help quickly search elements in array
    //        "break" instead of "continue" when A[k]-A[j] >= A[i], because array is increasing 
    //        and every subsequent k will make A[k] - A[j] >= A[i].
public:
    int lenLongestFibSubseq(vector<int>& A) {
        const int n = A.size();
        unordered_map<int, int> hashmap;
        for(int i = 0; i<n; i++) hashmap[A[i]] = i;
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 2));
        for(int j = 0; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                int a_i = A[k] - A[j];
                if(a_i >= A[j]) break;
                if(!hashmap.count(a_i)) continue;
                dp[j][k] = dp[hashmap[a_i]][j] + 1;
                ans = max(ans, dp[j][k]);
            }
        }
        return ans;
    }
};