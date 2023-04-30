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
    int minDeletionSize(vector<string>& strs) {
    	int ans = 0;
    	int n = strs.size();
    	int l = 0;
    	vector<int> removed(n, 0);
    	for(string& w : strs)
    		l = max(l, (int)w.size());
    	for(int i = 0; i < l; ++i) {
    		string w;
    		int ascending = 2;
    		for(int j = 0; j < n; ++j) {
                char c = strs[j][i];
    			if(i == strs[j].size()) continue;
    			if(strs[j][i] == w.back()) continue;
    			if(!w.empty()) {
    				if(c < w.back()) {
                        ans++;
                        break;
                    }
	    		}
	    		w += strs[j][i];
    		}
    	}
    	return ans;
    }
};