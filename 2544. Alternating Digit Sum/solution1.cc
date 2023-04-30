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
    int alternateDigitSum(int n) {
		long m = 1;
		while(m * 10 <= n) 
			m *= 10;
		int ans = 0, sign = 1;
		while(m >= 1) {
			ans += sign * (n / m);
			sign *= -1;
			n %= m;
			m /= 10;
		}
		return ans;
    }
};