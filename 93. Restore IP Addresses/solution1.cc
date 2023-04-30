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
    vector<string> restoreIpAddresses(string s) {
		// backtracking
		// check if current way of partition valid
		vector<string> path;
    	backtrack(s, 0, path);
    	return vector<string>(res.begin(), res.end());
    }
private:
	unordered_set<string> res;
	void backtrack(string& s, int i, vector<string>& path) {
		if(path.size() == 4) {
			if(i < s.size()) return;
			res.insert(buildIfValid(path));
			return;
		}
		if(i == s.size()) return;
		string element;
		int num = 0;
		for(int j = i; j < min((int)s.size(), i + 3); ++j) {
			element += s[j];
			num = 10 * num + (s[j] - '0');
			if(element[0] == '0' && element.size() > 1)
				continue;
			if(num > 255)
				continue;
			path.push_back(element);
			backtrack(s, j + 1, path);
			path.pop_back();
		}
	}
	string buildIfValid(vector<string>& path) {
		string ans;
		for(string& element : path) {			
			ans += element;
			ans += '.';
		}
		ans.pop_back();
		return ans;
	}
};