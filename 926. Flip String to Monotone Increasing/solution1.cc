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
    int minFlipsMonoIncr(string s) {
		int total = 0, cumsum = 0;
		for(char c : s)
			total += c - '0';
		int n = s.size();
		int ans = n - total;
		for(int i = 0; i < n; ++i) {
			cumsum += s[i] - '0';
			ans = min(ans, cumsum + (n - i - 1 - (total - cumsum)));
		}
		return ans;
    }
};