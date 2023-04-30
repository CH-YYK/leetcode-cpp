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
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        // digits.size() <= 9 seems a fair size, using backtrack
        // O(9!) -> TLE
        backtrack(digits, n, 0);
        return ans;
    }
private:
	long ans = 0;
	void backtrack(vector<string> digits, int& n, long num) {
		if(num > 0 && num <= n)
			ans++;
		if(num > n) return;
		for(string digit : digits) {
			backtrack(digits, n, num * 10 + digit[0] - '0');
		}
	}
};