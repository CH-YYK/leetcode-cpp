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
    int minimumMoves(string s) {
        // greedy
        int i = 0;
        int ans = 0;
        while(i < s.size()) {
        	if(s[i] != 'O') {
        		i += 3;
        		ans++;
        	}else i++;
        }
        return ans;
    }
};