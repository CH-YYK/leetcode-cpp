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

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        // palindrome subsequence, s.size() - k
        // Dynamic programming
        // 1. maybe we need three dimensions to track the state, i, j, k
        // 		where i and j are index, and dp[i][j][k] := can have a palindrome
        // 		after removing at most k
        //   - the complexity become O(N^3) which is not good.
        // 2. "at most" is not "exactly", which means that we really don't need to 
        // 	   steadly follow k. If we know the longest palindrome subsequence, 
        // 	   we can check whether its valid by s.size() - length(palindrome subseq) <= k
        //     dp[i][j]:= length of the longest subseq in substring(i,j);
    	// 	 - complexity O(N^2), which looks more acceptable.
        // dp[i][j]: longest palindrome subsequence in s(i,j)
        // dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + 2, dp[i+1][j])
        int n = s.size();
        // range based dp
        // dp[i][j]: length of the longest parlindrome subseq
        vector<vector<int>> dp(n, vector<int>(n, 1));

        // length 1
        for(int i = 0; i < n; ++i)
        	dp[i][i] = 1;
        // length 2
        for(int i = 0; i < n - 1; ++i) {
        	if(s[i] == s[i + 1])
        		dp[i][i + 1] = 2;
        	else 1;
        }
        // length > 2
        for(int l = 3; l <= n; ++l) {
        	for(int i = 0; i < n - l + 1; ++i) {        			
        		int j = i + l - 1;
        		if(s[i] == s[j])
        			dp[i][j] = max(dp[i][j], dp[i+1][j-1] + 2);
        		dp[i][j] = max(dp[i][j], dp[i+1][j]);
        		dp[i][j] = max(dp[i][j], dp[i][j-1]);
        	}
        }
        return n - dp[0][n-1] <= k;
    }
};