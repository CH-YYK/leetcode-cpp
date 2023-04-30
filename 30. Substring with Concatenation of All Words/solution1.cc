// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	// r - l + 1 = m * len
    	// O(N^2)
    	unordered_map<string, int> cnts;
        for(string& w : words) cnts[w]++;
        int n = s.size();
        int len = words[0].size(), m = words.size();

        vector<int> ans;
        for(int l = 0; l <= n - len * m; ++l) {
        	unordered_map<string, int> newCnts;
            int i = 0;
        	for(; i < m; ++i) {
        		string w = s.substr(l + i * len, len);
        		if(cnts.count(w)) {
        			if(++newCnts[w] > cnts[w])
        				break;
        		} else 
        			break;
        	}
            if(i == words.size())
        	    ans.push_back(l);
        }
        return ans;
    }
};