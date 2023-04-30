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
    int differenceOfSum(vector<int>& nums) {
		int ans = 0;
		for(int num : nums) {
			ans += num;
			while(num) {
				ans -= num % 10;
				num /= 10;
			}
		}
		return abs(ans);
    }
};