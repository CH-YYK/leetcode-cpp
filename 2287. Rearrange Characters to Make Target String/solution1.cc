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
    int rearrangeCharacters(string s, string target) {    	
		vector<int> freq(26, 0), freq2(26, 0);
		for(char c : s)
			freq[c - 'a']++;
		int ans = s.size();
		for(char c : target) 
			freq2[c - 'a']++;
		for(int i = 0; i < 26; ++i)
			if(freq[i] > 0 && freq2[i] > 0)
				ans = min(ans, freq[i] / freq2[i]);
			else if(freq2[i] > 0 && freq[i] == 0)
				return 0;
		return ans;
    }
};