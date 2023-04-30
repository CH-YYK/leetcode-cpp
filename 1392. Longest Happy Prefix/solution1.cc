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
    string longestPrefix(string s) {
		// longest prefix which is also prefix
		// use LPS: longest prefix suffix
		int n = s.size();
		vector<int> lps(n, -1);
		int j = -1;
		for(int i = 1; i < n; ++i) {
			while(j > -1 && s[i] != s[j + 1])
				j = lps[j];
			if(s[i] == s[j + 1])
				j++;
			lps[i] = j;
		}
		return s.substr(0, lps[n-1] + 1);
    }
};