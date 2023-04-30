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
    bool isAlienSorted(vector<string>& words, string order) {
    	// convert alien words to english
    	vector<int> dict(26, 0);
    	for(int i = 0; i < 26; ++i)
    		dict[order[i] - 'a'] = i;
    	bool ans = true;
    	for(int i = 0; i < words.size(); ++i) {
    		for(int j = 0; j < words[i].size(); ++j)
    			words[i][j] = 'a' + dict[words[i][j] - 'a'];
    		if(i > 0)
    			ans &= words[i] >= words[i - 1];    		
    	}
    	return ans;
    }
};