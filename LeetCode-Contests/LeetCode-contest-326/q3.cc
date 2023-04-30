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
    int minimumPartition(string s, int k) {
        // DP
        // dp[i] := min of good partitions of s[:i]
        // dp[i] = min(dp[j] + 1) if eval(s[i:j]) <= k
        // dp[i] = dp[i-1] + 1
        // O(9N) as k<=10^9
    	int n = s.size();
    	int l = 0, kcpy = k;
    	while(kcpy) 
    		kcpy /= 10, l++;    	

    	vector<int> dp(n + 1, n + 1);
    	dp[0] = 0;
    	for(int i = 0; i < n; ++i) {
    		// j - i + 1 <= l
    		// j <= i - l + 1;
    		long num = 0;
    		for(int j = i; j <= min(n - 1, i + l - 1); ++j) {
    			num = 10 * num + s[j] - '0';
    			if(num <= k) 
    				dp[j + 1] = min(dp[j+1], dp[i] + 1);
    		}
    	}
    	return dp[n] > n ? -1 : dp[n];
    }
};