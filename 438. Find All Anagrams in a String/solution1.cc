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
    vector<int> findAnagrams(string s, string p) {
		vector<int> freq(26, 0);        
		for(char c : p) 
			freq[c - 'a']++;
		vector<int> window(26, 0);
		int l = 0;
		vector<int> ans;
		for(int r = 0; r < s.size(); ++r) {
			window[s[r] - 'a']++;
			if(r - l + 1 == p.size()) {
				if(freq == window)
					ans.push_back(l);
				window[s[l++] - 'a']--;
			}
		}
		return ans;
    }
};