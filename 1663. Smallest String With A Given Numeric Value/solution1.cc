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
    string getSmallestString(int n, int k) {
		string ans(n, 'a');
        k -= n;
		while(k) {
			int diff = min('z' - ans[n-1], k);
			k -= diff;			
			ans[n-1] += diff;
			n--;
		}
		return ans;
    }
};