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
    int countAsterisks(string s) {
		int l = -1;
		int ans = 0;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] == '*' && l == -1)
				ans++;
			if(s[i] == '|') 
				l = l == -1 ? i : -1;			
		}
		return ans;
    }
};