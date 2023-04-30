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
#include <iostream>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    int minimumScore(string s, string t) {
		// longest prefix 
		// longest suffix
		// dp1 := longest prefix
		vector<int> dp1(s.size(), -1);
		int j = 0;
		for(int i = 0; i < s.size(); ++i) {
			if(i > 0)
				dp1[i] = dp1[i-1];
			if(j < t.size() && s[i] == t[j]) {
				dp1[i] = j;
				j++;
			}
		}
		// dp2 := longest suffix
		vector<int> dp2(s.size(), t.size());
		int k = t.size() - 1;
		for(int i = s.size() - 1; i >= 0; i--) {
			if(i < s.size() - 1)
				dp2[i] = dp2[i + 1];
			if(k >= 0 && s[i] == t[k]) {
				dp2[i] = k;
				k--;
			}
		}
		int sum = max(dp1[s.size() - 1] + 1, (int)t.size() - dp2[0]);
		for(int i = 0; i < s.size() - 1; ++i) {
			int prefix = dp1[i] + 1;
			int suffix = t.size() - dp2[i + 1];
			int sum = max(sum, prefix + suffix);
		}
		return t.size() - sum;
    }
};