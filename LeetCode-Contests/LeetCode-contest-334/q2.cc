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
    vector<int> divisibilityArray(string word, int m) {
		// modulo
		// num[:2] = nums[0] * 10 + nums[1]
    	vector<int> ans(word.size(), 0);
    	long num = 0;
    	for(int i = 0; i < word.size(); ++i) {
    		num = (10 * num + (word[i] - '0') % m) % m;
    		if(num == 0)
    			ans[i] = 1;
    	}
    	return ans;
    }
};