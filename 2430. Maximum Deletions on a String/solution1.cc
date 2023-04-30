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
		int n = s.size();
    	vector<int> dp(n, 0);
    	dp[n-1] = 1;
    	for(int i = n -2; i >= 0; --i) {
    		// j:= length of removable substr
    		for(int j = 0; j <= (n - i) / 2; ++j) {
    			int i2 = i, j2 = i + j;
    			while(i2 < i + j && s[i2] == s[j2])
    				i2++, j2++;
    			if(i2 == i + j)
    				dp[i] = max(dp[i], dp[i+j] + 1);
    		}
    	}
    	return dp[0];
    }
};