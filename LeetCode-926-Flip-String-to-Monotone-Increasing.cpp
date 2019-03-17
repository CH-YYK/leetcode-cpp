#include <vector>
#include <string> 
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
    // Brute force solution  O(n^2)
    // divide string into two parts. Count and store the number of ways needed
    // to flip 0->1 left and 1->0 right
public:
    int minFlipsMonoIncr(string S) {
        int ans = INT_MAX;
        for(int k=0; k <= S.size(); k++){
            int ans1 = 0, ans2 = 0;
            for(int i = 0; i < k; i++)
                if(S[i] != '0') ans1++;
            for(int j = k; j < S.size(); j++)
                if(S[j] != '1') ans2++;
            ans = min(ans1 + ans2, ans);
        }
        return ans;
    }
};

class Solution2 {
    // DP version of Solution above, O(n) in time and O(n) in space;
    // create two arrays to cache the 
public:
    int minFlipsMonoIncr(string S) {
        vector<int> left(S.size()+1, 0);
        vector<int> right(S.size()+1, 0);
        for(int i = 0; i < S.size(); i++) {
            left[i+1] += left[i];
            if(S[i] != '0') left[i+1]++;
        }
        for(int j = S.size()-1; j>=0; j--) {
            right[j] += right[j+1];
            if(S[j] != '1') right[j]++;
        }

        int ans = left[0] + right[0];
        for(int k = 1; k <= S.size(); k++)
            ans = min(ans, left[k] + right[k]);
        return ans;
    }
};

class Solution3 {
    // DP version O(n) in time O(2n) in space
    // where dp[i][0] refer to the minimum steps of flip needed when 
    // String[0:i] form a monotune string given ith character is '0'
public:
    int minFlipsMonoIncr(string S) {
        const int n = S.size();
        vector<vector<int>> dp(n+1, vector<int>(2));
        for(int i = 1; i <= n; i++) {
            if(S[i-1] == '0'){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
            } else {
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = min(dp[i-1][1], dp[i-1][0]);
            }
        }
        return min(dp[n][0], dp[n][1]);
    }
};

class Solution4 {
    // DP version O(n) in time O(1) in space
    // updated version for the above one.
    // as dp[i][0] rely on dp[i-1][0] and whether S[i] == 1
    // and dp[i][1] rely on both dp[i-1][0], dp[i-1][1] and whether S[i] == 0
public:
    int minFlipsMonoIncr(string S) {
        const int n = S.size();
        int initial0, initial1;
        initial0 = (int)(S[0] == '1');
        initial1 = (int)(S[0] == '0');

        for(int i = 1; i <= n; i++) {
            initial1 = min(initial0, initial1) + (S[i] == '0');
            initial0 = initial0 + (S[i] == '1');
        }    
        return min(initial0, initial1);
    }
};

int main() {
    string S = "00110";
    int ans = Solution4().minFlipsMonoIncr(S);
    cout << ans << "\n";
    int x = '1' - '1';
    cout << x << "\n";
    return 0;
}