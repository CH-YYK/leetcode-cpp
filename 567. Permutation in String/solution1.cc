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
    bool checkInclusion(string s1, string s2) {
		vector<int> freq(26, 0);
		for(char c : s1)
			freq[c - 'a']++;
		int l = 0;
		vector<int> freq2(26, 0);
		for(int r = 0; r < s2.size(); ++r) {
			freq2[s2[r] - 'a']++;
			if(r - l + 1 < s1.size()) continue;
			if(freq == freq2) return true;
			freq2[s2[l++] - 'a']--;
		}
		return false;
    }
};