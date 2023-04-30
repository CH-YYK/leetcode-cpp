// Hello,  is a CPP leetcode snippet.

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
    int deleteString(string s) {
		// dp[i]: maximum moves to delete s[i:]
		// dp[i] = max(dp[i+j] + 1) if s[i:i+j] can be removed;
		// the above is O(N^3)
		// Use LPS to reduce it back to O(N^2)
		// 
		int n = s.size();
    	vector<int> dp(n, 1);
    	dp[n-1] = 1;
    	for(int i = n -2; i >= 0; --i) {
    		vector<int> lps = build(s, i, n - 1);
    		// j:= length of rest substr
    		for(int j = 2; j <= n - i; j += 2) {
    			// left j/2 and right j/2 are same
                // lps[i + j - 1] = i + j/2 - 1 
    			// prefix end index
    			int i2 = j / 2 - 1;
    			int j2 = j - 1;
    			if(i2 == lps[j2])
    				dp[i] = max(dp[i], dp[i + i2 + 1] + 1);
    		}
    	}
    	return dp[0];
    }
private:
	vector<int> build(string& s, int start, int end) {
		int j = -1;
		vector<int> lps(end - start + 1, -1);
		for(int i = 1; i <= end - start; ++i) {
			while(j > -1 && s[i + start] != s[j + 1 + start]) 
				j = lps[j];
			if(s[i + start] == s[j + 1 + start])
				j++;
			lps[i] = j;
		}
		return lps;
	}
};