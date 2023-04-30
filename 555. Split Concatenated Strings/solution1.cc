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
    string splitLoopedString(vector<string>& strs) {
		// start from lexically largest str
		// rule: 
		//  1. cutting can happnd in every word, say w
		// 		we should let the larger one in w[:i], reverse(w[:i])
		// 		as a new lead.
		// 	2. total length of strs is under 1000, so we can rebuild the whole string evry iteration
		//	 	-> 1000 * 1000 full iterations

    	string s, res = "a";
    	for(string w : strs) {
    		string rw = w;
    		reverse(rw.begin(), rw.end());
    		s += max(rw, w);
    	}
    	for(int i = 0, len = 0; i < strs.size(); len += strs[i++].size()) {
    		string w = strs[i], rw = strs[i];
    		string left = s.substr(0, len);
    		string right = s.substr(len + w.size());
    		reverse(rw.begin(), rw.end());
    		for(int j = 0; j < w.size(); ++j) {
    			res = max(res, w.substr(j) + right + left + w.substr(0, j));
    			res = max(res, rw.substr(j) + right + left + rw.substr(0, j));
    		}
    	}
    	return res;
    }
};