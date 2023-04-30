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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // save words in dict
        // for each word, break it to see if it's a concatenation of others
        // time complexity: O(n * l^2) -> 10^7
  		unordered_set<string> s;
  		for(string& w : words)
  			s.insert(w);
		vector<string> ans;
		for(string& w : words) {
			int l = w.size();
			// dp[i]:= whether w[:i] is concatenated word
			// dp[i] = any(dp[j] && (w[j:i] in words))
			s.erase(w);
			vector<int> dp(l + 1, 0);
			dp[0] = 1;
			for(int i = 0; i < l; ++i) {
				if(dp[i] == 0) continue;
				string word;
				for(int j = i; j < l; ++j) {
					word += w[j];
					if(s.count(word))
						dp[j + 1] = dp[i];
				}
			}
			if(dp[l])
				ans.push_back(w);
			s.insert(w);
		}
		return ans;
    }
};