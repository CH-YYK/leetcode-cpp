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
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    	int n = scores.size();
		vector<pair<int,int>> players(n);
		for(int i = 0; i < n; ++i) {
			players[i].first = ages[i];
			players[i].second = scores[i];
		}
		sort(players.begin(), players.end());
		vector<int> dp(n, 0);
		// dp[i]:= max score if choosing players[i]
		// dp[i] = max(dp[j]) + scores[i];
		dp[0] = players[0].second;
		int ans = dp[0];
		for(int i = 1; i < n; ++i) {
			int score = 0;
			dp[i] = players[i].second;
			for(int j = i-1; j >= 0; --j) {
				if(players[j].second <= players[i].second)
					dp[i] = max(dp[i], dp[j] + players[i].second);
			}
			ans = max(ans, dp[i]);
		}
		return ans;
    }
};