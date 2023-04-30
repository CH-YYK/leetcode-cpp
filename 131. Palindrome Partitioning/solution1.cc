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
    vector<vector<string>> partition(string s) {
    	int n = s.size();
    	isPalindrome = vector<vector<int>>(n, vector<int>(n, 0));
    	for(int i = 0; i < n; ++i)
    		isPalindrome[i][i] = 1;
    	for(int i = 0; i < n - 1; ++i) 
    		if(s[i] == s[i+1])
    			isPalindrome[i][i+1] = 1;

    	for(int l = 3; l <= n; ++l) {
    		for(int i = 0; i < n - l + 1; ++i) {
    			int j = i + l - 1;
    			if(s[i] == s[j])
    				isPalindrome[i][j] = isPalindrome[i+1][j-1];
    		}
    	}
    	vector<string> path;
    	backtrack(s, 0, path);
    	return res;
    }
private:
	vector<vector<int>> isPalindrome;
	vector<vector<string>> res;
	void backtrack(string& s, int i, vector<string>& path) {
		if(i == s.size()) {
			res.push_back(path);
			return;
		}
		string element;
		for(int j = i; j < s.size(); ++j) {
			element += s[j];
			if(isPalindrome[i][j]) {
				path.push_back(element);
				backtrack(s, j + 1, path);
				path.pop_back();
			}
		}
	}
};