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
    double calculateTax(vector<vector<int>>& brackets, int income) {
		double ans = 0;
		for(int i = 0; i < brackets.size(); ++i) {
			if(income >= brackets[i][0]) {
				if(i == 0) ans += (double)brackets[i][0] * brackets[i][1] / 100;
				else ans += (double)(brackets[i][0] - brackets[i-1][0]) * brackets[i][1] / 100;
			} else {
				if(i == 0) ans += (double)income * brackets[i][1] / 100;
				else ans += (double)(income - brackets[i-1][0]) * brackets[i][1] / 100;
				break;
			}
		}
		return ans;
    }
};