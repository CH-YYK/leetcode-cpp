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
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
		function<bool(vector<int>& left, vector<int>& right)> sorter = 
		[&](vector<int>& lhs, vector<int>& rhs) {
			return lhs[k] > rhs[k];
		};
		sort(score.begin(), score.end(), sorter);
		return score;
    }
};