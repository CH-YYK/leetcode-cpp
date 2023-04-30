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
    int takeCharacters(string s, int k) {
    	// find longest substring such that
    	// for each char freq[ch] <= allFreq[ch] - k
    	vector<int> allFreq(26, 0), freq(26, 0);
    	for(char c : s)
    		allFreq[c - 'a']++;
        for(int i = 0; i < 3; ++i)
            if(allFreq[i] < k) return -1;
    	int l = 0, maxlen = 0;
    	for(int r = 0; r < s.size(); ++r) {
    		freq[s[r] - 'a']++;

    		while(l < r + 1 && !isEnough(freq, allFreq, k)) {

    			freq[s[l++] - 'a']--;
    		}
    		maxlen = max(r - l + 1, maxlen);
    	}
    	return s.size() - maxlen;
    }
private:
	bool isEnough(vector<int>& freq, vector<int>& allFreq, int k) {
		// freq[ch] <= allFreq[ch] - k
		for(int i = 0; i < 3; ++i)
			if(allFreq[i] - freq[i] < k)
				return false;
		return true;

	}
};